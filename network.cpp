#include "network.h"
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include<hourly.h>

Network::Network(QObject *parent): QObject{parent}
{ }

void Network::httpConnect(){

    qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();


    manager = new QNetworkAccessManager();

    QObject::connect(manager, &QNetworkAccessManager::finished,
                     this,
                     [=](QNetworkReply *reply) {
                         if (reply->error()) {
                             qDebug() << reply->errorString();
                             return;
                         }

                         QString answer = reply->readAll();
                         QByteArray json_bytes = answer.toLocal8Bit();
                         auto jsonDocument = QJsonDocument::fromJson(json_bytes);
                         auto json_obj=jsonDocument.object();

                         QVariantList timeArray = json_obj.toVariantMap()["hourly"].toJsonObject().toVariantMap()["time"].toList();
                         QVariantList temperatureArray = json_obj.toVariantMap()["hourly"].toJsonObject().toVariantMap()["temperature_180m"].toList();
                         QVariantList precipitationProbabilityArray = json_obj.toVariantMap()["hourly"].toJsonObject().toVariantMap()["precipitation_probability"].toList();

                         QList<Hourly*> hourlyList;
                         for(int i=0; i<timeArray.count(); ++i){
                             hourlyList.append(new Hourly(timeArray.at(i).toString(), temperatureArray.at(i).toString(), precipitationProbabilityArray.at(i).toString()));
                         }

                         for(int i=0; i<hourlyList.count(); ++i){
                             qDebug() << hourlyList[i]->toString();
                         }

                         //qDebug() << answer;
                     });

    request.setUrl(QUrl("https://api.open-meteo.com/v1/forecast?latitude=55.7522&longitude=37.6156&hourly=temperature_180m,precipitation_probability,precipitation"));
    manager->get(request);
}
