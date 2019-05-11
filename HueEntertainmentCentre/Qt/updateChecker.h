#pragma once

#include <string>

#include "version.h"

class QNetworkAccessManager;
class QNetworkReply;
class UpdateChecker
{
public:
	static UpdateChecker* Instance();

	UpdateChecker();

	bool isUpdateAvailable();
	bool isDownloading() const;

	std::string getUpdateUrl() const;

private:
	static UpdateChecker *_instance;

	std::string getVersionFile();
	Version getVersionFromFile();
	Version getVersionFromApplication() const;

	bool _isDownloading = false;
	int _timeoutSeconds = 5;

	const std::string _updateUrl = "https://github.com/PropaneDragon/PiHueEntertainment/releases";
	const std::string _baseUrl = "https://raw.githubusercontent.com/PropaneDragon/PiHueEntertainment/master";
	const std::string _versionUrl = _baseUrl + "/HueEntertainmentCentre/Qt/updateChecker.cpp";

	QNetworkAccessManager *_accessManager = nullptr;
};