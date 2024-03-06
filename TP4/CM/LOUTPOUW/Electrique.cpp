#include <iostream>

class Electrique {
public:

    float tension = 220.0f;
    float intensite;

    Electrique() {}
    Electrique(float tension, float intensite) : tension(tension), intensite(intensite) {}

    virtual float Calculer_puissance() const = 0;

    float Get_tension() const { return tension; }
    void Set_tension(float tension) { this->tension = tension; }

    float Get_intensite() const { return intensite; }
    void Set_intensite(float intensite) { this->intensite = intensite; }
};
