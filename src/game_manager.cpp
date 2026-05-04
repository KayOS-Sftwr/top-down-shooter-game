#include "game_manager.h"
#include <SFML/Graphics.hpp>
game_manager::game_manager() : p1(100,5.0f)
{
pencere.create(sf::VideoMode(1280,720),"Shooter Game");
pencere.setFramerateLimit(165);
}
void game_manager::run()
{
    int x=600 , y=300;
    while(pencere.isOpen()){
        sf::Event olay;

        while(pencere.pollEvent(olay))
        {
            printf(".");

            if(olay.type==sf::Event::Closed)
            {
                pencere.close();
            }
        }
         pencere.clear(sf::Color::Blue);
          p1.draw(pencere);
         pencere.display();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            p1.changePosition_xright();

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            p1.changePosition_xleft();

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            p1.changePosition_ydown();

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            p1.changePosition_yup();

        }

    }
}
