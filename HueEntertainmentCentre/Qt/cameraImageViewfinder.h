#pragma once

#include <QAbstractVideoSurface>
#include <QPixmap>

class CameraImageViewfinder : public QAbstractVideoSurface
{
	Q_OBJECT;

public:
	CameraImageViewfinder(QSize scale);

	bool present(const QVideoFrame &frame) override;

	QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const override;

signals:
	void imageCaptured(QImage);

private:
	QSize _scale = QSize(10, 10);
};