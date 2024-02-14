#include <iostream>
#include "Guirlande.hpp"
#include "Light.hpp"


int main() {
  // Création de guirlandes
  Guirlande guirlande1(5), guirlande2(3);
  for (int i = 0; i < 5; i++) {
    // Correction : Utilisez le constructeur par défaut de Light
    guirlande1.lights[i] = Light();
    guirlande1.lights[i].turnOn(); // Ou utilisez cette ligne si vous voulez allumer les lumières avec une alternance
  }
  for (int i = 0; i < 3; i++) {
    // Correction : Utilisez le constructeur par défaut de Light
    guirlande2.lights[i] = Light();
    guirlande2.lights[i].turnOn(); // Ou utilisez cette ligne si vous voulez allumer les lumières avec une alternance
  }

  // Concaténation
  Guirlande guirlande3 = guirlande1 + guirlande2;
  std::cout << "Guirlande 3 (concaténation): ";
  guirlande3.print();

  // Soustraction
  Guirlande guirlande4 = guirlande1 - guirlande2;
  std::cout << "Guirlande 4 (soustraction): ";
  guirlande4.print();

  // Répétition
  Guirlande guirlande5 = guirlande1 * 3;
  std::cout << "Guirlande 5 (répétition): ";
  guirlande5.print();

  // Division
  Guirlande* guirlande6 = guirlande1/4;
  for (int i = 0; i < guirlande1.nbLights / 4; i++) {
    std::cout << "Guirlande " << i + 6 << " (division): ";
    guirlande6[i].print();
  }

  // Allumer/éteindre tout
  guirlande1.turnAllOn();
  guirlande1.print();
  guirlande1.turnAllOff();
  guirlande1.print();

  // Comparaison
  if (guirlande1 == guirlande2) {
    std::cout << "Les guirlandes sont identiques" << std::endl;
  } else {
    std::cout << "Les guirlandes sont différentes" << std::endl;
  }
  return 0;
}
