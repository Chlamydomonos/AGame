#include "SyncObjectProrotype.h"

SyncObject *BaseSyncObjectPrototype::create(Side side, int flag) const
{
    auto out = createObjFromLocal(side);
    if (side == Side::SERVER)
        NetworkHandler::getServerInstance()->newSyncObject(out, typeName);
    else
        NetworkHandler::getClientInstance()->newSyncObject(out, typeName);
    return out;
}

BaseSyncObjectPrototype::BaseSyncObjectPrototype(const QString &_typeName)
{
    typeName = _typeName;
    NetworkHandler::objectsToRegister.enqueue(this);
}

BaseSyncObjectPrototype::~BaseSyncObjectPrototype()
{
    NetworkHandler::allSyncObjects.remove(typeName);
}
