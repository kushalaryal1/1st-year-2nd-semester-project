#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QWidget>
#include<QSqlDatabase>
#include<QDebug>
#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_pbtn_clicked();

    void on_addmore_clicked();

    void on_userbtn_clicked();



    void on_signout_btn_clicked();

private:
    Ui::admin *ui;
};

#endif // ADMIN_H
