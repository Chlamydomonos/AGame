#ifndef NETWORK__NETWORK_HANDLER_H
#define NETWORK__NETWORK_HANDLER_H

#include "Side.h"
#include <QObject>
#include <QMap>
#include <QQueue>

#include <QUdpSocket>
#include <QQueue>
#include <QThread>

class SyncObject;

template<class T>
class SyncObjectPrototype;

class NetworkHandler : public QObject
{
	Q_OBJECT
private:
	friend class BaseSyncObjectPrototype;
	friend class Game;
	friend class Server;
	friend class Client;
	friend class MainWidget;
	friend int main(int argc, char *argv[]);
	Side side;
	static NetworkHandler *serverInstance;
	static NetworkHandler *clientInstance;
	static QMap<QString, BaseSyncObjectPrototype *> allSyncObjects;
	static QQueue<BaseSyncObjectPrototype *> objectsToRegister;
	static void registerSyncObjects();
	QList<QHostAddress> addresses;
	QUdpSocket *socket;
	NetworkHandler(Side _side);
private slots:
	void readData();
	void testHasPendingDatagram();
public:
	~NetworkHandler();
	static NetworkHandler *getServerInstance() { return serverInstance; }
	static NetworkHandler *getClientInstance() { return clientInstance; }
public slots:
	void newSyncObject(SyncObject *object, const QString &typeName);
	void updateSyncObject(SyncObject *object);
	void addConnection(QHostAddress address);
	void deleteSyncObject(SyncObject *object);
signals:
	void updateHasPendingDatagram();
	void objectCreatedFromNet(SyncObject *object);
};

#endif // !NETWORK__NETWORK_HANDLER_H
