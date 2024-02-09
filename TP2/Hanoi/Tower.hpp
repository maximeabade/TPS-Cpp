#ifndef __TOWER_HPP__
#define __TOWER_HPP__

#include <iostream>
#include <string>
#include <vector>  // Use std::vector for dynamic disk storage
#include "Disk.hpp"  // Include header for Disk class

class Tower {
public:
    Tower(const std::string& name);  // Constructor

    void pushDisk(int diskSize);  // Add a disk of specified size
    void popDisk();               // Remove the top disk
    void display() const;         // Display the tower's state (const for readability)

    ~Tower();                   // Destructor for proper memory management

    friend std::ostream& operator<<(std::ostream& out, const Tower& tower);  // Friend for output

private:
    std::string name;
    std::vector<int> disks;  // Store disk sizes using std::vector
};

#endif
