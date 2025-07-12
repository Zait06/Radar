#include "serialcom.h"

#include <QDebug>

SerialCom *SerialCom::m_instance = nullptr;

SerialCom::SerialCom()
{
    m_baudRates.append(QVariant(QSerialPort::Baud1200));
    m_baudRates.append(QVariant(QSerialPort::Baud2400));
    m_baudRates.append(QVariant(QSerialPort::Baud4800));
    m_baudRates.append(QVariant(QSerialPort::Baud9600));
    m_baudRates.append(QVariant(QSerialPort::Baud19200));
    m_baudRates.append(QVariant(QSerialPort::Baud38400));
    m_baudRates.append(QVariant(QSerialPort::Baud57600));
    m_baudRates.append(QVariant(QSerialPort::Baud115200));
}

SerialCom::~SerialCom() {}

qint32 SerialCom::baudRate()
{
    return m_serialPort.baudRate();
}

void SerialCom::setBaudRate(qint32 newBaudRate)
{
    if (baudRate() == newBaudRate)
        return;
    m_serialPort.setBaudRate(newBaudRate);
    emit baudRateChanged();
}

QString SerialCom::serialPort()
{
    return m_serialPort.portName();
}

void SerialCom::setSerialPort(QString newSerialPort)
{
    if (serialPort() == newSerialPort)
        return;
    m_serialPort.setPortName(newSerialPort);
    emit serialPortChanged();
}

SerialCom *SerialCom::instance()
{
    if (m_instance == nullptr)
        m_instance = new SerialCom;
    return m_instance;
}

SerialCom *SerialCom::create(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    return SerialCom::instance();
}