#include "Game.hpp"

Game::Game() : t1("A"), t2("B"), t3("C") {
    t1.pushDisk(4);
    t1.pushDisk(3);
    t1.pushDisk(2);
    t1.pushDisk(1);
}

void Game::display() const {
    std::cout << t1.display() << t2.display() << t3.display() << std::endl;
}

void Game::solve(int n, Tower& source, Tower& auxiliary, Tower& destination) {
    if (n > 0) {
        solve(n - 1, source, destination, auxiliary);
        Disk disk = source.pop();
        destination.pushDisk(disk.getSize());
        display();  // Display intermediate state for visualization
        solve(n - 1, auxiliary, source, destination);
    }
}
