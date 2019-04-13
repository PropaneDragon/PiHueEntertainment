#pragma once

#include <vector>
#include <memory>

#include <QDialog>

#include "ui_entertainmentGroupConnectDialog.h"

namespace huestream
{
	class Bridge;
	class Group;
}

class EntertainmentGroupConnectDialog : public QDialog, public Ui::EntertainmentGroupConnectDialog
{
	Q_OBJECT;

public:
	EntertainmentGroupConnectDialog(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
	EntertainmentGroupConnectDialog(std::shared_ptr<huestream::Bridge> bridge, QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
	EntertainmentGroupConnectDialog(std::vector<std::shared_ptr<huestream::Group>> groups, QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

	void setGroups(std::shared_ptr<huestream::Bridge> bridge);
	void setGroups(std::vector<std::shared_ptr<huestream::Group>> groups);

	std::shared_ptr<huestream::Group> getSelectedGroup() const;

protected slots:
	void bottomButtonClicked(QAbstractButton *button);

private:


};