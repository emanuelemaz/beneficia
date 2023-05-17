#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "types.h"
#include "bkdialog.h"
#include "stima.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bft_add_clicked();

    void on_k_add_clicked();

    void on_bfa_sb_valueChanged(double arg1);

    void on_rc_sb_valueChanged(double arg1);

    void on_r_sb_valueChanged(double arg1);

    void on_stima_btn_clicked();

    void on_bfp_sb_valueChanged(double arg1);

    void on_tempo_sb_valueChanged(double arg1);

    void on_bfa_ordinario_stateChanged(int arg1);

    void on_bfp_ordinario_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    double r_c; //tasso di capitalizzazione
    double r; //tasso di interesse
    double bf_a; // beneficio fondiario antemiglioramento
    double bf_p; // beneficio fondiario postmiglioramento
    double tempo;
    std::vector<Annualita> bf_t;
    std::vector<Annualita> K;
    BKDialog *bdialog;
    Stima *stima;
};
#endif // MAINWINDOW_H
