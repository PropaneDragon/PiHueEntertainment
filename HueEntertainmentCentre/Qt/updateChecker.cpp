#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QApplication>
#include <QDateTime>

#include <thread>

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
	request.setUrl(QString::fromStdString(_versionUrl));

	auto reply = _accessManager->get(request);
	if (reply) {

		while (reply->isRunning() && !reply->isFinished() && startTime.addSecs(_timeoutSeconds) > QDateTime::currentDateTime()) {
			QApplication::processEvents(QEventLoop::ProcessEventsFlag::ExcludeUserInputEvents);
		}

		if (!reply->error()) {
			response = reply->readAll().toStdString();
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
		return versionFile;
	}

	return "";
}

std::string UpdateChecker::getVersionFromApplication() const
{
	return "0.2.0.0";
}
