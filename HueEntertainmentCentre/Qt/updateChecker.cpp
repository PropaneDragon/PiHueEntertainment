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

	return !availableVersion.empty() && !currentVersion.empty() && availableVersion != currentVersion;
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

std::string UpdateChecker::getVersionFromFile()
{
	auto versionFile = getVersionFile();
	if (!versionFile.empty()) {

		const std::regex versionFinder("::getVersionFromApplication.*?(?:\\n|\\r|.)*?return *\"(([0-9]\\.){3}[0-9])\"");
		std::smatch match;

		if (std::regex_search(versionFile, match, versionFinder) && match.size() >= 2) {
			auto matchedVersion = match[1];
			return matchedVersion.str();
		}
 	}

	return "";
}

std::string UpdateChecker::getVersionFromApplication() const
{
	return "0.2.0.0";
}
