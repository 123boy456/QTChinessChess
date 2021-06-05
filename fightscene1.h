#ifndef FIGHTSCENE1_H
#define FIGHTSCENE1_H

#include <QWidget>

namespace Ui {
class fightscene1;
}

class fightscene1 : public QWidget
{
    Q_OBJECT

public:
    explicit fightscene1(QWidget *parent = nullptr);
    ~fightscene1();

private:
    Ui::fightscene1 *ui;
};

#endif // FIGHTSCENE1_H
