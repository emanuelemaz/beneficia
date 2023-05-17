#include "stima.h"
#include "ui_stima.h"
#include "types.h"

Stima::Stima(Context &ctx, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stima)
{
    ui->setupUi(this);
    ui->Sd0->setMinimum(std::numeric_limits<double>::max()*(-1));
    ui->Sd0->setMaximum(std::numeric_limits<double>::max());

    ui->Si0->setMinimum(std::numeric_limits<double>::max()*(-1));
    ui->Si0->setMaximum(std::numeric_limits<double>::max());

    ui->Vo_a0->setMinimum(std::numeric_limits<double>::max()*(-1));
    ui->Vo_a0->setMaximum(std::numeric_limits<double>::max());

    ui->Kt0->setMinimum(std::numeric_limits<double>::max()*(-1));
    ui->Kt0->setMaximum(std::numeric_limits<double>::max());

    ui->Vr0->setMinimum(std::numeric_limits<double>::max()*(-1));
    ui->Vr0->setMaximum(std::numeric_limits<double>::max());

    ui->Sd0->setValue(ctx.spese_dirette_0());
    ui->Si0->setValue(ctx.spese_indirette_0());
    ui->Vo_a0->setValue(ctx.valore_ordinario_0());
    ui->Kt0->setValue(ctx.costo_totale_0());

    ui->Vr0->setValue(ctx.valore_reale_0());

    QString giudizio_reddito;
    QString giudizio_capitale;
    QString giudizio_fruttuosita;

    if (ctx.Bfp-ctx.Bfa>=ctx.costo_totale_n()*ctx.saggio_interesse) {
        giudizio_reddito = "Visto che " + QString::number(ctx.Bfp-ctx.Bfa) + "€ ≥ " + QString::number(ctx.costo_totale_n()*ctx.saggio_interesse, 'f', 2) + "€ il miglioramento È conveniente.";
    } else {
        giudizio_reddito = "Visto che " + QString::number(ctx.Bfp-ctx.Bfa) + "€ ≤ " + QString::number(ctx.costo_totale_n()*ctx.saggio_interesse, 'f', 2) + "€ il miglioramento NON È conveniente.";
    }

    if ((ctx.Bfp-ctx.Bfa)/ctx.saggio_interesse>=ctx.costo_totale_n()) {
        giudizio_capitale = "Visto che " + QString::number((ctx.Bfp-ctx.Bfa)/ctx.saggio_interesse, 'f', 2) + "€ ≥ " + QString::number(ctx.costo_totale_n()) + "€ il miglioramento È conveniente.";
    } else {
        giudizio_capitale = "Visto che " + QString::number((ctx.Bfp-ctx.Bfa)/ctx.saggio_interesse, 'f', 2) + "€ ≤ " + QString::number(ctx.costo_totale_n()) + "€ il miglioramento NON È conveniente.";
    }

    if ((ctx.Bfp-ctx.Bfa)/ctx.saggio_interesse>=ctx.costo_totale_n()) {
        giudizio_fruttuosita = "Visto che " + QString::number((ctx.Bfp-ctx.Bfa)/ctx.costo_totale_n(), 'f', 2) + " ≥ " + QString::number(ctx.saggio_interesse) + " il miglioramento È conveniente.";
    } else {
        giudizio_fruttuosita = "Visto che " + QString::number((ctx.Bfp-ctx.Bfa)/ctx.costo_totale_n(), 'f', 2) + " ≤ " + QString::number(ctx.saggio_interesse) + " il miglioramento NON È conveniente.";
    }


    ui->giud_r->setText(giudizio_reddito);
    ui->giud_c->setText(giudizio_capitale);
    ui->giud_f->setText(giudizio_fruttuosita);
}

Stima::~Stima()
{
    delete ui;
}
