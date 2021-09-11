#include "TileDefination.h"
#include "../core/Game.h"
#include "ServerMap.h"

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

void TileDefination::onDataRecieved(SyncTile *object) const
{
	SyncTilePrototype::onDataRecieved(object);
	if (object->side == Side::CLIENT)
	{
		if (object->highlight == 0)
			object->clientTile->stopAnimation();
		if (object->highlight == 1)
			object->clientTile->startAnimation("green");
		if (object->highlight == 2)
			object->clientTile->startAnimation("red");
	}
	else
	{
		auto ser = dynamic_cast<ServerTile *>(object->parent());
		if (object->getChosen())
			ser->map->setChosenTile(ser);
		else if (ser->map->getChosenTile() == ser)
			ser->map->setChosenTile(nullptr);
	}
}

void TileDefination::mouseReleaseEvent(Sprite *sprite, QGraphicsSceneMouseEvent *event) const
{
	auto tile = (SyncTile *)(sprite->getDataMap()["sync"].toInt());

	if (Game::getInstance()->getClient()->getMap()->getCanChooseTile())
	{
		if (!tile->chosen)
		{
			tile->setChosen(true);
			tile->notifyChange();
		}
		else
		{
			tile->setChosen(false);
			tile->notifyChange();
		}
	}
	ClientTilePrototype::mouseReleaseEvent(sprite, event);
}
