#include "hourly.h"

Hourly::Hourly(QObject *parent)
    : QObject{parent}
{

}

Hourly::Hourly(QString timeLine, QString temperature, QString precipitationProbability) {
    this->m_timeLine = timeLine;
    this->m_temperature = temperature;
    this->m_precipitationProbability = precipitationProbability;
}

QString Hourly::toString()  const{
    return m_timeLine + " " + m_temperature + " " + m_precipitationProbability;
}

QString Hourly::timeLine() const{
    return m_timeLine;
}

QString Hourly::temperature() const{
    return m_temperature;
}

QString Hourly::precipitationProbability() const{
    return m_precipitationProbability;
}
