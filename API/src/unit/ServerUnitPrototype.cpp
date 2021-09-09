#include "ServerUnitPrototype.h"

#include "ServerUnit.h"

ServerUnit *ServerUnitPrototype::create() const
{
    return new ServerUnit(this);
}
