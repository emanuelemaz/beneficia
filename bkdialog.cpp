#include "bkdialog.h"
#include "ui_bkdialog.h"
#include "types.h"
#include <vector>

BKDialog::BKDialog(double tempo, bool showf, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BKDialog)
{
    ui->setupUi(this);

    input_bft.importo=0;
    input_bft.anno_inizio=0;
    input_bft.anno_fine=0;
    input_bft.fattore_ap=0;

    ui->doubleSpinBox->clear();
    ui->doubleSpinBox_2->clear();
    ui->spinBox->clear();
    ui->spinBox_2->clear();

    ui->doubleSpinBox->setMaximum(std::numeric_limits<double>::max());
    ui->doubleSpinBox_2->setMaximum(std::numeric_limits<double>::max());
    ui->spinBox->setMaximum(std::numeric_limits<int>::max());
    ui->spinBox_2->setMaximum(qIntCast(tempo));

    if (!showf) {
        setWindowTitle("Input: Beneficio fondiario transitorio");
        ui->label_4->hide();
        ui->doubleSpinBox_2->hide();
        ui->doubleSpinBox_2->setValue(0);
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        adjustSize();
    } else {
        setWindowTitle("Input: Spesa diretta");
        ui->label_4->show();
        ui->doubleSpinBox_2->show();
        ui->pushButton->show();
        ui->pushButton_2->show();
        ui->pushButton_3->show();
        adjustSize();
    }
}

BKDialog::~BKDialog()
{
    delete ui;
}

void BKDialog::on_buttonBox_accepted()
{
    input_bft.importo=ui->doubleSpinBox->value();
    input_bft.fattore_ap=ui->doubleSpinBox_2->value();
    input_bft.anno_inizio=ui->spinBox->value();
    input_bft.anno_fine=ui->spinBox_2->value();
}


void BKDialog::on_pushButton_clicked()
{
    ui->doubleSpinBox_2->setValue(1);
}


void BKDialog::on_pushButton_3_clicked()
{
    ui->doubleSpinBox_2->setValue(0.5);
}


void BKDialog::on_pushButton_2_clicked()
{
    ui->doubleSpinBox_2->setValue(0);
}

