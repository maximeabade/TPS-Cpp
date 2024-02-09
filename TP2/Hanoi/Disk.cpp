#include "Disk.hpp"

Disk::Disk(int diameter){
    this->size = diameter;
}

Disk::~Disk(){
    //rien a faire
}

int Disk::getSize(){
    return this->size;
}