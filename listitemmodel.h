#ifndef LISTITEMMODEL_H
#define LISTITEMMODEL_H

#include <QAbstractListModel>
#include <QObject>

class ListItemModel: public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QList<QString> contacts READ contacts WRITE setContacts NOTIFY contactsChanged FINAL)

public:
    explicit ListItemModel(QObject *parent = nullptr);
    QList<QString> contacts() const;
    void setContacts(const QList<QString> &newContacts);

    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

signals:
    void contactsChanged();

private:
    QList <QString> m_contacts;

};

#endif // LISTITEMMODEL_H
