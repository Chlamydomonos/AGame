#include "ServerMap.h"
#include "SyncMap.h"

void ServerMap::bindSyncMap(SyncMap *syncMap)
{
}

ServerTile *ServerMap::getTile(short x, short y, short z)
{
	unsigned long long index = (((unsigned long long) ((unsigned short)x)) << 32) | (((unsigned long long) ((unsigned short)y)) << 16) | ((unsigned long long) ((unsigned short)z));
	if (tiles.contains(index))
		return tiles[index];
	return nullptr;
}

ServerTile *ServerMap::getTile(unsigned long long index)
{
	if (tiles.contains(index))
		return tiles[index];
	return nullptr;
}

ServerUnit *ServerMap::getUnit(short x, short y, short z)
{
	unsigned long long index = (((unsigned long long) ((unsigned short)x)) << 32) | (((unsigned long long) ((unsigned short)y)) << 16) | ((unsigned long long) ((unsigned short)z));
	if (units.contains(index))
		return units[index];
	return nullptr;
}

ServerUnit *ServerMap::getUnit(unsigned long long index)
{
	if (units.contains(index))
		return units[index];
	return nullptr;
}
