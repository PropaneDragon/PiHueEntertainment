#pragma once

#include <QMainWindow>
#include <QDateTime>

#include "../Hue/abstractBridgeConnectionNotifier.h"

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

	void connectToBridge();
	void onBridgeConnected(std::shared_ptr<huestream::IHueStream> stream, std::shared_ptr<huestream::Bridge> bridge) override;
	void onBridgeDisconnected(std::shared_ptr<huestream::Bridge> bridge) override;
	void onBridgeConnectionFailed() override;
	void connectToGroup(std::shared_ptr<huestream::Group> group);
	void processImage(const QImage &image);

protected slots:
	void captureTimerUpdated();

private:
	bool _connected = false;

	int _targetFramerate = 10;

	QDateTime _lastRequestTime = QDateTime::currentDateTime();

	std::shared_ptr<huestream::IHueStream> _stream = nullptr;

	CameraCapture *_capture = nullptr;
	QTimer *_captureTimer = nullptr;
};