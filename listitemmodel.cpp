#include "listitemmodel.h"

ListItemModel::ListItemModel(QObject *parent) : QAbstractListModel{parent}
{
    m_contacts.append("Jack London");
   m_contacts.append("Jack London");
m_contacts.append("Jack London");
}

QList<QString> ListItemModel::contacts() const
{
    return m_contacts;
}

int ListItemModel::rowCount(const QModelIndex &parent) const
{
    return m_contacts.size();
}

void ListItemModel::setContacts(const QList<QString> &newContacts)
{
    if (m_contacts == newContacts)
        return;
    m_contacts = newContacts;
    emit contactsChanged();
}

QHash<int, QByteArray> ListItemModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    return roles;
}

QVariant ListItemModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}
