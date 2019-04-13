#include <iostream>

#include <QApplication>
#include <QTimer>

#include "Hue/bridgeConnectionHandlerInstance.h"

#include "Qt/startWindow.h"
#include "Qt/mainWindow.h"

int main(int argc, char *argv[])
{
	auto result = 0;

	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication application(argc, argv);

	auto startWindow = std::shared_ptr<MainWindow>(new MainWindow());

	BridgeConnectionHandlerInstance::Instance()->setNotifier(startWindow);

	startWindow->show();

	result = application.exec();

    return result;
}