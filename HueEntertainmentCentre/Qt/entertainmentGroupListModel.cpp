#include "huestream/HueStream.h"

#include "entertainmentGroupListModel.h"

EntertainmentGroupListModel::EntertainmentGroupListModel(QObject *parent) : QAbstractListModel(parent)
{
}

EntertainmentGroupListModel::EntertainmentGroupListModel(std::vector<std::shared_ptr<huestream::Group>> groups, QObject *parent) : EntertainmentGroupListModel(parent)
{
	setGroups(groups);
}

void EntertainmentGroupListModel::setGroups(std::vector<std::shared_ptr<huestream::Group>> groups)
{
	_groups = groups;
}

int EntertainmentGroupListModel::rowCount(const QModelIndex &parent) const
{
	return _groups.size();
}

QVariant EntertainmentGroupListModel::data(const QModelIndex &index, int role) const
{
	auto actualRole = (Qt::ItemDataRole)role;

	if (index.isValid()) {
		if (actualRole == Qt::ItemDataRole::DisplayRole) {

			auto group = getGroup(index);
			if (group) {
				return QString::fromStdString(group->GetName());
			}
		}
	}

	return QVariant();
}

QVariant EntertainmentGroupListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	return QVariant();
}

std::shared_ptr<huestream::Group> EntertainmentGroupListModel::getGroup(const QModelIndex &index) const
{
	return getGroup(index.row());
}

std::shared_ptr<huestream::Group> EntertainmentGroupListModel::getGroup(int index) const
{
	if (index >= 0 && index < rowCount()) {
		return _groups.at(index);
	}

	return nullptr;
}
