#include "Guirlande.hpp"

Guirlande::Guirlande(int nbLights) {
  this->nbLights = nbLights;
  lights = new Light[nbLights]; // Allouer de la mémoire pour les lumières
}

Guirlande::Guirlande() {
  this->nbLights = 0;
  lights = nullptr;
}

Guirlande::~Guirlande() {
  delete[] lights; // Libérer la mémoire
}

Guirlande Guirlande::operator+(const Guirlande& guirlande) const {
    int newNbLights = this->nbLights + guirlande.nbLights;
    Guirlande newGuirlande(newNbLights);

    for (int i = 0; i < this->nbLights; i++) {
        newGuirlande.lights[i] = this->lights[i];
    }

    for (int i = 0; i < guirlande.nbLights; i++) {
        newGuirlande.lights[i + this->nbLights] = guirlande.lights[i];
    }

    return newGuirlande;
}

Guirlande Guirlande::operator-(const Guirlande& guirlande) const {
  if (guirlande.nbLights > this->nbLights) {
    throw std::out_of_range("La guirlande à soustraire ne peut pas être plus grande que la guirlande de base");
  }
  Guirlande newGuirlande(this->nbLights); // Créer une nouvelle guirlande avec la même taille
  int j = 0;
  for (int i = 0; i < this->nbLights; i++) {
    bool found = false;
    for (int k = 0; k < guirlande.nbLights; k++) {
      if (this->lights[i] == guirlande.lights[k]) {
        found = true;
        break;
      }
    }
    if (!found) {
      newGuirlande.lights[j++] = this->lights[i];
    }
  }
  return newGuirlande;
}

Guirlande Guirlande::operator*(int n) const {
  if (n < 0) {
    throw std::invalid_argument("Le nombre de répétitions ne peut pas être négatif");
  }
  Guirlande newGuirlande(this->nbLights * n); // Créer une nouvelle guirlande avec la taille multipliée par n
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < this->nbLights; j++) {
      newGuirlande.lights[i * this->nbLights + j] = this->lights[j];
    }
  }
  return newGuirlande;
}

void Guirlande::print() const {
  for (int i = 0; i < this->nbLights; i++) {
    std::cout << lights[i].isOn() << " ";
  }
  std::cout << std::endl;
}

void Guirlande::turnAllOn() {
  for (int i = 0; i < nbLights; i++) {
    lights[i].turnOn();
  }
}

void Guirlande::turnAllOff() {
  for (int i = 0; i < nbLights; i++) {
    lights[i].turnOff();
  }
}

bool Guirlande::operator==(const Guirlande& guirlande) const {
  if (this->nbLights != guirlande.nbLights) {
    return false;
  }
  for (int i = 0; i < this->nbLights; i++) {
    if (this->lights[i] != guirlande.lights[i]) {
      return false;
    }
  }
  return true;
}

bool Guirlande::operator!=(const Guirlande& guirlande) const {
  return !(*this == guirlande);
}

//methode divide

Guirlande* Guirlande::operator/(int divisor) const {
  if (divisor <= 0) {
    throw std::invalid_argument("Le diviseur doit être un entier positif");
  }

  int newNbLights = nbLights / divisor;
  Guirlande* guirlandeArray = new Guirlande[newNbLights];

  for (int i = 0; i < newNbLights; i++) {
    guirlandeArray[i] = Guirlande(divisor);
    for (int j = 0; j < divisor; j++) {
      guirlandeArray[i].lights[j] = lights[i * divisor + j];
    }
  }

  return guirlandeArray;
}