#ifndef UNIT__UNIT_PROTOTYPE_H
#define UNIT__UNIT_PROTOTYPE_H

#include "../memory/registry/RegistryEntry.h"
#include <QObject>

class UnitPrototype : public QObject, public RegistryEntry<UnitPrototype>
{
	Q_OBJECT
};

#endif // !UNIT__UNIT_PROTOTYPE_H
