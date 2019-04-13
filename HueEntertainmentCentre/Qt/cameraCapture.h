#pragma once

#include <QImage>
#include <QCamera>
#include <QDateTime>

#include "cameraImageViewfinder.h"

class CameraCapture : public QObject
{
	Q_OBJECT;

public:
	CameraCapture(QObject *parent = nullptr);
	~CameraCapture();

	void connectToDefaultCamera();
	void disconnectCamera();

	bool connectedToCamera();
	bool hasNewImage(const QDateTime &since);

	QImage lastImage();
	QSize resolution();

public slots:
	void imageCaptured(QImage image);

private:
	QDateTime _lastImageUpdate = QDateTime::currentDateTime().addYears(-1);
	QImage _lastImage;
	QSize _expectedResolution = QSize(50, 50);

	QCamera *_camera = nullptr;
	CameraImageViewfinder *_viewfinder = nullptr;
};