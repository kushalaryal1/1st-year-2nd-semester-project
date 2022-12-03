#include "admin.h"
#include "mainwindow.h"
#include "ui_admin.h"
#include <QDebug>
#include "QMessageBox"
#include "information.h"
admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_pbtn_clicked()
{
    qDebug()<<"yes.";
}


void admin::on_addmore_clicked()
{
    QMessageBox::information(this,"Add More","Edit from Qt.");
}





void admin::on_userbtn_clicked()
{

    this->close();
    auto login = new information();
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}


void admin::on_signout_btn_clicked()
{
   this->close();
    auto logout =new mainwindow();
    logout->setAttribute(Qt::WA_DeleteOnClose);
    logout->show();
}

