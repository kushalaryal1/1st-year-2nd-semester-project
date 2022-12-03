#include "gui.h"
#include "ui_gui.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include "mainwindow.h"

gui::gui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gui)
{

    ui->setupUi(this);
//   resize(400,400);
//    QPixmap windowBG("C:/Users/dell/Desktop/KUPOOL_FINAL1/images/bg.png");
//    windowBG=windowBG.scaled(1000,1000,Qt::KeepAspectRatio);

//   ui->setupUi(this);

}



void gui::on_signin_clicked(){
    this->close();
    auto login = new mainwindow();
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}


void gui::on_pushbtn_clicked() {
qDebug()<<"yes.";
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
    }else{
        if(ui->firstname->text().isEmpty() ||
         ui->lastname->text().isEmpty() ||
         ui->department->text().isEmpty() ||
         ui->phno->text().isEmpty() ||
         ui->email->text().isEmpty() ||
         ui->password->text().isEmpty() ||
         ui->username->text().isEmpty())
        {
         QMessageBox::warning(this, "Empty", "One or more fields empty");
    }else{

         QSqlQuery qry(db);
         qDebug() << "CAME UPTO HERE";
     // qry.prepare("INSERT INTO Kupool (firstname, lastname, department, phonenumber, email, password, username) VALUES('"+firstname+"', '"+lastname+"','"+department+"', '"+phonenumber+"', '"+email+"', '"+password+"', '"+username+"')");

        QString sql_query = "INSERT INTO Kupool (firstname, lastname, department, phonenumber, email, password, username) VALUES('"+firstname+"', '"+lastname+"','"+department+"', '"+phonenumber+"', '"+email+"', '"+password+"', '"+username+"')";
        qDebug() << sql_query;
        qry.prepare(sql_query);
         if(qry.exec()){
             qDebug() << "The query was executed";
             QMessageBox::information(this, "Inserted", "Succesfully Registered. Proceed to Login");
            this->close();
             auto login_page = new mainwindow();
             login_page->show();
             db.close();
             db.removeDatabase(db.connectionName());
        }else{
             QMessageBox::information(this, "Not Connected", "Database is Not connected");
         }
        }
    }
}





gui::~gui(){
    delete ui;
}







