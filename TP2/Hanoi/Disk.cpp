#include "Disk.hpp"

Disk::Disk(int diameter) : size(diameter) {}

int Disk::getSize() const {
    return size;
}