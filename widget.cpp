#include "widget.h"
#include "ui_widget.h"
#include <QIcon>
#include <QPainter>
#include "mypushbutton.h"
#include<QDebug>
#include <QTimer>
#include <QPixmap>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(1200,700);
    setWindowIcon(QIcon(":/image/table.jpg"));
    setWindowTitle("象棋明暗棋");

    choosescene = new ChooseScene;
    connect(choosescene,&ChooseScene::chooseBack,this,[=](){
        choosescene->hide();
        this->show();
       });

    MyPushButton *startbtn = new MyPushButton(":/image/start.jpg");
    startbtn->setParent(this);
    startbtn->move(this->width()*0.5-startbtn->width()*0.5,this->height()*0.65);
    connect(startbtn,&QPushButton::clicked,[=](){
        startbtn->jump1();
        startbtn->jump2();

        QTimer::singleShot(400,this,[=](){
            this->hide();
            choosescene->show();
        });
    });
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/background.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
