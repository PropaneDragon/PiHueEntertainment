#pragma once

#include <QDialog>

#include "ui_timingsDialog.h"

class QTimer;
class TimingsDialog : public QDialog, public Ui::TimingsDialog
{
public:
	TimingsDialog(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

private:
	void update();

	QTimer *_updateTimer = nullptr;
};