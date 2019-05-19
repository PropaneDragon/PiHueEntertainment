#include <chrono>

#include <QTimer>

#include "performanceItemModel.h"
#include "timingsDialog.h"

TimingsDialog::TimingsDialog(QWidget *parent, Qt::WindowFlags flags) : QDialog(parent, flags)
{
	setupUi(this);

	update();

	_updateTimer = new QTimer(this);
	_updateTimer->setInterval(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::seconds(10)).count());
	/*_updateTimer->start();

	connect(_updateTimer, &QTimer::timeout, this, &TimingsDialog::update);*/
}

void TimingsDialog::update()
{
	treeView->setModel(new PerformanceItemModel(this));
}