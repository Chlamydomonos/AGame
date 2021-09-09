#include "SyncUnitPrototype.h"
#include "SyncUnit.h"

SyncUnit *SyncUnitPrototype::createFromNet(Side side) const
{
    return new SyncUnit(this, side);
}

SyncUnit *SyncUnitPrototype::createFromLocal(Side side) const
{
    return new SyncUnit(this, side);
}
