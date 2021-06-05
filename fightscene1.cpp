#include "fightscene1.h"
#include "ui_fightscene1.h"

fightscene1::fightscene1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fightscene1)
{
    ui->setupUi(this);
}

fightscene1::~fightscene1()
{
    delete ui;
}
