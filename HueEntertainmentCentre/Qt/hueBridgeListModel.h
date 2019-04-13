#pragma once

#include <QAbstractListModel>

namespace huestream {
	class Bridge;
}

class HueBridgeListModel : public QAbstractListModel
{
public:
	HueBridgeListModel(QObject *parent = nullptr);
	HueBridgeListModel(std::vector<std::shared_ptr<huestream::Bridge>> bridges, QObject *parent = nullptr);

	void setBridges(std::vector<std::shared_ptr<huestream::Bridge>> bridges);

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;

	QVariant data(const QModelIndex &index, int role) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::ItemDataRole::DisplayRole) const override;

	std::shared_ptr<huestream::Bridge> getBridge(const QModelIndex &index);

private:
	std::vector<std::shared_ptr<huestream::Bridge>> _bridges;
};