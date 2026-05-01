#include "game_manager.h"
#include <SFML/Graphics.hpp>
game_manager::game_manager()
{
pencere.create(sf::VideoMode(1280,720),"Shooter Game");
}

void game_manager::run()
{
    while(pencere.isOpen()){
        sf::Event olay;

        while(pencere.pollEvent(olay))
        {
            if(olay.type==sf::Event::Closed)
            {
                pencere.close();
            }
        }
         pencere.clear(sf::Color::Black);

    }
}
