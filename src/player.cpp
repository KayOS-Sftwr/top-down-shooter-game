#include "player.h"
#include <SFML/Graphics.hpp>
player::player(int hp, float spd) : health(hp), speed(spd){

sekil.setFillColor(sf::Color::Black);
sekil.setSize(sf::Vector2f(100.0f,501.0f));
sekil.setPosition(600.0f, 300.0f);
}

void player::draw(sf::RenderWindow& pencere)
{
    pencere.draw(sekil);
}
