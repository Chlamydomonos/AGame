#ifndef UNIT__CLIENT_UNIT_PROTOTYPE_H
#define UNIT__CLIENT_UNIT_PROTOTYPE_H

#include "../graphic/SpritePrototype.h"

class ClientUnitPrototype : public SpritePrototype
{
public:
	ClientUnitPrototype() : SpritePrototype({ 64, 96 }, 0, { -32, -64 }) {}
};

#endif // !UNIT__CLIENT_UNIT_PROTOTYPE_H
