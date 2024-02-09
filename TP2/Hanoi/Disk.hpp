#ifndef __DISK_HPP__
#define __DISK_HPP__
#include <iostream>
using namespace std;


class Disk{
    public:
        Disk(int diameter);
        ~Disk();
        int getSize();
    private:
        int size;
};

#endif