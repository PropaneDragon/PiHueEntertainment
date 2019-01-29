#include <QMultimedia>
#include <QImage>
#include <QPixmap>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraImageCapture>
#include <QApplication>
#include <QDateTime>

#include "cameraCapture.h"

CameraCapture::CameraCapture()
{
	_viewfinder = new CameraImageViewfinder(_expectedResolution);

	connect(_viewfinder, &CameraImageViewfinder::imageCaptured, this, &CameraCapture::imageCaptured);
}

void CameraCapture::connectToDefaultCamera()
{
	if (_camera) {
		disconnectCamera();
	}

	auto availableCameras = QCameraInfo::availableCameras().count();

 	auto cameraInfo = QCameraInfo::defaultCamera();
	if (!cameraInfo.isNull() && _viewfinder) {
 		_camera = new QCamera(cameraInfo);
		_camera->setCaptureMode(QCamera::CaptureMode::CaptureViewfinder);
		_camera->setViewfinder(_viewfinder);
		_camera->viewfinderSettings().setResolution(QSize(_expectedResolution.width(), _expectedResolution.height()));
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
	_camera->disconnect();
	_camera->deleteLater();
	_camera = nullptr;
}

bool CameraCapture::connectedToCamera()
{
	return _camera;
}

bool CameraCapture::hasNewImage(const QDateTime &since)
{
	return _lastImageUpdate >= since;
}

QImage CameraCapture::lastImage()
{
	return _lastImage;
}

QSize CameraCapture::resolution()
{
	return _expectedResolution;
}

void CameraCapture::imageCaptured(QImage image)
{
	if (!image.isNull() && image.size() == _expectedResolution) {
		_lastImage = image;
		_lastImageUpdate = QDateTime::currentDateTime();
	}
}
