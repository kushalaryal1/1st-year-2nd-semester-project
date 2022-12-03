#ifndef DD_H
#define DD_H

#include <QDialog>

namespace Ui {
class dd;
}

class dd : public QDialog
{
    Q_OBJECT

public:
    explicit dd(QWidget *parent = nullptr);
    ~dd();

private:
    Ui::dd *ui;
};

#endif // DD_H
