#include "Ampoule.hpp"
#include "Electrique.hpp"
#include "Guirlande.hpp"
#include <iostream>

using namespace std;

int main() {
    // Création des ampoules
    Ampoule a1(0.05);
    Ampoule a2(0.1);

    // Création d'une guirlande
    vector<Ampoule> ampoules = {a1, a2};
    Guirlande guirlande(ampoules);

    // Affichage initial
    guirlande.afficher();

    // Allumage de toutes les ampoules
    guirlande.allumer();

    // Affichage après allumage
    cout << endl;
    guirlande.afficher();

    // Calcul et affichage de la puissance consommée par chaque guirlande
    cout << endl;
    cout << "Puissance consommée par la guirlande : " << guirlande.puissance() << "W" << endl;

    return 0;
}