#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

class bullet
{
    public:
        bullet(int dmg, float spd);
        void draw_screen(sf::RenderWindow& pencere);
        void setPosition(sf::Vector2f konum );
        void move_mermi(sf::Vector2i mouse_konum, sf::Vector2f player_konum);
    private:
        float speed;
        int damage;
        sf::RectangleShape mermi_sekil;

};

#endif // BULLET_H
