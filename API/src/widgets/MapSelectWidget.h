#ifndef WIDGETS__MAP_SELECT_WIDGET_H
#define WIDGETS__MAP_SELECT_WIDGET_H

#include <QWidget>
#include "ui_MapSelectWidget.h"

class MapSelectWidget : public QWidget
{
	Q_OBJECT

public:
	MapSelectWidget(QWidget *parent = Q_NULLPTR);
	~MapSelectWidget();

private:
	Ui::MapSelectWidget ui;
};

#endif // !WIDGETS_MAP_SELECT_WIDGET_H