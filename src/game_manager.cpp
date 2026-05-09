#include "game_manager.h"
#include <SFML/Graphics.hpp>
game_manager::game_manager() : p1(100,5.0f), b1(50,10.0f)
{
pencere.create(sf::VideoMode(1280,720),"Shooter Game");
pencere.setFramerateLimit(165);
}

void game_manager::run()
{
    sf::Vector2f player_konum;
     sf::Vector2i mouse_position;
    sf::Vector2f player_konum_initial;
    player_konum_initial.x=p1.getPosition_x();
        player_konum_initial.y=p1.getPosition_y();
    b1.setPosition(player_konum_initial);
    while(pencere.isOpen()){
        sf::Event olay;
        while(pencere.pollEvent(olay))
        {
            printf(".");
           if (olay.type == sf::Event::MouseButtonPressed) {
        if (olay.mouseButton.button == sf::Mouse::Left) {
        player_konum.x=p1.getPosition_x();
        player_konum.y=p1.getPosition_y();
        mouse_position=sf::Mouse::getPosition(pencere);
            b1.setPosition(player_konum);
        }
           }
            if(olay.type==sf::Event::Closed)
            {
                pencere.close();
            }
        }
//        sf::Vector2f player_konum;
//        player_konum.x=p1.getPosition_x();
//        player_konum.y=p1.getPosition_y();
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
        b1.move_mermi(mouse_position, player_konum);
        pencere.clear(sf::Color::Blue);
           p1.draw(pencere);
        b1.draw_screen(pencere);
         pencere.display();

    }
}
