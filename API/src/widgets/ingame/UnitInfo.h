#ifndef WIDGETS__INGAME__UNIT_INFO_H
#define WIDGETS__INGAME__UNIT_INFO_H

#include <QWidget>
#include "ui_UnitInfo.h"

#include "../../graphic/Sprite.h"

class UnitInfo : public QWidget
{
	Q_OBJECT

public:
	UnitInfo(QWidget *parent = Q_NULLPTR);
	~UnitInfo();

	void setUnit(Sprite *unit);

public slots:
	void tryUseSkill1() { emit useSkill(0); }
	void tryUseSkill2() { emit useSkill(1); }
	void tryUseSkill3() { emit useSkill(2); }
	void pressMove();

signals:
	void useSkill(int index);

private:
	Ui::UnitInfo ui;
	Sprite *unit;
	void updateData();
};

#endif // !WIDGETS__INGAME__UNIT_INFO_H