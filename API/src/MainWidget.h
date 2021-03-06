#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWidget.h"
#include "../core/Game.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = Q_NULLPTR);
private:
    Ui::MainWidgetClass ui;
};
