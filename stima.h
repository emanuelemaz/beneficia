#ifndef STIMA_H
#define STIMA_H

#include <QDialog>
#include "types.h"

namespace Ui {
class Stima;
}

class Stima : public QDialog
{
    Q_OBJECT

public:
    explicit Stima(Context &ctx, QWidget *parent = nullptr);
    ~Stima();

private:
    Ui::Stima *ui;
};

#endif // STIMA_H
