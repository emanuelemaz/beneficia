#ifndef TYPES_H
#define TYPES_H
#include <vector>
class Annualita {
    public:
        double importo;
        int anno_inizio;
        int anno_fine;
        double fattore_ap; //fattore di anticipazione/posticipazione delle annualità (12/12=anticipata, 6/12=mediamente anticipata, 0/12=posticipata,...)
        bool illimitato;
        Annualita();
        Annualita(double i, int y1, int y2, double f);
};

class Context {
    public:
        double Bfa;
        double Bfp;
        std::vector<Annualita> Bft;
        std::vector<Annualita> spese;
        double saggio_interesse;
        double saggio_capitalizzazione;
        double tempo;
        bool bfp_ordinario;

        double valore_ordinario_0();
        double valore_reale_0();
        double spese_dirette_0();
        double spese_indirette_0();
        double costo_totale_0();
        double costo_totale_n();
        Context();
        Context(double Bfa, double Bfp, std::vector<Annualita> Bft, std::vector<Annualita> spese, double saggio_interesse, double saggio_capitalizzazione, double tempo, bool bfp_ordinario);
};

#endif // TYPES_H
