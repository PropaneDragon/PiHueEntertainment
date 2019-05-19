#include "monitoring.h"
#include "performanceItemModel.h"

PerformanceItemModel::PerformanceItemModel(QObject *parent) : QAbstractItemModel(parent)
{
}

int PerformanceItemModel::rowCount(const QModelIndex &parent) const
{
	auto timing = getTiming(parent);
	if (timing) {
		return timing->getChildren().size();
	}

	return 0;
}

int PerformanceItemModel::columnCount(const QModelIndex &parent) const
{
	return 2;
}

bool PerformanceItemModel::hasChildren(const QModelIndex &parent) const
{
	auto timing = getTiming(parent);
	if (timing) {
		return timing->getChildren().size() > 0;
	}

	return true;
}

QModelIndex PerformanceItemModel::index(int row, int column, const QModelIndex &parent) const
{
	auto associatedTiming = Monitoring::Instance()->getRoot();

	if (parent.isValid()) {

		auto parentTiming = (Timing *)(parent.internalPointer());
		if (parentTiming) {

			auto children = parentTiming->getChildren();

			if (row >= 0 && row < children.size()) {
				associatedTiming = children[row];
			}
		}
	}

	return createIndex(row, column, associatedTiming);
}

QModelIndex PerformanceItemModel::parent(const QModelIndex &child) const
{
	if (child.isValid()) {

		auto associatedTiming = (Timing *)child.internalPointer();
		if (associatedTiming) {

			auto parent = associatedTiming->getParent();
			if (parent) {

				return createIndex(getRow(parent), 0, parent);
			}
		}
	}

	return QModelIndex();
}

QVariant PerformanceItemModel::data(const QModelIndex &index, int role) const
{
	if (role == Qt::ItemDataRole::DisplayRole) {

		auto timing = getTiming(index);
		if (timing) {

			auto column = index.column();
			switch (column) {
			case 0:
				return QString::fromStdString(timing->getName());
			case 1:
				return QString::number(timing->getMilliseconds());
			}
		}
	}

	return QVariant();
}

Timing* PerformanceItemModel::getTiming(const QModelIndex &index) const
{
	if (index.isValid()) {

		return (Timing *)index.internalPointer();
	}

	return Monitoring::Instance()->getRoot();
}

int PerformanceItemModel::getRow(const QModelIndex &index) const
{
	if (index.isValid()) {

		auto associatedTiming = (Timing *)index.internalPointer();
		if (associatedTiming) {

			return getRow(associatedTiming);
		}
	}

	return 0;
}

int PerformanceItemModel::getRow(Timing *timing) const
{
	if (timing) {
		
		auto parent = timing->getParent();
		if (parent) {

			auto children = parent->getChildren();
			for (auto row = 0; row < children.size(); ++row) {

				if (children[row] == timing) {
					return row;
				}
			}
		}
	}

	return 0;
}

QModelIndexList PerformanceItemModel::getAllParents(const QModelIndex &child) const
{
	QModelIndexList parents;

	if (child.isValid()) {
		auto parent = child.parent();
		while (parent.isValid()) {

			parents.push_back(parent);
			parent = parent.parent();
		}
	}

	return parents;
}

std::vector<Timing*> PerformanceItemModel::getParentTimings(const QModelIndex &index) const
{
	std::vector<Timing*> parents;

	if (index.isValid()) {
		
		auto associatedTiming = getTiming(index);
		if (associatedTiming) {

			auto parent = associatedTiming->getParent();
			while (parent) {

				parents.push_back(parent);

				parent = parent->getParent();
			}
		}
	}

	return parents;
}