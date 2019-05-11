#include <QTimer>
#include <QDesktopServices>
#include <QUrl>

#include "updateChecker.h"
#include "qThreadLambda.h"
#include "updateDialog.h"

UpdateDialog::UpdateDialog(QWidget *parent, Qt::WindowFlags flags) : QDialog(parent, flags)
{
	setupUi(this);

	buttons_bottom->addButton("Update", QDialogButtonBox::ButtonRole::AcceptRole);
}

void UpdateDialog::checkForUpdateAndShow()
{
	if (!_updateCheckThread) {
		_updateCheckThread = new QThreadLambda([this]() {
			_updateAvailable = UpdateChecker::Instance()->isUpdateAvailable();
		}, this);
	}

	if (!_updatedCheckTimer) {
		_updatedCheckTimer = new QTimer(this);
		_updatedCheckTimer->setSingleShot(false);

		connect(_updatedCheckTimer, &QTimer::timeout, [this]() {
			
			if (_updateCheckThread->isFinished()) {				
				_updatedCheckTimer->stop();

				if (_updateAvailable) {
					show();
				}
			}
		});
	}

	_updateCheckThread->terminate();
	_updateCheckThread->start();

	_updatedCheckTimer->stop();
	_updatedCheckTimer->setInterval(10);
	_updatedCheckTimer->start();
}

void UpdateDialog::accept()
{
	QDialog::accept();
	QDesktopServices::openUrl(QUrl(QString::fromStdString(UpdateChecker::Instance()->getUpdateUrl())));
}
