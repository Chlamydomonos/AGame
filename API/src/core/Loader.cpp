#include "Loader.h"

#include "../tiles/Ground.h"
#include "../tiles/Water.h"

#include "../skills/TestSkill.h"

#include "../units/Soldier.h"

#include "../maps/Test.h"

void Loader::load()
{
	new Ground();
	new Water();

	new TestSkill();

	new Soldier();

	new Test();
}
