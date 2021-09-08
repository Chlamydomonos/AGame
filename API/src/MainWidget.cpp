#include "MainWidget.h"

#include "graphic/AnimationPrototype.h"
#include "graphic/Animation.h"

#include <QDebug>
#include <time.h>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    AnimationPrototype test(QVector<QPixmap>());
    ui.setupUi(this);
}
