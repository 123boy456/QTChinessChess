#ifndef CHESSPUSHBUTTON_H
#define CHESSPUSHBUTTON_H

#include <QPushButton>
#include <QString>
#include <QPixmap>
#include <QTimer>
class ChessPushButton : public QPushButton
{
    Q_OBJECT
public:
    ChessPushButton(int x);
    int num;
    QPixmap pix;//用于保存初始图片
    QPixmap pixmap;//用于图片的变化
    void changeIcon();
    QTimer *time;
    int min = 0;
    int max = 2;
    void changefinish();
    void change(QPixmap a);
    bool exist;
    bool keshi;
    bool choose;
    bool eat;
    bool cheakable;
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    int x;
    int y;
signals:
    void event1();
    void event2();
    void event3();

public slots:
};

#endif // CHESSPUSHBUTTON_H
