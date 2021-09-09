#ifndef MAP__SYNC_TILE_PROTOTYPE_H
#define MAP__SYNC_TILE_PROTOTYPE_H

#include "../network/SyncObjectProrotype.h"

class SyncTile;

class SyncTilePrototype : public SyncObjectPrototype<SyncTile>
{
private:
	virtual SyncTile *createFromNet(Side side) const override final;
	virtual SyncTile *createFromLocal(Side side) const override final;
};

#endif // !MAP__SYNC_TILE_PROTOTYPE_H
