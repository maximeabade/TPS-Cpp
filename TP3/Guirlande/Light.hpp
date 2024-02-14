

#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__

#include <iostream>

class Light {
public:
  bool status;

  // Retirez la déclaration de toutes les fonctions ici sauf le constructeur
  Light();
  bool isOn() const;
  void toggle();
  void turnOn();
  void turnOff();

  bool operator==(const Light& other) const;
  bool operator!=(const Light& other) const;
};

#endif
