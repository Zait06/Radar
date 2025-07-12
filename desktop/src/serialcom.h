#ifndef SERIALCOM_H
#define SERIALCOM_H

#include <QJSEngine>
#include <QObject>
#include <QPair>
#include <QQmlEngine>
#include <QQmlListProperty>
#include <QSerialPort>
#include <QtQmlIntegration/qqmlintegration.h>

class SerialCom : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint32 baudRate READ baudRate WRITE setBaudRate NOTIFY baudRateChanged)
    Q_PROPERTY(QString serialPort READ serialPort WRITE setSerialPort NOTIFY serialPortChanged)
    Q_PROPERTY(QVariantList baudRates MEMBER m_baudRates)
    QML_ELEMENT
    QML_SINGLETON

    SerialCom();

public:
    ~SerialCom();

    qint32 baudRate();
    void setBaudRate(qint32 newBaudRate);

    QString serialPort();
    void setSerialPort(QString newSerialPort);

    static SerialCom *instance();
    static SerialCom *create(QQmlEngine *engine, QJSEngine *scriptEngine);

private:
    QSerialPort m_serialPort;
    QVariantList m_baudRates;

    static SerialCom *m_instance;

signals:
    void baudRateChanged();
    void serialPortChanged();
    void angleDistance(int angle, double distance);
};

#endif