#include <QSettings>

#include "cameraImageViewfinder.h"

CameraImageViewfinder::CameraImageViewfinder()
{
}

bool CameraImageViewfinder::present(const QVideoFrame &frame)
{
	QVideoFrame duplicate(frame);
	duplicate.map(QAbstractPlanarVideoBuffer::ReadOnly);

	QImage image(duplicate.bits(), duplicate.width(), duplicate.height(), duplicate.bytesPerLine(), QImage::Format::Format_RGB32);

	duplicate.unmap();

	emit imageCaptured(image.scaled(resolution()));

	return true;
}

QSize CameraImageViewfinder::resolution() const
{
	QSettings settings;

	auto resolution = settings.value("camera/resolution", 10).toInt();
	return QSize(resolution, resolution);
}

QList<QVideoFrame::PixelFormat> CameraImageViewfinder::supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const
{
	QList<QVideoFrame::PixelFormat> list;

	if (handleType == QAbstractVideoBuffer::NoHandle) {
		list.append(QVideoFrame::Format_RGB32);
	}

	return list;
}
