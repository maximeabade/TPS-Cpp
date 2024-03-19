#include <iostream>


class Electrique {
public:
    Electrique(float tension, float intensite);
    void afficher() const;

private:
    float tension;
    float intensite;
};
