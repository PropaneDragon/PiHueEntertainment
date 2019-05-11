#pragma once

#include <QMainWindow>
#include <QDateTime>

#include "Hue/abstractBridgeConnectionNotifier.h"
#include "Hue/colourArea.h"

#include "ui_mainWindow.h"

namespace huestream
{
	class Bridge;
	class IHueStream;
	class Group;
}

class CameraCapture;
class QTimer;

class MainWindow : public QMainWindow, public AbstractBridgeConnectionNotifier, public Ui::MainWindow
{
	Q_OBJECT;

public:
	MainWindow(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

	void showEvent(QShowEvent *event) override;
	void closeEvent(QCloseEvent *event) override;

	void onBridgeConnected(std::shared_ptr<huestream::IHueStream> stream, std::shared_ptr<huestream::Bridge> bridge) override;
	void onBridgeDisconnected(std::shared_ptr<huestream::Bridge> bridge) override;
	void onBridgeConnectionFailed() override;
	void connectToGroup(std::shared_ptr<huestream::Group> group);
	void processImage(const QImage &image);

protected slots:
	void captureTimerUpdated();
	void connectToNewBridge();
	void connectToNewCamera();
	void connectToBridge();
	void connectToCamera();
	void disconnectFromBridge();
	void disconnectFromCamera();
	void changeImageUpdatePreference(bool canUpdate);
	void rotateImageClockwise();
	void rotateImageAntiClockwise();
	void flipImageHorizontal(bool flip);
	void flipImageVertical(bool flip);
	void showOptions();
	void showPerformance();

protected:
	void rotateImage(int degrees);

private:
	void loadSettings();

	bool _connected = false;
	bool _imageAllowedToUpdate = true;
	bool _imageFlippedHorizontally = false;
	bool _imageFlippedVertically = false;

	int _imageRotation = 0;
	int _maximumBrightness = 100;
	int _minimumBrightness = 0;

	QDateTime _lastRequestTime = QDateTime::currentDateTime();

	std::shared_ptr<huestream::IHueStream> _stream = nullptr;
	std::vector<ColourArea> _areas;

	CameraCapture *_capture = nullptr;
	QTimer *_captureTimer = nullptr;
};