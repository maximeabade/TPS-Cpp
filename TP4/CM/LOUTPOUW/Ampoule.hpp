#ifndef AMPOULE_HPP
#define AMPOULE_HPP

#include <iostream>
#include "Electrique.hpp"

class Ampoule : public Electrique {
protected:
    bool etat = false;

public:
    Ampoule(); // Constructeur par défaut (optionnel)
    Ampoule(float tension, float intensite, bool etat); // Constructeur avec paramètres

    void Allumer();
    void Eteindre();

    float Calculer_puissance() const override; // Fonction virtuelle redéfinie

    bool Get_etat() const { return etat; }
    void Set_etat(bool etat) { this->etat = etat; }
};

#endif // AMPOULE_HPP
