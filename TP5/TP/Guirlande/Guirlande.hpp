#ifndef GUIRLANDE_HPP
#define GUIRLANDE_HPP

#include "Ampoule.hpp"
#include <vector>

using namespace std;

class Guirlande : public Electrique {
private:
    vector<Ampoule> ampoules;
    float coutProduction; // Ajout du coût de production

public:
    Guirlande(vector<Ampoule> ampoules, float coutCable);
    
    float puissance() const;

    void afficher() const override;

    void allumer();
    vector<Ampoule> getAmpoules() const; // Ajout de la fonction getAmpoules
    float getPrixVente() const; // Ajout du prix de vente
    double getCoutCable() const; // Ajout du coût de production
private:
    float calculerCoutProduction(float coutCable); // Fonction pour calculer le coût de production
};

Guirlande::Guirlande(vector<Ampoule> ampoules, float coutCable) : Electrique(220, 0) {
    this->ampoules = ampoules;
    for (const Ampoule &ampoule : ampoules) {
        intensite += ampoule.getIntensite();
    }
    coutProduction = calculerCoutProduction(coutCable);
}

//fonction getCoutCable qui va dependre du nombre d ampoules
double Guirlande::getCoutCable() const {
    return 1.1 * ampoules.size();
}

//fonction getAmpoules
vector<Ampoule> Guirlande::getAmpoules() const {
    return ampoules;
}

float Guirlande::puissance() const {
    float puissanceTotale = 0;
    for (const Ampoule &ampoule : ampoules) {
        puissanceTotale += ampoule.puissance();
    }
    return puissanceTotale;
}

void Guirlande::afficher() const {
    Electrique::afficher();
    for (const Ampoule &ampoule : ampoules) {
        ampoule.afficher();
    }
    printf("\n");
}

void Guirlande::allumer() {
    for (Ampoule &ampoule : ampoules) {
        ampoule.setIntensite(0.1);
    }
}

float Guirlande::getPrixVente() const {
    float marge = 0.1; // Marge de 10%
    return coutProduction * (1 + marge);
}

float Guirlande::calculerCoutProduction(float coutCable) {
    float coutTotal = 0;
    for (const Ampoule &ampoule : ampoules) {
        coutTotal += ampoule.getPrixAchat();
    }
    return coutTotal + coutCable;
}

#endif // GUIRLANDE_HPP
