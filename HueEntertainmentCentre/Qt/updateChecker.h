#pragma once

#include <string>

class QNetworkAccessManager;
class QNetworkReply;
class UpdateChecker
{
public:
	static UpdateChecker* Instance();

	UpdateChecker();

	bool isUpdateAvailable();
	bool isDownloading() const;

private:
	static UpdateChecker *_instance;

	std::string getVersionFile();
	std::string getVersionFromFile();
	std::string getVersionFromApplication() const;

	bool _isDownloading = false;
	int _timeoutSeconds = 5;

	const std::string _baseUrl = "https://raw.githubusercontent.com/PropaneDragon/PiHueEntertainment/master";
	const std::string _versionUrl = _baseUrl + "/HueEntertainmentCentre/Qt/updateChecker.cpp";

	QNetworkAccessManager *_accessManager = nullptr;
};