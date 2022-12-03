#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "homepage.h"
#include "gui.h"
#include "ui_homepage.h"
#include "QPixmap"
#include "QMessageBox"
#include "QDesktopServices"
#include <QSqlDatabase>
#include <QSqlQuery>
#include "admin.h"
mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    resize(630,420);
    QPixmap passicon("C:/Users/dell/Desktop/KUPOOL_FINAL1/images/lock.png");
    ui->loginPasswordIcon->setPixmap(passicon.scaled(30,30,Qt::KeepAspectRatio));

    QPixmap usernameicon("C:/Users/dell/Desktop/KUPOOL_FINAL1/images/user_green.png");
    ui->loginUsernameIcon->setPixmap(usernameicon.scaled(30,30,Qt::KeepAspectRatio));

    QPixmap kuicon("C:/Users/dell/Desktop/KUPOOL_FINAL1/images/icon.png");
    ui->icon->setPixmap(kuicon.scaled(80,80,Qt::KeepAspectRatio));

    QPixmap ku_logo("C:/Users/dell/Desktop/KUPOOL_FINAL1/images/KU_LOGO.png");
    ui->KULOGO->setPixmap(ku_logo.scaled(80,80,Qt::KeepAspectRatio));

    QPixmap windowBG("C:/Users/dell/Desktop/KUPOOL_FINAL1/images/bg.png");
    windowBG = windowBG.scaled(650,700,Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, windowBG);
    this->setPalette(palette);
}

mainwindow::~mainwindow()
{
    delete ui;
}


void mainwindow::on_loginButton_clicked() {
    mydb = QSqlDatabase::addDatabase("QSQLITE", "MAIN_WINDOW");
    mydb.setDatabaseName("C:/Users/dell/Desktop/KUPOOL_FINAL1/Kupool.db");

    QString username = ui->loginUsernameInput->text();
    QString password = ui->loginPasswordInput->text();
    if(username=="" || password== ""){
        QMessageBox::warning(this,"Invalid","Invalid username or password!");
    }

    if(!mydb.open()){
         qDebug()<<"Failed to open the database.";
    }else{
        QSqlQuery qry(mydb);
        QString sql_query = "SELECT * FROM Kupool WHERE username = '" + username + "' AND password='"+password+ "'";
        qDebug() << sql_query;

        if(qry.exec(sql_query)){
           int count = 0;
            while(qry.next()){
                  count++;
            }

            if(count<1)
                QMessageBox::warning(this,"Invalid","username and password is not correct!");
            if(count == 1){
                mydb.close();
                mydb.removeDatabase(mydb.connectionName());
                this->close();
                auto admin_page = new homepage();
                admin_page->setAttribute(Qt::WA_DeleteOnClose);
                admin_page->show();
        }

            if(username=="admin" && password=="admin"){
                this->close();
                auto admin_page = new admin();
                admin_page->setAttribute(Qt::WA_DeleteOnClose);
                admin_page->show();
            }else{
            qDebug () << "BHITRA AAYINA";
        }
    }
}
}
void mainwindow::on_forgot_password_clicked()
{
    QMessageBox::warning(this,"ERROR","Contact the administration!");
}


void mainwindow::on_createAccount_clicked()
{

    gui file;
    file.setModal(true);
        close();
    file.exec();
}


//
////     if((username == "admin") && (password == "admin" ))
////     {
////         this->close();
////         auto admin_page = new homepage();
////         admin_page->setAttribute(Qt::WA_DeleteOnClose);
////         admin_page->show();
////     }
//    QSqlQuery qry(Kupool);
//    QString sql_query = "SELECT * FROM Kupool WHERE username = '" + username + "' AND password='"+password+ "'";
//    if(qry.exec(sql_query)){
//       int count = 0;
//        while(qry.next()){
//              count++;
//        }
//        if(count == 1)
//            this->close();
//            auto admin_page = new homepage();
//            admin_page->setAttribute(Qt::WA_DeleteOnClose);
//            admin_page->show();
//        if(count>1)
//            ui->loginUsernameInput->setText("Duplicate username and password!");
//        if(count<1)
//            ui->loginUsernameInput->setText("username and password is notcorrect!");
//    }else{
//        qDebug () << "BHITRA AAYINA";
//    }
//
