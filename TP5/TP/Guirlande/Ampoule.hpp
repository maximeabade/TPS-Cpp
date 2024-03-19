#ifndef AMPOULE_HPP
#define AMPOULE_HPP

#include "Electrique.hpp"
#include <vector>

using namespace std;

class Ampoule : public Electrique {
public:
    Ampoule(float intensite = 0);

    float puissance() const;

    virtual void afficher() const override; // Ajout du mot-clé "override" pour polymorphisme

    float getIntensite() const;
    void setIntensite(float intensite);
    float getPrixAchat() const; // Ajout pour le prix d'achat
    void setPrixAchat(float prixAchat);

    float intensite;
    float prixAchat; // Ajout du prix d'achat
};

Ampoule::Ampoule(float intensite) : Electrique(220, intensite) {}

float Ampoule::puissance() const {
    return tension * intensite;
}

void Ampoule::afficher() const {
    if (intensite == 0) {
        cout << ".";
    } else if (intensite <= 0.05) {
        cout << "o";
    } else {
        cout << "O";
    }
}

float Ampoule::getIntensite() const {
    return intensite;
}

void Ampoule::setIntensite(float intensite) {
    this->intensite = intensite;
}

float Ampoule::getPrixAchat() const {
    return prixAchat;
}

void Ampoule::setPrixAchat(float prixAchat) {
    this->prixAchat = prixAchat;
}

#endif // AMPOULE_HPP
