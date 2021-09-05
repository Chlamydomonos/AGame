#ifndef GRAPHIC__GAME_MAIN_WIDGET_H
#define GRAPHIC__GAME_MAIN_WIDGET_H

#include "Sprite.h"
#include <QMap>

class GameMainWidget
{
private:
	QMap<int, Sprite *> spriteRoots;
};

#endif // !GRAPHIC__GAME_MAIN_WIDGET_H
