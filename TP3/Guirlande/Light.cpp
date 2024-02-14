#include "Light.hpp"

// Ne redéfinissez pas le constructeur ici, cela doit être fait dans le fichier d'implémentation
Light::Light() {
   status = false;
}

bool Light::isOn() const {
  return status;
}

void Light::toggle() {
  status = !status;
}

void Light::turnOn() {
  status = true;
}

void Light::turnOff() {
  status = false;
}

bool Light::operator==(const Light& other) const {
  return this->status == other.status;
}

bool Light::operator!=(const Light& other) const {
  return !(*this == other);
}
