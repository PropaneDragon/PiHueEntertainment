#pragma once

#include <QAbstractListModel>

namespace huestream
{
	class Group;
}

class EntertainmentGroupListModel : public QAbstractListModel
{
public:
	EntertainmentGroupListModel(QObject *parent = nullptr);
	EntertainmentGroupListModel(std::vector<std::shared_ptr<huestream::Group>> groups, QObject *parent = nullptr);

	void setGroups(std::vector<std::shared_ptr<huestream::Group>> groups);

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;

	QVariant data(const QModelIndex &index, int role) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::ItemDataRole::DisplayRole) const override;

	std::shared_ptr<huestream::Group> getGroup(const QModelIndex &index) const;
	std::shared_ptr<huestream::Group> getGroup(int index) const;

private:
	std::vector<std::shared_ptr<huestream::Group>> _groups;
};