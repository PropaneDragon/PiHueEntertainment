#include <QTimer>
#include <QLabel>

#include "../Hue/bridgeConnectionHandler.h"
#include "../Hue/bridgeConnectionNotifier.h"

#include "startWindow.h"

StartWindow::StartWindow(QWidget *parent, Qt::WindowFlags flags)
{
	setFixedSize(QSize(350, 350));

	_previewImage = new QLabel(this);
	_previewImage->setScaledContents(true);

	setCentralWidget(_previewImage);
}

void StartWindow::showEvent(QShowEvent *event)
{
	auto connectionHandler = new BridgeConnectionHandler("Pi Camera Mirror");
	auto connectionNotifier = std::shared_ptr<BridgeConnectionNotifier>(new BridgeConnectionNotifier());

	connectionHandler->setNotifier(connectionNotifier);
	connectionNotifier->setUpdateImage(_previewImage);
}
