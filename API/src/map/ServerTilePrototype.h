#ifndef MAP__SERVER_TILE_PROTOTYPE_H
#define MAP__SERVER_TILE_PROTOTYPE_H

#include "../util/Prototype.h"

class ServerTile;
class TileDefination;

class ServerTilePrototype : public Prototype<ServerTile>
{
public:
	ServerTilePrototype() {}

	virtual ServerTile *create() const override final;
};

#endif // !MAP__SERVER_TILE_PROTOTYPE_H
