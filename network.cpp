#include "network.h"

Network::Network(QObject *parent): QObject{parent}
{ }

void Network::httpConnect(){

    qDebug()<<QSslSocket::

    manager = new QNetworkAccessManager();

    QObject::connect(manager, &QNetworkAccessManager::finished,
                     this,
                     [=](QNetworkReply *reply) {
                         if (reply->error()) {
                             qDebug() << reply->errorString();
                             return;
                         }

                         QString answer = reply->readAll();

                         qDebug() << answer;
                     });

    request.setUrl(QUrl("https://api.open-meteo.com/v1/forecast?latitude=55.7522&longitude=37.6156&hourly=temperature_180m,precipitation_probability,precipitation"));
    manager->get(request);
}
