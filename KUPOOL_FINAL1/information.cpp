#include "information.h"
#include "ui_information.h"
#include "admin.h"
information::information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::information)
{
    ui->setupUi(this);

QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
db.setDatabaseName("C:/Users/dell/Desktop/KUPOOL_FINAL1/Kupool.db");
if(db.open())
{
    QSqlQueryModel *modal =new QSqlQueryModel();

    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("select * from Kupool");
    qry->exec();
    modal->setQuery(*qry);
    ui->datatable->setModel(modal);
    qDebug()<<(modal->rowCount());
}
}


information::~information()
{
    delete ui;
}




void information::on_pbtn_clicked()
{
    this->close();
    auto login = new admin();
    login->setAttribute(Qt::WA_DeleteOnClose);
    login->show();
}

