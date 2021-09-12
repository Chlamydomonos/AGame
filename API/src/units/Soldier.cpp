#include "Soldier.h"

Soldier::Soldier() : UnitDefination("agame:soldier")
{
	maxHP[0] = 10; maxHP[1] = 15; maxHP[2] = 40;
	maxMP[0] = 1; maxMP[1] = 3; maxMP[2] = 5;
	atk[0] = 7; atk[1] = 14; atk[2] = 30;
	def[0] = 0; def[1] = 0; def[2] = 0;
	res[0] = 0; res[1] = 0; res[2] = 0;
	mov[0] = 4; mov[1] = 4; mov[2] = 4;
	price = 5;
	exp[0] = 3; exp[1] = 10;
	deathExp[0] = 1; deathExp[1] = 2; deathExp[2] = 5;

	for (int i = 0; i < 3; i++)
		skills[i] = AllRegistries::getInstance()->getRegistry<Skill>()->get("agame:test");

	for (int i = 0; i < 12; i++)
	{
		loadPixmap("blue" + QString::number(i + 1), ":/pixmaps/soldier_blue/" + QString::number(i + 1) + ".png");
		loadPixmap("red" + QString::number(i + 1), ":/pixmaps/soldier_red/" + QString::number(i + 1) + ".png");
	}

	createAnimation(
		"blue_down",
		{
			createAnimationFrame("blue1", 200),
			createAnimationFrame("blue2", 200),
			createAnimationFrame("blue3", 200)
		},
		-1
	);

	createAnimation(
		"blue_left",
		{
			createAnimationFrame("blue4", 200),
			createAnimationFrame("blue5", 200),
			createAnimationFrame("blue5", 200)
		},
		-1
	);

	createAnimation(
		"blue_right",
		{
			createAnimationFrame("blue7", 200),
			createAnimationFrame("blue8", 200),
			createAnimationFrame("blue9", 200)
		},
		-1
	);

	createAnimation(
		"blue_up",
		{
			createAnimationFrame("blue10", 200),
			createAnimationFrame("blue11", 200),
			createAnimationFrame("blue12", 200)
		},
		-1
	);

	createAnimation(
		"blue_default",
		{
			createAnimationFrame("blue2")
		},
		-1
	);

	createAnimation(
		"red_down",
		{
			createAnimationFrame("red1", 200),
			createAnimationFrame("red2", 200),
			createAnimationFrame("red3", 200)
		},
		-1
	);

	createAnimation(
		"red_left",
		{
			createAnimationFrame("red4", 200),
			createAnimationFrame("red5", 200),
			createAnimationFrame("red5", 200)
		},
		-1
	);

	createAnimation(
		"red_right",
		{
			createAnimationFrame("red7", 200),
			createAnimationFrame("red8", 200),
			createAnimationFrame("red9", 200)
		},
		-1
	);

	createAnimation(
		"red_up",
		{
			createAnimationFrame("red10", 200),
			createAnimationFrame("red11", 200),
			createAnimationFrame("red12", 200)
		},
		-1
	);

	createAnimation(
		"red_default",
		{
			createAnimationFrame("red2")
		},
		-1
	);

	setDefaultAnimation("blue_default");
}
