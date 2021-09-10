#include "ServerMapPrototype.h"
#include "ServerMap.h"

ServerMap *ServerMapPrototype::create() const
{
    return new ServerMap(this);
}
