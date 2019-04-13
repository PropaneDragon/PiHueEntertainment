#include <QAbstractButton>

#include "huestream/HueStream.h"

#include "entertainmentGroupListModel.h"
#include "entertainmentGroupConnectDialog.h"

EntertainmentGroupConnectDialog::EntertainmentGroupConnectDialog(QWidget *parent, Qt::WindowFlags flags) : QDialog(parent, flags)
{
	setupUi(this);

	buttons_bottom->addButton("Connect", QDialogButtonBox::ButtonRole::AcceptRole);
}

EntertainmentGroupConnectDialog::EntertainmentGroupConnectDialog(std::shared_ptr<huestream::Bridge> bridge, QWidget *parent, Qt::WindowFlags flags) : EntertainmentGroupConnectDialog(parent, flags)
{
	setGroups(bridge);
}

EntertainmentGroupConnectDialog::EntertainmentGroupConnectDialog(std::vector<std::shared_ptr<huestream::Group>> groups, QWidget *parent, Qt::WindowFlags flags) : EntertainmentGroupConnectDialog(parent, flags)
{
	setGroups(groups);
}

void EntertainmentGroupConnectDialog::setGroups(std::shared_ptr<huestream::Bridge> bridge)
{
	if (bridge) {
		auto groups = bridge->GetGroups();
		if (groups) {
			setGroups(*groups);
		}
	}
}

void EntertainmentGroupConnectDialog::setGroups(std::vector<std::shared_ptr<huestream::Group>> groups)
{
	auto model = new EntertainmentGroupListModel(groups, this);
	list_groups->setModel(model);
}

std::shared_ptr<huestream::Group> EntertainmentGroupConnectDialog::getSelectedGroup() const
{
	auto model = dynamic_cast<EntertainmentGroupListModel *>(list_groups->model());
	auto selectionModel = list_groups->selectionModel();

	if (model && selectionModel) {
		auto selectedIndexes = selectionModel->selectedIndexes();
		if (selectedIndexes.count() > 0) {
			auto firstIndex = selectedIndexes.first();

			return model->getGroup(firstIndex);
		}
	}

	return nullptr;
}

void EntertainmentGroupConnectDialog::bottomButtonClicked(QAbstractButton *button)
{
	auto role = buttons_bottom->buttonRole(button);
	if (role == QDialogButtonBox::ButtonRole::AcceptRole) {
		accept();
	}
	else {
		reject();
	}
}
