#include "mainwindow.h"
#include "homepage.h"
#include "gui.h"
#include "admin.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwindow w;
    w.show();


    homepage h;
//    h.show();
    gui g;
//    g.show();
   admin o;
//  o.show();

    return a.exec();
}
