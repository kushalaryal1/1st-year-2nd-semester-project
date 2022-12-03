#include "dd.h"
#include "ui_dd.h"

dd::dd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dd)
{
    ui->setupUi(this);
}

dd::~dd()
{
    delete ui;
}
