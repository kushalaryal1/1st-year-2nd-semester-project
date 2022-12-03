#include "reg.h"
#include "mainwindow.h"
#include "ui_reg.h"
#include <QDebug>
#include"QMessageBox"//;
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QDialog>
reg::reg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reg)
{
    ui->setupUi(this);
}






void reg::on_pushbtn_clicked()
{
    db = QSqlDatabase::addDatabase("QSQLITE", "GUI");
   db.setDatabaseName("C:/Users/dell/Desktop/KUPOOL_FINAL1/Kupool.db");
    db.open();
    QString firstname = ui->firstname->text();
    QString lastname = ui->lastname->text();
    QString department = ui->department->text();
    QString phonenumber = ui->phno->text();
    QString email = ui->email->text();
    QString password = ui->password->text();
    QString username  = ui->username->text();
    if(!db.open()){
     ui->firstname->setText("Failed to open the database");
    }
    QSqlQuery qry, qry1;

     if (ui->firstname->text().isEmpty() ||
         ui->lastname->text().isEmpty() ||
         ui->department->text().isEmpty() ||
         ui->phno->text().isEmpty() ||
         ui->email->text().isEmpty() ||
         ui->password->text().isEmpty() ||
         ui->username->text().isEmpty())
            {
         QMessageBox::warning(this, "Empty", "One or more fields empty");
            }
    else{QMessageBox::warning(this, "Empty", "heelo");}

        qry.prepare("INSERT INTO Kupool (firstname, lastname, department, phonenumber, email, password, username) VALUES('"+firstname+"', '"+lastname+"','"+department+"', '"+phonenumber+"', '"+email+"', '"+password+"', '"+username+"')");

        //QString sql_query = "INSERT INTO Kupool VALUES('"+username+"', '"+password+"','"+department+"', '"+phonenumber+"', '"+email+"', '"+firstname+"', '"+lastname+"')";
    // qDebug() << sql_query;
   // qry.prepare(sql_query);

        if(qry1.exec()){
         qDebug() << "The query was executed";

         QMessageBox::information(this, "Inserted", "Succesfully Registered. Proceed to Login");
        this->close();
        auto login_page = new mainwindow();
         login_page->show();
        // db.close();
         //db.removeDatabase(db.connectionName());
    } else {
         QMessageBox::information(this, "Not Connected", "Database is Not connected");
     }
    }


reg::~reg()
{
    delete ui;

}

