#include "player.h"
#include <SFML/Graphics.hpp>
player::player(int hp, float spd) : health(hp), speed(spd){

sekil.setFillColor(sf::Color::Black);
sekil.setSize(sf::Vector2f(50.0f,25.0f));
sekil.setPosition(600.0f, 300.0f);
}

void player::draw(sf::RenderWindow& pencere)
{
    pencere.draw(sekil);
}
void player::changePosition_xright(){
sf::Vector2f konum = sekil.getPosition();
sekil.move(speed,0);
if (konum.x > 1280.0f) {
        sekil.setPosition(0.0f, konum.y);
}
}
void player::changePosition_xleft(){
sf::Vector2f konum = sekil.getPosition();
sekil.move(-speed,0);
if (konum.x < 0.0f) sekil.setPosition(1280.0f, konum.y);
}
void player::changePosition_yup(){
    sf::Vector2f konum = sekil.getPosition();
    sekil.move(0,-speed);
    if (konum.y < 0.0f) sekil.setPosition(konum.x, 720.0f);
}
    void player::changePosition_ydown(){

sf::Vector2f konum = sekil.getPosition();
    sekil.move(0,speed);
if (konum.y > 720.0f) sekil.setPosition(konum.x, 0.0f);
    }

    int player::getPosition_x()
    {
        sf::Vector2f konum= sekil.getPosition();
        return konum.x;
    }
      int player::getPosition_y()
    {
        sf::Vector2f konum= sekil.getPosition();
        return konum.y;
    }
