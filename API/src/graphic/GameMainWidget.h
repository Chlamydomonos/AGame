#ifndef GRAPHIC__GAME_MAIN_WIDGET_H
#define GRAPHIC__GAME_MAIN_WIDGET_H

#include <QWidget>
#include <QSet>

class Sprite;

class GameMainWidget : public QWidget
{
private:
	QPoint cameraFocus;
	QSet<Sprite *>sprites;
};

#endif // !GRAPHIC__GAME_MAIN_WIDGET_H
