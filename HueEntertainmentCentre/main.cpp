#include <iostream>

#include <QApplication>
#include <QTimer>

#include "Qt/startWindow.h"

int main(int argc, char *argv[])
{
	auto result = 0;

	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication application(argc, argv);

	StartWindow startWindow;
	startWindow.show();

	result = application.exec();

    return result;
}