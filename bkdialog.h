#ifndef BKDIALOG_H
#define BKDIALOG_H

#include <QDialog>
#include "types.h"
#include <vector>

namespace Ui {
class BKDialog;
}

class BKDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BKDialog(double tempo, bool showf, QWidget *parent = nullptr);
    ~BKDialog();
    Annualita input_bft;

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::BKDialog *ui;
};

#endif // BKDIALOG_H
