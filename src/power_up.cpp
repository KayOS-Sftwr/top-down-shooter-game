#include "power_up.h"

power_up::power_up()
{
power_sekil.setRadius(5.0f);
power_sekil.setFillColor(sf::Color::White);
}


void power_up::can(sf::Vector2f dumsan_konum)
{
    if(!circle_texture.loadFromFile("health_up.png"))
    {}
    power_sekil.setTexture(&circle_texture);
    power_sekil.setPosition(dumsan_konum);

}void power_up::hiz(sf::Vector2f dumsan_konum)
{
    if(!circle_texture.loadFromFile("speed_power_up.png"))
    {}
    power_sekil.setTexture(&circle_texture);
    power_sekil.setPosition(dumsan_konum);
}
void power_up::dmg(sf::Vector2f dumsan_konum)
{
    if(!circle_texture.loadFromFile("damage.png"))
    {}
    power_sekil.setTexture(&circle_texture);
    power_sekil.setPosition(dumsan_konum);
}

int power_up::carpti_mi(sf::FloatRect player_konum)
{
    if(player_konum.intersects(power_sekil.getGlobalBounds()))
       {
           return true;
       }
       else
        {return false;
        }
}
void power_up::yazdir(sf::RenderWindow& pencere)
{
    pencere.draw(power_sekil);
}
