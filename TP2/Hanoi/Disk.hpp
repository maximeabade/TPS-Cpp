#ifndef __DISK_HPP__
#define __DISK_HPP__

#include <iostream>

class Disk {
public:
    Disk(int diameter);
    ~Disk() = default;
    int getSize() const;

private:
    int size;
};

#endif