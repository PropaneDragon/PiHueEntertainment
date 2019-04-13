#include "huestream/HueStream.h"

#include "hueBridgeListModel.h"

HueBridgeListModel::HueBridgeListModel(QObject *parent) : QAbstractListModel(parent)
{
}

HueBridgeListModel::HueBridgeListModel(std::vector<std::shared_ptr<huestream::Bridge>> bridges, QObject *parent) : HueBridgeListModel(parent)
{
	setBridges(bridges);
}

void HueBridgeListModel::setBridges(std::vector<std::shared_ptr<huestream::Bridge>> bridges)
{
	_bridges = bridges;
}

int HueBridgeListModel::rowCount(const QModelIndex &parent) const
{
	return _bridges.size();
}

QVariant HueBridgeListModel::data(const QModelIndex &index, int role) const
{
	auto row = index.row();
	auto actualRole = (Qt::ItemDataRole)role;

	if (row >= 0 && row < rowCount()) {
		if (actualRole == Qt::ItemDataRole::DisplayRole) {

			auto bridge = _bridges.at(row);
			if (bridge) {
				return QString::fromStdString(bridge->GetName());
			}
		}
	}

	return QVariant();
}

QVariant HueBridgeListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	return QVariant();
}

std::shared_ptr<huestream::Bridge> HueBridgeListModel::getBridge(const QModelIndex &index)
{
	auto row = index.row();
	if (row >= 0 && row < rowCount()) {
		return _bridges.at(row);
	}

	return nullptr;
}
