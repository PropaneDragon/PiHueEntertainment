#pragma once

#include <QDialog>

#include "ui_hubConnectDialog.h"

class QThreadLambda;
class HubConnectDialog : public QDialog, public Ui::HubConnectDialog
{
	Q_OBJECT;

public:
	HubConnectDialog(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

	void showEvent(QShowEvent *event) override;
	void connectToBridgeAsync();
	void connectToBridge();

protected slots:
	void checkBridgeConnection();

private:
	bool _connected = false;

	QThreadLambda *_connectThread = nullptr;
};