#include "game_manager.h"
#include <SFML/Graphics.hpp>
game_manager::game_manager() : p1(100,5.0f)
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
    int counter=0;
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
        bullet yeni_mermi;
        yeni_mermi.setPosition(player_konum);
        yeni_mermi.move_mermi(mouse_position,player_konum);
        bullets.push_back(yeni_mermi);
        counter++;
        }
           }
            if(olay.type==sf::Event::Closed)
            {
                pencere.close();
            }
        }

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
        for(int i=0;i<bullets.size();i++)
        {
            bullets[i].mermi_hareket();
        }
        for(int i=0;i<bullets.size();i++)
        {
            if(bullets[i].temizle())
                bullets.erase(bullets.begin() + i);
        }

        pencere.clear(sf::Color::Blue);
           p1.draw(pencere);
       for(int i=0;i<bullets.size();i++)
        {
            bullets[i].draw_screen(pencere);
        }
         pencere.display();

    }
}
