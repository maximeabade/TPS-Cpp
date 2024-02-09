#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "Tower.hpp"  // Include header for Tower class

class Game {
public:
    Game();
    void display() const;  // Use const for readability
    void solve(int n, Tower& source, Tower& auxiliary, Tower& destination);

private:
    Tower t1;
    Tower t2;
    Tower t3;
};

#endif
