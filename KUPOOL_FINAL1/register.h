#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>

namespace Ui {
class register;
}

class register : public QDialog
{
    Q_OBJECT

public:
    explicit register(QWidget *parent = nullptr);
    ~register();

private:
    Ui::register *ui;
};

#endif // REGISTER_H
