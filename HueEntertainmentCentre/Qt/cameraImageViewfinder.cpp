#include "cameraImageViewfinder.h"

CameraImageViewfinder::CameraImageViewfinder(QSize scale)
{
	_scale = scale;
}

bool CameraImageViewfinder::present(const QVideoFrame &frame)
{
	QVideoFrame duplicate(frame);
	duplicate.map(QAbstractPlanarVideoBuffer::ReadOnly);

	QImage image(duplicate.bits(), duplicate.width(), duplicate.height(), duplicate.bytesPerLine(), QImage::Format::Format_RGB32);

	duplicate.unmap();

	emit imageCaptured(image.scaled(_scale));

	return true;
}

QList<QVideoFrame::PixelFormat> CameraImageViewfinder::supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const
{
	QList<QVideoFrame::PixelFormat> list;

	if (handleType == QAbstractVideoBuffer::NoHandle)
	{
		list.append(QVideoFrame::Format_RGB32);
	}

	return list;
}
