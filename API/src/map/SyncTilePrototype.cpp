#include "SyncTilePrototype.h"
#include "SyncTile.h"

SyncTile *SyncTilePrototype::createFromNet(Side side) const
{
    return new SyncTile(this, side);
}

SyncTile *SyncTilePrototype::createFromLocal(Side side) const
{
    return new SyncTile(this, side);
}
