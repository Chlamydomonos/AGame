#ifndef GRAPHIC__SPRITE_H
#define GRAPHIC__SPRITE_H

#include "AnimationFrameGroup.h"

#include <QSet>
#include <QPoint>
#include <QSize>
#include <QPainter>
#include <QQueue>

class SpritePrototype;

class Sprite
{
private:
	friend class GameMainWidget;
	friend class SpritePrototype;
	Sprite *parent;
	QSet<Sprite *> children;
	SpritePrototype *prototype;
	QPoint position;
	QPoint actualPosition;
	QSize size;
	int zOrder;
	QQueue<AnimationFrameGroup *> animationFrameGroups;
	bool visible;
	int time;
	AnimationFrame currentFrame;

	Sprite(SpritePrototype *_prototype, QSize _size, int _zOrder, QPoint _position = { 0, 0 },
		Sprite *_parent = nullptr, bool _visible = true);

	~Sprite();

	void render(QPainter *painter);

	bool onMouseHoverStart(bool leftButtonPressed, bool rightButtonPressed);
	bool onMouseHoverEnd(bool leftButtonPressed, bool rightButtonPressed);
	bool onMouseButtonPressed(bool isLeft);
	bool onMouseButtonReleased(bool isLeft);
public:
	QPoint getPosition() const { return position; }
	QSize getSize() const { return size; }
	int getZOrder() const { return zOrder; }
	Sprite *getParent() { return parent; }
	QSet<Sprite *> &getChildren() { return children; }
	bool isVisible() { return visible; }

	void setPosition(const QPoint &position) { this->position = position; }
	void setSize(const QSize &size) { this->size = size; }
	void setVisible(bool visible) { this->visible = visible; }
	void setParent(Sprite *parent);
	void show() { visible = true; }
	void hide() { visible = false; }

	struct AnimationFrameGroupInfo
	{
		const QString &name;
		bool isLoop;
		bool operator==(const AnimationFrameGroupInfo &other)
		{
			return name == other.name && isLoop == other.isLoop;
		}
	};

	void enqueueAnimationFrameGroup(const QString &name, bool isLoop);
	void enqueueAnimationFrameGroup(AnimationFrameGroupInfo info);
	void dequeueAnimationFrameGroup();

	bool isAnimationFrameGroupQueueEmpty() { return animationFrameGroups.isEmpty(); }
    AnimationFrameGroupInfo lastAnimationFrameGroup();
};

#endif // !GRAPHIC__SPRITE_H
