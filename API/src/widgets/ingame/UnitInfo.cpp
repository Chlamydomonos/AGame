#include "UnitInfo.h"
#include "../../unit/UnitDefination.h"
#include "../../core/Game.h"

UnitInfo::UnitInfo(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QFile style(":/stylesheets/UnitInfo.qss");
	style.open(QIODevice::ReadOnly);
	setStyleSheet(style.readAll());
	connect(ui.useSkill1, &QPushButton::pressed, this, &UnitInfo::tryUseSkill1);
	connect(ui.useSkill2, &QPushButton::pressed, this, &UnitInfo::tryUseSkill2);
	connect(ui.useSkill3, &QPushButton::pressed, this, &UnitInfo::tryUseSkill3);
	connect(ui.move, &QPushButton::pressed, this, &UnitInfo::pressMove);
}

UnitInfo::~UnitInfo()
{
}

void UnitInfo::setUnit(Sprite *unit)
{
	this->unit = unit;
	updateData();
}

void UnitInfo::updateData()
{
	auto sync = (SyncUnit *)(unit->getDataMap()["sync"].toInt());
	auto def = dynamic_cast<const UnitDefination *>(sync->getPrototype());

	ui.name->setText(tr(def->getName().toLatin1()));

	ui.hpBar->setMinimum(0);
	ui.hpBar->setMaximum(def->getMaxHP(sync->getLevel()));
	ui.hpBar->setValue(sync->getHp());

	ui.mpBar->setMinimum(0);
	ui.mpBar->setMaximum(def->getMaxMP(sync->getLevel()));
	ui.mpBar->setValue(sync->getMp());

	ui.expBar->setMinimum(0);
	ui.expBar->setMaximum(sync->getLevel() == 2 ? 0 : def->getExp(sync->getLevel()));
	ui.expBar->setValue(sync->getExp());

	ui.level->setText(QString::number(sync->getLevel()));
	ui.skill1->setText(tr(def->getSkill(0)->getName().toLatin1()));
	ui.skill2->setText(tr(def->getSkill(1)->getName().toLatin1()));
	ui.skill3->setText(tr(def->getSkill(2)->getName().toLatin1()));

	ui.useSkill1->setEnabled(true);
	ui.useSkill2->setEnabled(true);
	ui.useSkill3->setEnabled(true);

	if (sync->getLevel() < 2 || sync->getCd3())
		ui.useSkill3->setEnabled(false);
	if (sync->getLevel() < 1 || sync->getCd2())
		ui.useSkill2->setEnabled(false);

	if (sync->getCd1())
		ui.useSkill1->setEnabled(false);
	if (sync->getPlayer() != Game::getInstance()->getClient()->getPlayer())
	{
		ui.useSkill1->setEnabled(false);
		ui.useSkill2->setEnabled(false);
		ui.useSkill3->setEnabled(false);
	}

	ui.move->setEnabled(sync->getPlayer() == Game::getInstance()->getClient()->getPlayer() && !sync->getMoved());
}

void UnitInfo::pressMove()
{
	auto sync = (SyncUnit *)(unit->getDataMap()["sync"].toInt());
	sync->setMovePressed(true);
	this->hide();
	sync->notifyChange();
}
