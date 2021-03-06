#ifndef UNIT__SKILL_H
#define UNIT__SKILL_H

#include "../memory/registry/RegistryEntry.h"
#include "../map/ServerTile.h"

class ServerUnit;

class Skill : public RegistryEntry<Skill>
{
protected:
	int range;
	int aoeRange;
	int cd;
public:
	Skill(const QString &name) : RegistryEntry(name) {}
	virtual void use(ServerUnit *from, ServerTile *target) = 0;

	int getRange() const { return range; }
	int getAoeRange() const { return aoeRange; }
	int getCd() const { return cd; }
};

#endif // !UNIT__SKILL_H
