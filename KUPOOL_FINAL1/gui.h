#ifndef GUI_H
#define GUI_H

#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
namespace Ui {
class gui;
}

class gui : public QDialog
{
    Q_OBJECT

public:
    explicit gui(QWidget *parent = nullptr);
    QSqlDatabase db;
    ~gui();


private slots:
    void on_pushbtn_clicked();

    void on_signin_clicked();

    void on_pushButton_clicked();

private:
    Ui::gui *ui;
};

#endif // GUI_H
