#include "Ground.h"

Ground::Ground() : TileDefination("agame:ground")
{
	walkable = false;
	loadPixmap("default", ":/pixmaps/ground.png");
	loadPixmap("red", ":/pixmaps/ground_red.png");
	loadPixmap("green", ":/pixmaps/green.png");
	createAnimation("default", { createAnimationFrame("default") }, -1);
	createAnimation("red", { createAnimationFrame("red") }, -1);
	createAnimation("green", { createAnimationFrame("green") }, -1);
	setDefaultAnimation("default");
}
