#include "ServerMap.h"
#include "SyncMap.h"
#include "../unit/UnitDefination.h"

void ServerMap::bindSyncMap(SyncMap *syncMap)
{
	syncMap->setParent(this);
	this->syncMap = syncMap;
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

	if (chosenTile != nullptr && chosenUnit != nullptr)
	{
		moveUnit();
	}
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

void ServerMap::createUnit(const QString &name, bool player, short x, short y, short z)
{
	auto unit = AllRegistries::getInstance()->getRegistry<UnitDefination>()->get(name)->createServerUnit(x, y, z);
	unit->initMap(this);
}

void ServerMap::findUnitPath()
{
	pathFinder.clear();
	pathFinder.search(chosenUnit->getSyncUnit()->getIndex(), dynamic_cast<const UnitDefination *>(chosenUnit->prototype)->getMov(chosenUnit->getSyncUnit()->getLevel()));

	QSet<unsigned long long>availablePositions = pathFinder.getAvailablePositions();

	for (auto i : availablePositions)
	{
		if (i != chosenUnit->getSyncUnit()->getIndex())
			getTile(i)->getSyncTile()->setHighlight(1);
		getTile(i)->getSyncTile()->notifyChange();
	}

	if (availablePositions.size() > 1)
	{
		syncMap->setCanChooseTile(true);
		syncMap->notifyChange();
	}
}

void ServerMap::moveUnit()
{
	auto path = pathFinder.getPathTo(chosenTile->index());
	chosenUnit->syncUnit->setPath(path);
	chosenUnit->syncUnit->setMoved(true);

	for (auto i : pathFinder.getAvailablePositions())
	{
		getTile(i)->getSyncTile()->setHighlight(0);
		getTile(i)->getSyncTile()->notifyChange();
	}

	setChosenTile(nullptr);
	setChosenUnit(nullptr);
}
