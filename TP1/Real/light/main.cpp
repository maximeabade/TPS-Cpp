#include <iostream>
#include "Light.hpp"

int main() {
    Light light;

    cout << "La lumière est-elle allumée ? " << light.isOn() << endl;

    light.toggle();

    cout << "La lumière est-elle allumée ? " << light.isOn() << endl;

    return 0;
}