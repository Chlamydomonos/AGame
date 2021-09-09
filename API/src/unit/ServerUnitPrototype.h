#ifndef UNIT__SERVER_UNIT_PROTOTYPE_H
#define UNIT__SERVER_UNIT_PROTOTYPE_H

#include "../util/Prototype.h"

class ServerUnit;

class ServerUnitPrototype : public Prototype<ServerUnit>
{
public:
	ServerUnitPrototype() {}
	virtual ServerUnit *create() const override;
};

#endif // !UNIT__SERVER_UNIT_PROTOTYPE_H
