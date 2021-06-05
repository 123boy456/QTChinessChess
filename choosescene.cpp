#include "choosescene.h"
#include <QIcon>
#include <QPushButton>
#include <QPainter>
#include <QTimer>
#include "fightscene.h"
#include <QPixmap>
ChooseScene::ChooseScene(QWidget *parent) : QWidget(parent)
{
     setFixedSize(1000,500);
     this->setWindowIcon(QIcon(":/image/table.jpg"));
     this->setWindowTitle("选择对战方式");
     b1.setText("玩家对战");
     b3.setText("返回");
     b1.setParent(this);
     b3.setParent(this);
     b1.move(350,200);
     b3.move(900,467);
     b1.resize(300,100);
     b3.resize(100,33);

     connect(&b3,&QPushButton::clicked,[=](){
         QTimer::singleShot(500,this,[=](){
         this->hide();
         emit chooseBack();
         });
     });
         fightscene1 = new fightscene;
     connect(&b1,&QPushButton::clicked,[=](){
         this->hide();
         fightscene1->show();
     });

}
void ChooseScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/background3.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

