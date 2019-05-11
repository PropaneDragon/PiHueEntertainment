#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QApplication>
#include <QDateTime>
#include <QFile>

#include <regex>

#include "updateChecker.h"

UpdateChecker* UpdateChecker::_instance = nullptr;

UpdateChecker* UpdateChecker::Instance()
{
	if (!_instance) {
		_instance = new UpdateChecker();
	}

	return _instance;
}

UpdateChecker::UpdateChecker()
{
	_accessManager = new QNetworkAccessManager();
	_accessManager->setNetworkAccessible(QNetworkAccessManager::NetworkAccessibility::Accessible);
}

bool UpdateChecker::isUpdateAvailable()
{
	auto availableVersion = getVersionFromFile();
	auto currentVersion = getVersionFromApplication();

	return availableVersion.valid() && currentVersion.valid() && availableVersion > currentVersion;
}

bool UpdateChecker::isDownloading() const
{
	return _isDownloading;
}

std::string UpdateChecker::getVersionFile()
{
	auto startTime = QDateTime::currentDateTime();
	std::string response = "";

	_isDownloading = true;

	QNetworkRequest request;
	request.setUrl(QUrl(QString::fromStdString(_versionUrl)));

	auto reply = _accessManager->get(request);
	if (reply) {

		while (reply->isRunning() && !reply->isFinished() && startTime.addSecs(_timeoutSeconds) > QDateTime::currentDateTime()) {
			QApplication::processEvents(QEventLoop::ProcessEventsFlag::ExcludeUserInputEvents);
		}

		if (!reply->error()) {
			response = reply->readAll().data();
		}

		reply->deleteLater();
	}

	_isDownloading = false;

	return response;
}

Version UpdateChecker::getVersionFromFile()
{
	auto versionFile = getVersionFile();
	if (!versionFile.empty()) {

		const std::regex versionFinder("return *Version\\(([0-9]), *([0-9]), *([0-9]), *([0-9])", std::regex_constants::syntax_option_type::extended); // return *\"(([0-9]\\.){3}[0-9])\"
		std::smatch match;

		if (std::regex_search(versionFile, match, versionFinder) && match.size() >= 5) {
			auto matchedVersion = match[1].str() + "." + match[2].str() + "." + match[3].str() + "." + match[4].str();
			return Version(matchedVersion);
		}
 	}

	return Version();
}

Version UpdateChecker::getVersionFromApplication() const
{
	return Version(0, 3, 0, 0);
}
