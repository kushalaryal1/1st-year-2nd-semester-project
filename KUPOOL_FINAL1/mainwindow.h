#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

private slots:
    void on_loginButton_clicked();

    void on_forgot_password_clicked();

    void on_createAccount_clicked();

private:
    Ui::mainwindow *ui;
};
#endif // MAINWINDOW_H
