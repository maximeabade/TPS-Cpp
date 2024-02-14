#ifndef __GUIRLANDE_HPP__
#define __GUIRLANDE_HPP__

#include <iostream>
#include "Light.hpp"

class Guirlande {
public:
  Light* lights;
  int nbLights;

  Guirlande(int nbLights);
  Guirlande();
  ~Guirlande();

  // Concaténation
  Guirlande operator+(const Guirlande& guirlande) const;

  // Soustraction
  Guirlande operator-(const Guirlande& guirlande) const;

  // Répétition
  Guirlande operator*(int n) const;

  // Division
Guirlande* operator/(int divisor) const;

  void print() const;
  void turnAllOn();
  void turnAllOff();

  bool operator==(const Guirlande& guirlande) const;
  bool operator!=(const Guirlande& guirlande) const;

private:
  // Méthodes privées pour la gestion des exceptions
};

#endif
