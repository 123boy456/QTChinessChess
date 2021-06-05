#include "chesspushbutton.h"
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>
#include <QPushButton>
#include <QPixmap>
ChessPushButton::ChessPushButton(int x)
{
    num = x;
    if(num > 10)
        cheakable = true;
    else
        cheakable = false;

    QPixmap pix1;
    pix1.load(":/image/BB.jpg");
    QPixmap pix2;
    pix2.load(":/image/BS.jpg");
    QPixmap pix3;
    pix3.load(":/image/BX.jpg");
    QPixmap pix4;
    pix4.load(":/image/BC.jpg");
    QPixmap pix5;
    pix5.load(":/image/BH.jpg");
    QPixmap pix6;
    pix6.load(":/image/BP.jpg");
    QPixmap pix7;
    pix7.load(":/image/BZ.jpg");
    QPixmap pix8;
    pix8.load(":/image/Hshuai.jpg");
    QPixmap pix9;
    pix9.load(":/image/HS.jpg");
    QPixmap pix10;
    pix10.load(":/image/HX.jpg");
    QPixmap pix11;
    pix11.load(":/image/HC.jpg");
    QPixmap pix12;
    pix12.load(":/image/HM.jpg");
    QPixmap pix13;
    pix13.load(":/image/HP.jpg");
    QPixmap pix14;
    pix14.load(":/image/HB.jpg");
    if(num == 1)
        pix=pix7;
    if(num == 2)
        pix=pix6;
    if(num == 3)
        pix=pix5;
    if(num == 4)
        pix=pix4;
    if(num == 5)
        pix=pix3;
    if(num == 6)
        pix=pix2;
    if(num == 7)
        pix=pix1;
    if(num == 11)
        pix=pix14;
    if(num == 12)
        pix=pix13;
    if(num == 13)
        pix=pix12;
    if(num == 14)
        pix=pix11;
    if(num == 15)
        pix=pix10;
    if(num == 16)
        pix=pix9;
    if(num == 17)
        pix=pix8;
    //棋子图片的初始化
    pixmap = pix;
    pixmap=pixmap.scaled(pixmap.width()*1.3,pixmap.height()*1.3);
    this->setIcon(pixmap);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushbutton{border:0px}");
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));

    exist = false;//默认不存在
    keshi = false;//默认不可视
    choose = false;//默认未选中
    eat = false;//默认不可吃


    //图片选中时的图片变化的实现
    time = new QTimer(this);
    connect(time,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str;
        if(num == 1)
            str = QString(":/image/BZchange%1").arg(min++);
        if(num == 2)
            str = QString(":/image/BPchange%1").arg(min++);
        if(num == 3)
            str = QString(":/image/BHchange%1").arg(min++);
        if(num == 4)
            str = QString(":/image/BCchange%1").arg(min++);
        if(num == 5)
            str = QString(":/image/BXchange%1").arg(min++);
        if(num == 6)
            str = QString(":/image/BSchange%1").arg(min++);
        if(num == 7)
            str = QString(":/image/BBchange%1").arg(min++);
        if(num == 11)
            str = QString(":/image/HBchange%1").arg(min++);
        if(num == 12)
            str = QString(":/image/HPchange%1").arg(min++);
        if(num == 13)
            str = QString(":/image/HMchange%1").arg(min++);
        if(num == 14)
            str = QString(":/image/HCchange%1").arg(min++);
        if(num == 15)
            str = QString(":/image/HXchange%1").arg(min++);
        if(num == 16)
            str = QString(":/image/HSchange%1").arg(min++);
        if(num == 17)
            str = QString(":/image/Hshuaichange%1").arg(min++);
        pix.load(str);
        pix=pix.scaled(pix.width()*1.3,pix.height()*1.3);
        this->setIcon(pix);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushbutton{border:0px}");
        this->setIconSize(QSize(pix.width(),pix.height()));

        if(this->min>this->max)
            this->min = 0;
        });


}

void ChessPushButton::changeIcon()
{
    time->start(150);
}

void ChessPushButton::changefinish()
{
    time->stop();
    this->setIcon(pixmap);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushbutton{border:0px}");
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));

}

void ChessPushButton::change(QPixmap a)
{
    QPixmap  pixmap1 = a;
    pixmap1=pixmap1.scaled(pixmap1.width()*1.3,pixmap1.height()*1.3);
    this->setIcon(pixmap1);
    this->setFixedSize(pixmap1.width(),pixmap1.height());
    this->setStyleSheet("QPushbutton{border:0px}");
    this->setIconSize(QSize(pixmap1.width(),pixmap1.height()));
}

void ChessPushButton::mousePressEvent(QMouseEvent *event)
{
    if(this->cheakable == false)
    {
        return;
    }
    else
    {
        if(event->button() == Qt::RightButton)
            emit event2();
        if(event->button() == Qt::LeftButton)
            emit event1();
    }

}
void ChessPushButton::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        emit event3();
}

