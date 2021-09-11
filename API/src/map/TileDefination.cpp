#include "TileDefination.h"
#include "../core/Game.h"

void TileDefination::onObjCreated(SyncTile *obj) const
{
	if (obj->getSide() == Side::CLIENT)
	{
		Sprite *tile = createClientTile(obj);
		Game::getInstance()->getClient()->getScene()->addItem(tile);
	}
}

ServerTile *TileDefination::createServerTile(int x, int y, int z) const
{
	ServerTile *tile = ServerTilePrototype::create();
	tile->setPosition(x, y, z);
	SyncTile *syncTile = SyncTilePrototype::create(Side::SERVER);
	tile->bindSyncTile(syncTile);
	syncTile->x = tile->x;
	syncTile->y = tile->y;
	syncTile->z = tile->z;
	return tile;
}

Sprite *TileDefination::createClientTile(SyncTile *tile) const
{
	Sprite *sprite = ClientTilePrototype::create();
	tile->clientTile = sprite;
	sprite->getDataMap().insert("sync", (size_t)tile);
	return sprite;
}
