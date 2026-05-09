#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

class player
{
    public:
        player(int hp, float spd);
        void draw(sf::RenderWindow& pencere);
        void changePosition_xright();
        void changePosition_xleft();
        void changePosition_yup();
        void changePosition_ydown();
        int getPosition_x();
        int getPosition_y();
    private:
        int health;
        float speed;
        sf::RectangleShape sekil;
};

#endif // PLAYER_H
