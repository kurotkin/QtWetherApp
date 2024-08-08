#ifndef HOURLY_H
#define HOURLY_H

#include <QObject>

class Hourly : public QObject
{
   Q_OBJECT
   Q_PROPERTY(QString timeLine READ timeLine CONSTANT FINAL)
   Q_PROPERTY(QString temperature READ temperature CONSTANT FINAL)
   Q_PROPERTY(QString precipitationProbability READ precipitationProbability CONSTANT FINAL)

public:
    explicit Hourly(QObject *parent = nullptr);
    Hourly(QString timeLine, QString temperature, QString precipitationProbability);
    QString toString()  const;
    QString timeLine()  const;
    QString temperature()  const;
    QString precipitationProbability()  const;

private:
    QString m_timeLine;
    QString m_temperature;
    QString m_precipitationProbability;
};

#endif // HOURLY_H
