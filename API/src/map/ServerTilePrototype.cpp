#include "ServerTilePrototype.h"
#include "ServerTile.h"

ServerTile *ServerTilePrototype::create() const
{
    return new ServerTile(this);
}
