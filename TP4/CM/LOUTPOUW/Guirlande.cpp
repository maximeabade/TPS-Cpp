#include <iostream>
#include <vector>
#include "Electrique.hpp"
#include "Ampoule.hpp"

class Guirlande : public Electrique {
public:
    std::vector<Ampoule> liste_ampoules;
    Guirlande() {}
    Guirlande(float tension, float intensite) : Electrique(tension, intensite) {}

    void Ajouter_ampoule(const Ampoule& ampoule) { liste_ampoules.push_back(ampoule); }

    float Calculer_puissance_totale() const {
        float puissance_totale = 0.0f;
        for (const Ampoule& ampoule : liste_ampoules) {
            puissance_totale += ampoule.Calculer_puissance();
        }
        return puissance_totale;
    }
};