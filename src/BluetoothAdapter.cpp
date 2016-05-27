#include "BluetoothAdapter.h"
#include <qbluetoothdevicediscoveryagent.h>

BluetoothAdapter::BluetoothAdapter(QObject *parent) : QObject(parent)
{
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();

    connect(discoveryAgent, SIGNAL(deviceDiscovered(const QBluetoothDeviceInfo&)), this, SLOT(addNewDevice(const QBluetoothDeviceInfo&)));
    connect(discoveryAgent, SIGNAL(finished()), this, SLOT(finishedScanning()));
}

BluetoothAdapter::~BluetoothAdapter()
{
    delete discoveryAgent;
}

/* slot for discoveryAgent.deviceDiscovered()
 */
void BluetoothAdapter::addNewDevice(const QBluetoothDeviceInfo &info)
{
    emit newDeviceDetected(QString("%1 %2").arg(info.address().toString()).arg(info.name()));
}

/* slot for discoveryAgent.finished()
 */
void BluetoothAdapter::finishedScanning()
{
    emit scanFinished();
}

/* start scanning for new bluetooth devices
 */
void BluetoothAdapter::scanForNewDevices()
{
    discoveryAgent->start();
    emit scanStarted();
}
