#ifndef ELECTRIQUE_HPP
#define ELECTRIQUE_HPP

#include <iostream>

class Electrique {
protected:
    float tension = 220.0f;
    float intensite;

public:
    Electrique();
    Electrique(float tension, float intensite);

    virtual float Calculer_puissance() const = 0; // Fonction virtuelle pure

    float Get_tension() const { return tension; }
    void Set_tension(float tension) { this->tension = tension; }

    float Get_intensite() const { return intensite; }
    void Set_intensite(float intensite) { this->intensite = intensite; }
};

#endif // ELECTRIQUE_HPP
