#include "SyncObject.h"

SyncObject::SyncObject(QObject *parent) : SerializableObject(parent), connection(0), side(Side::SERVER)
{
	connect(this, SIGNAL(changed()), this, SLOT(sendSelf()));
}

void SyncObject::sendSelf()
{
	if (side == Side::SERVER)
		NetworkHandler::getServerInstance()->updateSyncObject(this);
	else
		NetworkHandler::getClientInstance()->updateSyncObject(this);
}
