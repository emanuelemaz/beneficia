#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bfa_sb->setMaximum(std::numeric_limits<double>::max());
    ui->bfp_sb->setMaximum(std::numeric_limits<double>::max());
    ui->rc_sb->setMaximum(std::numeric_limits<double>::max());
    ui->rc_sb->setSingleStep(0.01);
    ui->r_sb->setMaximum(std::numeric_limits<double>::max());
    ui->r_sb->setSingleStep(0.01);
    ui->tempo_sb->setMaximum(std::numeric_limits<double>::max());
    ui->tempo_sb->setSingleStep(0.5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bft_add_clicked()
{
    bdialog = new BKDialog(tempo, false); //mostra fattore a/p
    int result = bdialog->exec();
    if (result==QDialog::Accepted) {
        ui->bft_table->setRowCount(0);
        bf_t.push_back(bdialog->input_bft);
         for (std::vector<Annualita>::size_type i=0; i<bf_t.size();i++) {
             ui->bft_table->insertRow(ui->bft_table->rowCount());
             QTableWidgetItem *importo = new QTableWidgetItem();
             importo->setData(Qt::EditRole, QString::number(bf_t[i].importo, 'f', 2) + QString("€"));
             QTableWidgetItem *anno_inizio = new QTableWidgetItem();
             anno_inizio->setData(Qt::EditRole, (bf_t[i].anno_inizio));
             QTableWidgetItem *anno_fine = new QTableWidgetItem();
             anno_fine->setData(Qt::EditRole, bf_t[i].anno_fine);
             ui->bft_table->setItem(ui->bft_table->rowCount()-1,0,importo);
             ui->bft_table->setItem(ui->bft_table->rowCount()-1,1,anno_inizio);
             ui->bft_table->setItem(ui->bft_table->rowCount()-1,2,anno_fine);
         }
    };
}


void MainWindow::on_k_add_clicked()
{
    bdialog = new BKDialog(tempo, true); //mostra fattore a/p
    int result = bdialog->exec();
    if (result==QDialog::Accepted) {
        ui->k_table->setRowCount(0);
        K.push_back(bdialog->input_bft);
         for (std::vector<Annualita>::size_type i=0; i<K.size();i++) {
             ui->k_table->insertRow(ui->k_table->rowCount());
             QTableWidgetItem *importo = new QTableWidgetItem();
             importo->setData(Qt::EditRole, QString::number(K[i].importo, 'f', 2) + QString("€"));
             QTableWidgetItem *anno_inizio = new QTableWidgetItem();
             anno_inizio->setData(Qt::EditRole, (K[i].anno_inizio));
             QTableWidgetItem *anno_fine = new QTableWidgetItem();
             anno_fine->setData(Qt::EditRole, (K[i].anno_fine));
             QTableWidgetItem *fattore = new QTableWidgetItem();
             fattore->setData(Qt::EditRole, (K[i].fattore_ap));
             ui->k_table->setItem(ui->k_table->rowCount()-1,0,importo);
             ui->k_table->setItem(ui->k_table->rowCount()-1,1,anno_inizio);
             ui->k_table->setItem(ui->k_table->rowCount()-1,2,anno_fine);
             ui->k_table->setItem(ui->k_table->rowCount()-1,3,fattore);
         }
    };
}


void MainWindow::on_bfa_sb_valueChanged(double bfa_input)
{
    bf_a = bfa_input;
}


void MainWindow::on_rc_sb_valueChanged(double rc_input)
{
    r_c = rc_input;
}


void MainWindow::on_r_sb_valueChanged(double r_input)
{
    r = r_input;
}


void MainWindow::on_stima_btn_clicked()
{

    Context ctx(bf_a,bf_p, bf_t, K, r, r_c, tempo, ui->bfp_ordinario->isChecked());
    stima = new Stima(ctx);
    int result = stima->exec();
}


void MainWindow::on_bfp_sb_valueChanged(double bfp_input)
{
    bf_p=bfp_input;
}


void MainWindow::on_tempo_sb_valueChanged(double tempo_input)
{
    tempo=tempo_input;
}


void MainWindow::on_bfa_ordinario_stateChanged(int bfa_ordinario)
{
    if (bfa_ordinario) {
        ui->bfp_ordinario->setChecked(false);
    } else {
        ui->bfp_ordinario->setChecked(true);

    }
}


void MainWindow::on_bfp_ordinario_stateChanged(int bfp_ordinario)
{
    if (bfp_ordinario) {
        ui->bfa_ordinario->setChecked(false);
    } else {
        ui->bfa_ordinario->setChecked(true);

    }
}

