#include "Disk.hpp"  // Include necessary headers
#include "Tower.hpp"
#include "Game.hpp"
#include <iostream>

using namespace std;  // Avoid using `using namespace std;`

int main() {
    Game g = Game();
    g.display();
    g.solve();
    return 0;
}