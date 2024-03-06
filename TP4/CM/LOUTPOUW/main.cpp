#include <iostream>
#include "Ampoule.hpp"
#include "Guirlande.hpp"

void Allumer_toutes_les_ampoules(Guirlande& guirlande);

int main() {
    // Création d'une guirlande
    Guirlande guirlande;

    // Création d'ampoules avec tous les arguments
    Ampoule ampoule1(220.0f, 0.05f, false);
    Ampoule ampoule2(220.0f, 0.1f, true);

    // Ajout des ampoules à la guirlande
    guirlande.Ajouter_ampoule(ampoule1);
    guirlande.Ajouter_ampoule(ampoule2);

    // Allumage de toutes les ampoules
    Allumer_toutes_les_ampoules(guirlande);

    // Calcul et affichage de la puissance consommée par chaque ampoule
    for (const Ampoule& ampoule : guirlande.liste_ampoules) {
        float puissance = ampoule.Calculer_puissance();
        std::cout << "Puissance consommée par l'ampoule : " << puissance << " W" << std::endl;
    }

    // Calcul et affichage de la puissance consommée par la guirlande
    float puissance_totale = guirlande.Calculer_puissance_totale();
    std::cout << "Puissance consommée par la guirlande : " << puissance_totale << " W" << std::endl;

    return 0;
}

// Définition de la fonction `Allumer_toutes_les_ampoules`
void Allumer_toutes_les_ampoules(Guirlande& guirlande) {
    for (Ampoule& ampoule : guirlande.liste_ampoules) {
        ampoule.Allumer();
    }
}
