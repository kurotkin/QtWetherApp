#include "listitemmodel.h"

ListItemModel::ListItemModel(QObject *parent) : QAbstractListModel{parent} {
    //m_hourlyWeater.append(new Hourly(QString("6464"), QString("66666"), QString("677777")));

}

QList<Hourly> ListItemModel::getHourlyWeater() const
{
    return m_hourlyWeater;
}

int ListItemModel::rowCount(const QModelIndex &parent) const
{
    return m_hourlyWeater.size();
}

void ListItemModel::setHourlyWeater(QList<Hourly> newHourlyWeater)
{
    // if (m_hourlyWeater == newHourlyWeater)
    //     return;
    m_hourlyWeater = newHourlyWeater;
    emit weaterChanged();
}


QVariant ListItemModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}
