#pragma once

#include <QAbstractVideoSurface>
#include <QPixmap>

class CameraImageViewfinder : public QAbstractVideoSurface
{
	Q_OBJECT;

public:
	CameraImageViewfinder();

	bool present(const QVideoFrame &frame) override;

	QSize resolution() const;

	QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const override;

signals:
	void imageCaptured(QImage);
};