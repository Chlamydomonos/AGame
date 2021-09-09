#include "TileDefination.h"

ServerTile *TileDefination::createServerTile(int x, int y, int z) const
{
	ServerTile *tile = ServerTilePrototype::create();
	tile->setPosition(x, y, z);
	SyncTile *syncTile = SyncTilePrototype::create(Side::SERVER);
	tile->bindSyncTile(syncTile);
	syncTile->x = tile->x;
	syncTile->y = tile->y;
	syncTile->z = tile->z;
	syncTile->notifyChange();
	return tile;
}

Sprite *TileDefination::createClientTile(SyncTile *tile) const
{
	Sprite *sprite = ClientTilePrototype::create();
	tile->clientTile = sprite;
	return nullptr;
}
