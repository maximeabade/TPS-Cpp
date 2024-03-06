#include <iostream>
#include "Electrique.hpp"

class Ampoule : public Electrique {

public:
    bool etat = false;
    Ampoule() {}
    Ampoule(float tension, float intensite, bool etat) : Electrique(tension, intensite), etat(etat) {}

    void Allumer() { etat = true; }
    void Eteindre() { etat = false; }

    float Calculer_puissance() const override {
        return etat ? tension * intensite : 0.0f;
    }

    bool Get_etat() const { return etat; }
    void Set_etat(bool etat) { this->etat = etat; }
};