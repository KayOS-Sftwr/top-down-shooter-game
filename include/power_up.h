#ifndef POWER_UP_H
#define POWER_UP_H
#include <SFML/Graphics.hpp>

class power_up
{
    public:
        power_up();
        void can(sf::Vector2f dumsan_konum);
        void hiz(sf::Vector2f dumsan_konum);
        void dmg(sf::Vector2f dumsan_konum);
        int carpti_mi(sf::FloatRect player_konum);
        void yazdir(sf::RenderWindow& pencere);
        power_up(const power_up& ornek);
    power_up& operator=(const power_up& ornek);
    private:
    sf::CircleShape power_sekil;
    sf::Texture circle_texture;

};

#endif // POWER_UP_H
