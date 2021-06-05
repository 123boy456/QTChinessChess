#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QString>
#include <QPixmap>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QString normalImg);
    QString normalImgPath;
    void jump1();
    void jump2();


signals:

public slots:
};

#endif // MYPUSHBUTTON_H
