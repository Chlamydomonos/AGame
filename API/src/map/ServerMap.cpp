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

void ServerMap::setChosenTile(ServerTile *tile)
{
	if (chosenTile != nullptr && chosenTile != tile)
	{
		chosenTile->getSyncTile()->setChosen(false);
		chosenTile->getSyncTile()->notifyChange();
	}

	chosenTile = tile;
}

void ServerMap::setChosenUnit(ServerUnit *unit)
{
	if (chosenUnit != nullptr && chosenUnit != unit)
	{
		chosenUnit->getSyncUnit()->setChosen(false);
		chosenUnit->getSyncUnit()->notifyChange();
	}
	chosenUnit = unit; 
}
