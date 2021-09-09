#ifndef MAP__CLIENT_TILE_PROTOTYPE_H
#define MAP__CLIENT_TILE_PROTOTYPE_H

#include "../graphic/SpritePrototype.h"

class ClientTilePrototype : public SpritePrototype
{
public:
	ClientTilePrototype() : SpritePrototype({ 120, 100 }, -2, { -60, -50 }) {}
};

#endif // !MAP__CLIENT_TILE_PROTOTYPE_H
