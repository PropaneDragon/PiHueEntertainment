#include <QMessageBox>

#include "huestream/HueStream.h"

#include "../Hue/bridgeConnectionHandlerInstance.h"

#include "qThreadLambda.h"
#include "hueBridgeListModel.h"
#include "hubConnectDialog.h"

HubConnectDialog::HubConnectDialog(QWidget * parent, Qt::WindowFlags flags) : QDialog(parent, flags)
{
	setupUi(this);
}

void HubConnectDialog::showEvent(QShowEvent *event)
{
	connectToBridgeAsync();
}

void HubConnectDialog::connectToBridgeAsync()
{
	if (!_connectThread && !_connected) {
		_connectThread = new QThreadLambda(this);
		_connectThread->setFunction([this]() {
			connectToBridge();
		});

		connect(_connectThread, &QThread::finished, this, &HubConnectDialog::checkBridgeConnection);
		_connectThread->start();
	}
	else {
		checkBridgeConnection();
	}
}

void HubConnectDialog::connectToBridge()
{
	_connected = BridgeConnectionHandlerInstance::Instance()->tryConnect();
}

void HubConnectDialog::checkBridgeConnection()
{
	_connectThread->deleteLater();
	_connectThread = nullptr;

	if (_connected) {
		BridgeConnectionHandlerInstance::Instance()->checkConnectionAndNotify();
		accept();
	}
	else {
		auto button = QMessageBox::critical(this, "Couldn't connect to hub", "Unfortunately, we couldn't connect to the hub. Ensure the hub is on the same network, and that you press the circular button in the middle of the hub if this is your first time connecting.", QMessageBox::StandardButton::Retry | QMessageBox::StandardButton::Cancel);
		if (button == QMessageBox::StandardButton::Retry) {
			connectToBridgeAsync();
		}
	}
}