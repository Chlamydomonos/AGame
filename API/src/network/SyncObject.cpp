#include "SyncObject.h"

SyncObject::SyncObject(const BaseSyncObjectPrototype *_prototype, Side _side, QObject *parent) :
	SerializableObject(parent), connection(0), side(_side), prototype(_prototype)
{
	connect(this, SIGNAL(changed()), this, SLOT(sendSelf()));
}

void SyncObject::notifyDataRecieve()
{
	prototype->onDataRecieved(this);
	emit dataRecieved();
}

void SyncObject::sendSelf()
{
	if (side == Side::SERVER)
		NetworkHandler::getServerInstance()->updateSyncObject(this);
	else
		NetworkHandler::getClientInstance()->updateSyncObject(this);
}
