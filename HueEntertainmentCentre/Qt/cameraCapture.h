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

	bool connectedToCamera() const;
	bool hasNewImage(const QDateTime &since) const;
	bool wasSafelyDisconnected() const;

	QImage lastImage() const;
	QSize viewfinderResolution() const;

public slots:
	void imageCaptured(QImage image);

private:
	bool _safelyDisconnected = false;

	QDateTime _lastImageUpdate = QDateTime::currentDateTime().addYears(-1);
	QImage _lastImage;

	QCamera *_camera = nullptr;
	CameraImageViewfinder *_viewfinder = nullptr;
};