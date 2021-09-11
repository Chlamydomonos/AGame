#include "Soldier.h"

Soldier::Soldier() : UnitDefination("soldier")
{
	for (int i = 0; i < 12; i++)
		loadPixmap("blue" + QString::number(i + 1), ":/pixmaps/solder_blue/" + QString::number(i + 1) + ".png");

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
}
