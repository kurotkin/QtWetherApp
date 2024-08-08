#ifndef LISTITEMMODEL_H
#define LISTITEMMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <hourly.h>

class ListItemModel: public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QList<Hourly *> hourlyWeater READ getHourlyWeater WRITE setHourlyWeater NOTIFY weaterChanged FINAL)

public:
    explicit ListItemModel(QObject *parent = nullptr);
    QList<Hourly> getHourlyWeater() const;
    void setHourlyWeater(QList<Hourly> newHourlyWeater);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

signals:
    void weaterChanged();

private:
    QList<Hourly> m_hourlyWeater;

};

#endif // LISTITEMMODEL_H
