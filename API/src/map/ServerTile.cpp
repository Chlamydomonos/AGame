#include "ServerTile.h"
#include "ServerTilePrototype.h"
#include "ServerMap.h"
#include "SyncTile.h"

const Direction Direction::UP{ 0x0000ffff0001 };
const Direction Direction::DOWN{ 0x0000ffffffff };
const Direction Direction::FRONT{ 0x00010000ffff };
const Direction Direction::BACK{ 0xffff00000001 };
const Direction Direction::RIGHT{ 0x0001ffff0000 };
const Direction Direction::LEFT{ 0xffff00010000 };

void ServerTile::initMap(ServerMap *map)
{
	this->map = map;
	neighbours[Direction::UP] = map->getTile(x + Direction::UP.x(), y + Direction::UP.y(), z + Direction::UP.z());
	neighbours[Direction::DOWN] = map->getTile(x + Direction::DOWN.x(), y + Direction::DOWN.y(), z + Direction::DOWN.z());
	neighbours[Direction::LEFT] = map->getTile(x + Direction::LEFT.x(), y + Direction::LEFT.y(), z + Direction::LEFT.z());
	neighbours[Direction::RIGHT] = map->getTile(x + Direction::RIGHT.x(), y + Direction::RIGHT.y(), z + Direction::RIGHT.z());
	neighbours[Direction::FRONT] = map->getTile(x + Direction::FRONT.x(), y + Direction::FRONT.y(), z + Direction::FRONT.z());
	neighbours[Direction::BACK] = map->getTile(x + Direction::BACK.x(), y + Direction::BACK.y(), z + Direction::BACK.z());
}

void ServerTile::bindSyncTile(SyncTile *syncTile)
{
	this->syncTile = syncTile;
	this->syncTile->setParent(this);
}
