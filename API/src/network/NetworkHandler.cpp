#include "NetworkHandler.h"
#include "SyncObject.h"

#include <QNetworkDatagram>
#include <QTimer>

NetworkHandler *NetworkHandler::serverInstance{ nullptr };
NetworkHandler *NetworkHandler::clientInstance{ nullptr };
QMap<QString, BaseSyncObjectPrototype *> NetworkHandler::allSyncObjects{};
QQueue<BaseSyncObjectPrototype *> NetworkHandler::objectsToRegister{};

void NetworkHandler::registerSyncObjects()
{
	while (!objectsToRegister.isEmpty())
	{
		BaseSyncObjectPrototype *obj = objectsToRegister.dequeue();
		BaseRegistryEntry *entry = dynamic_cast<BaseRegistryEntry *>(obj);
		if (entry)
			obj->typeName += "@!" + entry->getName();

		allSyncObjects.insert(obj->typeName, obj);
	}
}

NetworkHandler::NetworkHandler(Side _side) : side(_side)
{
	socket = new QUdpSocket(this);
	socket->bind(QHostAddress::LocalHost, 25565 + side);
	connect(socket, &QUdpSocket::readyRead, this, &NetworkHandler::readData);
	connect(this, &NetworkHandler::updateHasPendingDatagram, this, &NetworkHandler::readData);
	readData();
	QTimer *timer = new QTimer(this);
	timer->setInterval(20);
	connect(timer, &QTimer::timeout, this, &NetworkHandler::testHasPendingDatagram);
	timer->start();
}

void NetworkHandler::readData()
{
	if (socket->hasPendingDatagrams())
	{
		auto data = socket->receiveDatagram(-1);
		PacketBuffer buffer{};
		buffer.pushData(data.data().constData(), data.data().size());
		bool isNew = buffer.read<bool>();

		if (isNew)
		{
			QString typeName = buffer.readString();
			SyncObject *obj = allSyncObjects[typeName]->createObjFromNet(side);
			obj->connection = buffer.read<size_t>();
			obj->deserialize(&buffer);
			obj->notifyCreatedByNet();

			PacketBuffer sendBuffer{};
			sendBuffer.write<size_t>((size_t)obj);
			sendBuffer.write<size_t>(obj->connection);
			sendBuffer.write<bool>(true);
			sendBuffer.write<bool>(false);

			for (auto i : addresses)
				socket->writeDatagram(sendBuffer.getData(), sendBuffer.dataLength(), i, 25566 - side);

			emit objectCreatedFromNet(obj);
			obj->prototype->onObjCreated(obj);
		}
		else
		{
			bool isUpdateConnection = buffer.read<bool>();

			if (isUpdateConnection)
			{
				SyncObject *temp = (SyncObject *)(buffer.read<size_t>());
				temp->connection = buffer.read<size_t>();
				temp->notifyChange();
			}
			else
			{
				bool isDelete = buffer.read<bool>();

				if (isDelete)
				{
					SyncObject *temp = (SyncObject *)(buffer.read<size_t>());
					if(temp)
						temp->connection = 0;
					delete temp;
				}
				else
				{
					SyncObject *temp = (SyncObject *)(buffer.read<size_t>());
					if (!temp)
						return;
					temp->deserialize(&buffer);
					temp->notifyDataRecieve();
					temp->prototype->onDataRecieved(temp);
				}
			}
		}
	}
}

void NetworkHandler::testHasPendingDatagram()
{
	if (socket->hasPendingDatagrams())
	{
		emit updateHasPendingDatagram();
	}
}

NetworkHandler::~NetworkHandler()
{
}

void NetworkHandler::newSyncObject(SyncObject *object, const QString &typeName)
{
	PacketBuffer buffer{};
	object->serialize(&buffer);
	buffer.write<size_t>((size_t)object);
	buffer.writeString(typeName);
	buffer.write<bool>(true);

	for (auto i : addresses)
		socket->writeDatagram(buffer.getData(), buffer.dataLength(), i, 25566 - side);
}

void NetworkHandler::updateSyncObject(SyncObject *object)
{
	PacketBuffer buffer{};
	object->serialize(&buffer);
	buffer.write<size_t>(object->connection);
	buffer.write<bool>(false);
	buffer.write<bool>(false);
	buffer.write<bool>(false);

	for (auto i : addresses)
		socket->writeDatagram(buffer.getData(), buffer.dataLength(), i, 25566 - side);
}

void NetworkHandler::addConnection(QHostAddress address)
{
	assert(addresses.length() <= 1 || side == Side::SERVER);
	addresses.push_back(address);
}

void NetworkHandler::deleteSyncObject(SyncObject *object)
{
	PacketBuffer buffer{};
	buffer.write<size_t>(object->connection);
	buffer.write<bool>(true);
	buffer.write<bool>(false);
	buffer.write<bool>(false);

	for (auto i : addresses)
		socket->writeDatagram(buffer.getData(), buffer.dataLength(), i, 25566 - side);
}
