#include "SyncObjectProrotype.h"

SyncObject *BaseSyncObjectPrototype::create(Side side, const QString & typeName)
{
    auto out = createObjFromLocal(side);
    if (side == Side::SERVER)
        NetworkHandler::getServerInstance()->newSyncObject(out, typeName);
    else
        NetworkHandler::getClientInstance()->newSyncObject(out, typeName);
    return out;
}

BaseSyncObjectPrototype::BaseSyncObjectPrototype(const QString &_typeName) : typeName(_typeName)
{
    NetworkHandler::allSyncObjects.insert(typeName, this);
}

BaseSyncObjectPrototype::~BaseSyncObjectPrototype()
{
    NetworkHandler::allSyncObjects.remove(typeName);
}
