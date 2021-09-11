#ifndef WIDGETS__START_WIDGET_H
#define WIDGETS__START_WIDGET_H

#include <QWidget>
#include "ui_StartWidget.h"

class StartWidget : public QWidget
{
	Q_OBJECT

public:
	StartWidget(QWidget *parent = Q_NULLPTR);
	~StartWidget();

private:
	Ui::StartWidget ui;
};

#endif // !WIDGETS__START_WIDGET_H