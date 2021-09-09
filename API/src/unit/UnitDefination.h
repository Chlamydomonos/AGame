#ifndef UNIT__UNIT_DEFINATION_H
#define UNIT__UNIT_DEFINATION_H

#include "../memory/registry/RegistryEntry.h"

#include "../graphic/Sprite.h"

#include "ServerUnitPrototype.h"
#include "SyncUnitPrototype.h"
#include "ClientUnitPrototype.h"
#include "ServerUnit.h"
#include "SyncUnit.h"
#include "Skill.h"

class UnitDefination : public QObject, public RegistryEntry<UnitDefination>, public ServerUnitPrototype, public SyncUnitPrototype, public ClientUnitPrototype
{
	Q_OBJECT
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
	Skill *skills[3];
public:
	UnitDefination(const QString &name) : RegistryEntry(name){}
	ServerUnit *createServerUnit(int x, int y, int z) const;
	Sprite *createClientUnit(SyncUnit *unit) const;

	double getMaxHP(int level) { return maxHP[level]; }
	double getMaxMP(int level) { return maxMP[level]; }
	double getAtk(int level) { return atk[level]; }
	double getDef(int level) { return def[level]; }
	double getRes(int level) { return res[level]; }
	int getMov(int level) { return mov[level]; }
	int getPrice() { return price; }
	int getExp(int fromLevel) { return exp[fromLevel]; }
	int getDeathExp(int level) { return deathExp[level]; }
};

#endif // !UNIT__UNIT_DEFINATION_H
