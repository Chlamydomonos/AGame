#include "Water.h"

Water::Water() : TileDefination("agame:water")
{
	loadPixmap("1", ":/pixmaps/water1.png");
	loadPixmap("2", ":/pixmaps/water2.png");
	loadPixmap("3", ":/pixmaps/water3.png");
	createAnimation(
		"default",
		{
			createAnimationFrame("1", 200),
			createAnimationFrame("2", 200),
			createAnimationFrame("3", 200)
		},
		-1
	);
	setDefaultAnimation("default");
}
