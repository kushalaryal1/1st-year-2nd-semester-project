#include "register.h"
#include "ui_register.h"


register::register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::register)
{
    ui->setupUi(this);
}

register::~register()
{
delete ui;
}
