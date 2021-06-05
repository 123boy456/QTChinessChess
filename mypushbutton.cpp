#include "mypushbutton.h"
#include <QString>
#include <QPropertyAnimation>
#include <QPixmap>
MyPushButton::MyPushButton(QString normalImg)
{
    this->normalImgPath=normalImg;
    QPixmap pix;
    pix.load(normalImg);
    pix=pix.scaled(pix.width()*0.7,pix.height()*0.7);
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}
void MyPushButton::jump1()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(400);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+8,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}
void MyPushButton::jump2()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(400);
    animation->setStartValue(QRect(this->x(),this->y()+8,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}
