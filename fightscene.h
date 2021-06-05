#ifndef FIGHTSCENE_H
#define FIGHTSCENE_H

#include <QWidget>
#include <QLabel>
#include "chesspushbutton.h"
#include "mypushbutton.h"
#include <QPixmap>
class fightscene : public QWidget
{
    Q_OBJECT
public:
    explicit fightscene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ChessPushButton *button = NULL;
    MyPushButton *coverybutton = NULL;
    QPushButton b2;
    QLabel *turn;
    QLabel *redwin;
    QLabel *blackwin;
    QLabel *heqi;
    ChessPushButton *btn[4][8];
    QPixmap pix0;
    QPixmap pix1;
    QPixmap pix2;
    QPixmap pix3;
    QPixmap pix4;
    QPixmap pix5;
    QPixmap pix6;
    QPixmap pix7;
    QPixmap pix8;
    QPixmap pix9;
    QPixmap pix10;
    QPixmap pix11;
    QPixmap pix12;
    QPixmap pix13;
    QPixmap pix14;
    QPixmap pix15;
    QPixmap pix16;
    QPixmap pix17;
    QPixmap pix18;
    QPixmap pix19;
    QPixmap judge(int x);
    int x;
    int y;
    QPushButton *btncovery[4][8];
    QLabel *dead;
    QLabel *mudi[4][8];
    QPushButton *b;
    int bushu = 0;
    int remainred = 0;
    int remainblack = 0;
    bool which;



signals:
    void chooseback();

public slots:
};

#endif // FIGHTSCENE_H
