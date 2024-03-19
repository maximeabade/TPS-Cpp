#include <iostream>
using namespace std;
class Electrique {
public:
    Electrique(float tension, float intensite);
    virtual void afficher() const = 0; // Ajout du mot-clé "virtual" pour polymorphisme

protected:
    float tension;
    float intensite;
};

Electrique::Electrique(float tension, float intensite) {
    this->tension = tension;
    this->intensite = intensite;
}

void Electrique::afficher() const {
    cout << "Tension : " << tension << "V" << endl;
    cout << "Intensite : " << intensite << "A" << endl;
}
