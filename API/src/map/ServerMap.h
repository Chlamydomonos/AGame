#ifndef MAP__SERVER_MAP_H
#define MAP__SERVER_MAP_H

#include <QMap>

class ServerMap
{
private:
	friend class ServerTile;
	friend class SyncMap;
	QMap<long long, ServerTile *> tiles;
public:
	ServerTile *getTile(int x, int y, int z) { return tiles[(((long long)x) << 4) | (((long long)y) << 2) | ((long long)z)]; }
	ServerTile *getTile(long long index) { return tiles[index]; }
};

#endif // !MAP__SERVER_MAP_H
