#include <iostream>
#include "Light.hpp"

int main() {
    Light light;


    light.toggle();


    //Tableau de lights pour faire une guirlande : 
    Light guirlande[10];
    for (int i = 0; i < 10; i++) {
        if(i%2==0){guirlande[i].toggle();}
    }
    //afichage de la guirlande
    for (int i = 0; i < 10; i++) {
        //cout << guirlande[i].isOn() << endl;
        //on veut afficher tous les 1 sur la meme ligne et tous les 0 en dessous
        if(guirlande[i].isOn()){cout << ".";}
        if(i==9){cout << endl;}    
    }
    for (int i = 0; i < 10; i++) {
        if(!guirlande[i].isOn()){cout << "O";}
        if(i==9){cout << endl;}
    }

    return 0;
}