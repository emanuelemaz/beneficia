#include "types.h"
#include <algorithm>
#include <cmath>

Annualita::Annualita() {};
Annualita::Annualita(double i, int y1, int y2, double f) {
    importo=i;
    anno_inizio=y1;
    anno_fine=y2;
    fattore_ap=f;
}

Context::Context() {};
Context::Context(double Bfa_in, double Bfp_in, std::vector<Annualita> Bft_in, std::vector<Annualita> K, double r, double r_c, double t, bool bfp_isordinario) {
    Bfa=Bfa_in;
    Bfp=Bfp_in;
    Bft=Bft_in;
    tempo = t;
    spese=K;
    saggio_interesse=r;
    saggio_capitalizzazione=r_c;
    bfp_ordinario = bfp_isordinario;
}

double Context::valore_ordinario_0() {
    if (bfp_ordinario) {
        return Bfp/saggio_capitalizzazione;
    } else {
        return Bfa/saggio_capitalizzazione;
    }
}

double Context::spese_dirette_0() {
    double val = 0.0;
    double r = saggio_interesse;
    double q = 1 + r;
    for (const Annualita &k : spese) {
        int durata = k.anno_fine-k.anno_inizio+1;
        val += k.importo*(1+r*k.fattore_ap)*(pow(q,durata)-1)/(r*pow(q,k.anno_fine));
    }
    return val;
}

double Context::valore_reale_0() {
    return valore_ordinario_0()-costo_totale_0();
}

double Context::spese_indirette_0() {
    double val = 0.0;
    double r = saggio_interesse;
    double q = 1 + r;
    for (const Annualita &bf : Bft) {
        int durata = bf.anno_fine-bf.anno_inizio+1;
        if (bfp_ordinario) {
            val += (Bfp-bf.importo)*(pow(q,durata)-1)/(r*pow(q,bf.anno_fine));
        } else {
            val += (bf.importo-Bfp)/(r*pow(q,bf.anno_fine));

        }
    }
    return val;
}
double Context::costo_totale_0() {
    return spese_dirette_0()+spese_indirette_0();
}
double Context::costo_totale_n() {
    double q = 1 + saggio_interesse;
    return costo_totale_0()/pow(q,tempo);
}
