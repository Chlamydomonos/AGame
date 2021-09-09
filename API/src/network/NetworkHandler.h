#ifndef NETWORK__NETWORK_HANDLER_H
#define NETWORK__NETWORK_HANDLER_H

#include "Side.h"
#include <QObject>
#include <QMap>

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
	friend class SendThread;
	Side side;
	static NetworkHandler serverInstance;
	static NetworkHandler clientInstance;
	static QMap<QString, BaseSyncObjectPrototype *> allSyncObjects;
	QList<QHostAddress> addresses;
	QUdpSocket *socket;
	NetworkHandler(Side _side);
private slots:
	void readData();
public:
	~NetworkHandler();
	static NetworkHandler *getServerInstance() { return &serverInstance; }
	static NetworkHandler *getClientInstance() { return &clientInstance; }
public slots:
	void newSyncObject(SyncObject *object, const QString &typeName);
	void updateSyncObject(SyncObject *object);
	void addConnection(QHostAddress address);
};

#endif // !NETWORK__NETWORK_HANDLER_H
