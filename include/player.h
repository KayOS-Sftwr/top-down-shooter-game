#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

class player
{
    public:
        player(int hp, float spd);
        void draw(sf::RenderWindow& pencere);

    private:
        int health;
        float speed;
        sf::RectangleShape sekil;
};

#endif // PLAYER_H
