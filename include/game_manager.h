#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <SFML/Graphics.hpp>
#include "player.h"
using namespace std;
class game_manager
{
    public:
        game_manager();

        void run();
    private:
    sf::RenderWindow pencere;
    player p1;

};

#endif // GAME_MANAGER_H
