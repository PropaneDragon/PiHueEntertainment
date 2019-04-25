#include <QMultimedia>
#include <QImage>
#include <QPixmap>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraImageCapture>
#include <QApplication>
#include <QDateTime>

#include "cameraCapture.h"

CameraCapture::CameraCapture(QObject *parent) : QObject(parent)
{
	_viewfinder = new CameraImageViewfinder();

	connect(_viewfinder, &CameraImageViewfinder::imageCaptured, this, &CameraCapture::imageCaptured);
}

CameraCapture::~CameraCapture()
{
}

void CameraCapture::connectToDefaultCamera()
{
	disconnectCamera();

	_safelyDisconnected = false;

	auto availableCameras = QCameraInfo::availableCameras();

 	auto cameraInfo = QCameraInfo::defaultCamera();
	if (!cameraInfo.isNull() && _viewfinder) {
 		_camera = new QCamera(cameraInfo);
		_camera->setCaptureMode(QCamera::CaptureMode::CaptureViewfinder);
		_camera->setViewfinder(_viewfinder);
		_camera->viewfinderSettings().setResolution(_viewfinder->resolution());
		_camera->exposure()->setManualAperture(16);
		_camera->exposure()->setManualIsoSensitivity(100);
		_camera->exposure()->setManualShutterSpeed(0.001);
		_camera->exposure()->setMeteringMode(QCameraExposure::MeteringMode::MeteringSpot);
		_camera->exposure()->setExposureMode(QCameraExposure::ExposureMode::ExposureManual);
		_camera->exposure()->setExposureCompensation(0);
		_camera->exposure()->setSpotMeteringPoint(QPointF(-1, -1));
		_camera->imageProcessing()->setManualWhiteBalance(5400);
		_camera->imageProcessing()->setBrightness(0);
		_camera->start();
		_camera->searchAndLock();
	}
}

void CameraCapture::disconnectCamera()
{
	_safelyDisconnected = true;

	if (_camera) {
		_camera->unlock();
		_camera->disconnect();
		_camera->unload();
		_camera->deleteLater();
		_camera = nullptr;
	}
}

bool CameraCapture::connectedToCamera() const
{
	return _camera && _camera->error() == QCamera::Error::NoError && _camera->availability() == QMultimedia::AvailabilityStatus::Available;
}

bool CameraCapture::wasSafelyDisconnected() const
{
	return _safelyDisconnected;
}

bool CameraCapture::hasNewImage(const QDateTime &since) const
{
	return _lastImageUpdate >= since;
}

QImage CameraCapture::lastImage() const
{
	return _lastImage;
}

QSize CameraCapture::viewfinderResolution() const
{
	if (_viewfinder) {
		return _viewfinder->resolution();
	}

	return QSize(50, 50);
}

void CameraCapture::imageCaptured(QImage image)
{
	if (!image.isNull() && image.size() == viewfinderResolution()) {
		_lastImage = image;
		_lastImageUpdate = QDateTime::currentDateTime();
	}
}
