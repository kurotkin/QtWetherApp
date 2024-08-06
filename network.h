#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = nullptr);
    void httpConnect();

private:
    QNetworkAccessManager *manager;
    QNetworkRequest request;

signals:
};

#endif // NETWORK_H
