#ifndef INFORMATION_H
#define INFORMATION_H
#include <QWidget>
#include<QSqlDatabase>
#include<QDebug>
#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class information;
}

class information : public QDialog
{
    Q_OBJECT

public:
    explicit information(QWidget *parent = nullptr);
    ~information();

private slots:
    void on_pbtn_clicked();

private:
    Ui::information *ui;
};

#endif // INFORMATION_H
