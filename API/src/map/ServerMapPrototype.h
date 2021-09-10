#ifndef MAP__SERVER_MAP_PROTOTYPE_H
#define MAP__SERVER_MAP_PROTOTYPE_H

#include "../util/Prototype.h"

class ServerMap;

class ServerMapPrototype : public Prototype<ServerMap>
{
protected:
	virtual ServerMap *create() const override final;
};

#endif // !MAP__SERVER_MAP_PROTOTYPE_H
