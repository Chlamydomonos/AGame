#ifndef MAP__SERVER_MAP_H
#define MAP__SERVER_MAP_H

#include <QObject>
#include <QMap>
#include "TileDefination.h"
#include "../unit/UnitDefination.h"
#include "ServerMapPrototype.h"
#include "../util/PathFinder.h"

class ServerMap : public QObject, public ItemWithPrototype<ServerMap, ServerMapPrototype>
{
	Q_OBJECT
private:
	friend class ServerTile;
	friend class SyncMap;
	friend class ServerUnit;
	friend class MapDefination;
	QMap<long long, ServerTile *> tiles;
	QMap<long long, ServerUnit *> units;
	ServerUnit *chosenUnit;
	ServerTile *chosenTile;
	SyncMap *syncMap;
	PathFinder pathFinder;
public:
	ServerMap(const ServerMapPrototype *prototype) : ItemWithPrototype(prototype), syncMap(nullptr), pathFinder(this) {}

	void bindSyncMap(SyncMap *syncMap);
	SyncMap *getSyncMap() const { return syncMap; }

	ServerTile *getTile(short x, short y, short z);
	ServerTile *getTile(unsigned long long index);

	ServerUnit *getUnit(short x, short y, short z);
	ServerUnit *getUnit(unsigned long long index);

	ServerUnit *getChosenUnit() { return chosenUnit; }
	ServerTile *getChosenTile() { return chosenTile; }
	void setChosenTile(ServerTile *tile) { chosenTile = tile; }
	void setChosenUnit(ServerUnit *unit) { chosenUnit = unit; }

	PathFinder *getPathFinder() { return &pathFinder; }
};

#endif // !MAP__SERVER_MAP_H
