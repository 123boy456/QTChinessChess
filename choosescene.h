#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include <QWidget>
#include <QPushButton>
#include "fightscene.h"
#include <QPixmap>
class ChooseScene : public QWidget
{
    Q_OBJECT
public:
    explicit ChooseScene(QWidget *parent = nullptr);
    QPushButton b1;
    QPushButton b2;
    QPushButton b3;
    void paintEvent(QPaintEvent *);
    fightscene *fightscene1 = NULL;

signals:
    void chooseBack();

public slots:
};

#endif // CHOOSESCENE_H
