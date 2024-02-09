#include "Tower.hpp"

Tower::Tower(const std::string& name) : name(name) {}

void Tower::pushDisk(int diskSize) {
    if (disks.empty() || diskSize < disks.back()) {
        disks.push_back(diskSize);
    } else {
        std::cerr << "Error: Cannot add a larger disk on top of a smaller one." << std::endl;
    }
}

void Tower::popDisk() {
    if (!disks.empty()) {
        disks.pop_back();
    } else {
        std::cerr << "Error: Cannot pop from an empty tower." << std::endl;
    }
}

void Tower::display() const {
    if (disks.empty()) {
        std::cout << name << " is empty." << std::endl;
    } else {
        std::cout << name << ":" << std::endl;
        for (int diskSize : disks) {
            std::cout << "  - " << diskSize << std::endl;
        }
    }
}

Tower::~Tower() {
    // No explicit deallocation needed for std::vector
}

std::ostream& operator<<(std::ostream& out, const Tower& tower) {
    tower.display();  // Call Tower's display method for consistent output
    return out;
}
