#ifndef UNIT__UNIT_DEFINATION_H
#define UNIT__UNIT_DEFINATION_H

#include "../memory/registry/RegistryEntry.h"

#include "../graphic/Sprite.h"

class ServerUnit;
class SyncUnit;

class UnitDefination : public RegistryEntry<UnitDefination>
{
protected:
	double maxHP[3];
	double maxMP[3];
	double atk[3];
	double def[3];
	double res[3];
	int mov[3];
	int price;
	int exp[2];
	int deathExp[3];
public:
	UnitDefination(const QString &name) : RegistryEntry(name){}
};

#endif // !UNIT__UNIT_DEFINATION_H
