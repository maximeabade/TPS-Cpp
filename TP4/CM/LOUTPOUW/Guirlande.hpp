#ifndef GUIRLANDE_HPP
#define GUIRLANDE_HPP

#include <iostream>
#include <vector>
#include "Electrique.hpp"

class Guirlande : public Electrique {
public:
    std::vector<Ampoule> liste_ampoules;

    Guirlande();
    Guirlande(float tension, float intensite);

    void Ajouter_ampoule(const Ampoule& ampoule);

    float Calculer_puissance_totale() const;
};

#endif // GUIRLANDE_HPP
