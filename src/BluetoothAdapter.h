#ifndef BLUETOOTH_ADAPTER_H
#define BLUETOOTH_ADAPTER_H

#include <qbluetoothglobal.h>
#include <qbluetoothlocaldevice.h>
#include <QObject>

QT_FORWARD_DECLARE_CLASS(QBluetoothDeviceDiscoveryAgent)
QT_FORWARD_DECLARE_CLASS(QBluetoothDeviceInfo)

/*
 * Qt Quick adapter for QBluetoothDeviceDiscoveryAgent
 */
class BluetoothAdapter : public QObject
{
    Q_OBJECT
public:
    explicit BluetoothAdapter(QObject *parent = 0);
            ~BluetoothAdapter();

    Q_INVOKABLE void scanForNewDevices();

signals:
    void newDeviceDetected(const QString &info);
    void scanFinished();
    void scanStarted();

public slots:
    void addNewDevice(const QBluetoothDeviceInfo&);

private slots:
    void finishedScanning();

private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
};

#endif // BLUETOOTH_ADAPTER_H
