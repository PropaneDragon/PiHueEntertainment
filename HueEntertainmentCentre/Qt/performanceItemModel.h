#pragma once

#include <QAbstractItemModel>

#include <vector>

class Timing;
class PerformanceItemModel : public QAbstractItemModel
{
public:
	PerformanceItemModel(QObject *parent = nullptr);

	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;

	virtual bool hasChildren(const QModelIndex &parent = QModelIndex()) const override;

	virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
	virtual QModelIndex parent(const QModelIndex &child) const override;

	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	Timing* getTiming(const QModelIndex &index) const;

private:
	int getRow(const QModelIndex &index) const;
	int getRow(Timing *timing) const;

	QModelIndexList getAllParents(const QModelIndex &child) const;

	std::vector<Timing*> getParentTimings(const QModelIndex &index) const;

};