#include "homepage.h"
#include "ui_homepage.h"
#include "QPixmap"
#include "QMessageBox"
#include "mainwindow.h"
homepage::homepage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::homepage)
{
    ui->setupUi(this);
//    QPixmap icon_main("C:/Users/dell/Desktop/KUPOOL_FINAL1/images/icon.png");
//    ui->pool->setPixmap(icon_main.scaled(80,80,Qt::KeepAspectRatio));

//    QPixmap icon_main123("C:/Users/dell/Desktop/KUPOOL_FINAL1/images/KU_logo.png");
//    ui->log_main->setPixmap(icon_main123.scaled(80,80,Qt::KeepAspectRatio));

//    //QPixmap icon_main1("C:/Users/dell/Desktop/KUPOOL_FINAL1/images/icon.png");
//   // ui->label_icons->setPixmap(icon_main1.scaled(200,200,Qt::KeepAspectRatio));

//    QPixmap swimming("C:/Users/dell/Desktop/KUPOOL_FINAL1/images/swimming.png");
//    ui->swimming_icon->setPixmap(swimming.scaled(141,141,Qt::KeepAspectRatio));

//    QPixmap tube1("C:/Users/dell/Desktop/KUPOOL_FINAL1/images/tubenew.png");
//    ui->Tube_icon->setPixmap(tube1.scaled(141,141,Qt::KeepAspectRatio));

//    QPixmap ball1("C:/Users/dell/Desktop/KUPOOL_FINAL1/images/ballnew.png");
//    ui->ball_icon->setPixmap(ball1.scaled(141,141,Qt::KeepAspectRatio));

//    QPixmap lifejacket1("C:/Users/dell/Desktop/KUPOOL_FINAL1/images/lifejacketnew.png");
//    ui->lifejacket_icon->setPixmap(lifejacket1.scaled(141,141,Qt::KeepAspectRatio));



}

homepage::~homepage()
{
    delete ui;
}

void homepage::on_show_graph_btn_clicked()
{
    QMessageBox::warning(this,"Feature","Feature not available!\n Refer to Administrtion!");
}


void homepage::on_export_csv_btn_clicked()
{
     QMessageBox::warning(this,"Successful","Sucessfully purchased!");
}


void homepage::on_abc_clicked()
{
    QString OOP_ee=ui->bline->text();
    int OOP_ee_val=OOP_ee.toInt();
    ui->bline->setText(QString::number(OOP_ee_val+60));
   QString OOP_marks=ui->qtyinput->text();
   int OOP_marks_val=OOP_marks.toInt();
   ui->qtyinput->setText(QString::number(OOP_marks_val+1));

   QString OOP_count=ui->amtinput->text();
   int OOP_count_val=OOP_count.toInt();
   ui->amtinput->setText(QString::number(OOP_count_val+60));



}



void homepage::on_tubepush_clicked()
{
    QString OOP_ee=ui->bline->text();
    int OOP_ee_val=OOP_ee.toInt();
    ui->bline->setText(QString::number(OOP_ee_val+60));
    QString OOP_counts=ui->tqty->text();
    int OOP_counts_val=OOP_counts.toInt();
    ui->tqty->setText(QString::number(OOP_counts_val+1));

    QString OOP_query=ui->tamt->text();
   int OOP_query_val=OOP_query.toInt();
    ui->tamt->setText(QString::number(OOP_query_val+60));

}


void homepage::on_ballpush_clicked()
{
    QString OOP_ee=ui->bline->text();
    int OOP_ee_val=OOP_ee.toInt();
    ui->bline->setText(QString::number(OOP_ee_val+60));
    QString OOP_marked=ui->blabel->text();
    int OOP_marked_val=OOP_marked.toInt();
    ui->blabel->setText(QString::number(OOP_marked_val+1));

    QString OOP_markeds=ui->bamt->text();
   int OOP_markeds_val=OOP_markeds.toInt();
    ui->bamt->setText(QString::number(OOP_markeds_val+60));
}


void homepage::on_lifejacketpush_clicked()
{
    QString OOP_ee=ui->bline->text();
    int OOP_ee_val=OOP_ee.toInt();
    ui->bline->setText(QString::number(OOP_ee_val+60));
    QString OOP_markedss=ui->ljqty->text();
    int OOP_markedss_val=OOP_markedss.toInt();
    ui->ljqty->setText(QString::number(OOP_markedss_val+1));

    QString OOP_markedsss=ui->ljamt->text();
   int OOP_markedsss_val=OOP_markedsss.toInt();
    ui->ljamt->setText(QString::number(OOP_markedsss_val+60));
}


void homepage::on_Dd_clicked()
{
    QString OOP_ee=ui->bline->text();
    int OOP_ee_val=OOP_ee.toInt();
    ui->bline->setText(QString::number(OOP_ee_val=0));
    QString OOP_markedss=ui->ljqty->text();
    int OOP_markedss_val=OOP_markedss.toInt();
    ui->ljqty->setText(QString::number(OOP_markedss_val=0));

    QString OOP_markedsss=ui->ljamt->text();
   int OOP_markedsss_val=OOP_markedsss.toInt();
    ui->ljamt->setText(QString::number(OOP_markedsss_val=0));
    QString OOP_marked=ui->blabel->text();
    int OOP_marked_val=OOP_marked.toInt();
    ui->blabel->setText(QString::number(OOP_marked_val=0));

    QString OOP_markeds=ui->bamt->text();
   int OOP_markeds_val=OOP_markeds.toInt();
    ui->bamt->setText(QString::number(OOP_markeds_val=0));
    QString OOP_counts=ui->tqty->text();
    int OOP_counts_val=OOP_counts.toInt();
    ui->tqty->setText(QString::number(OOP_counts_val=0));

    QString OOP_query=ui->tamt->text();
   int OOP_query_val=OOP_query.toInt();
    ui->tamt->setText(QString::number(OOP_query_val=0));
    QString OOP_marks=ui->qtyinput->text();
    int OOP_marks_val=OOP_marks.toInt();
    ui->qtyinput->setText(QString::number(OOP_marks_val=0));

    QString OOP_count=ui->amtinput->text();
    int OOP_count_val=OOP_count.toInt();
    ui->amtinput->setText(QString::number(OOP_count_val=0));
}


void homepage::on_signout_button_clicked()
{
    this->close();
    auto login = new mainwindow();
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}

