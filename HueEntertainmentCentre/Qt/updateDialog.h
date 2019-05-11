#pragma once

#include <QDialog>

#include "ui_updateDialog.h"

class QTimer;
class QThreadLambda;
class UpdateDialog : public QDialog, public Ui::UpdateDialog
{
	Q_OBJECT;

public:
	UpdateDialog(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

	void checkForUpdateAndShow();

public slots:
	void accept() override;

private:
	bool _updateAvailable = false;

	QTimer *_updatedCheckTimer = nullptr;
	QThreadLambda *_updateCheckThread = nullptr;
};