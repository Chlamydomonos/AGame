#include "SyncMapPrototype.h"
#include "SyncMap.h"

SyncMap *SyncMapPrototype::createFromNet(Side side) const
{
    return new SyncMap(this, side);
}

SyncMap *SyncMapPrototype::createFromLocal(Side side) const
{
    return new SyncMap(this, side);
}
