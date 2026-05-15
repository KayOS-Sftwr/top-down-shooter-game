#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

class bullet
{
    public:
        bullet();
        void draw_screen(sf::RenderWindow& pencere);
        void setPosition(sf::Vector2f konum );
        void move_mermi(sf::Vector2i mouse_konum, sf::Vector2f player_konum);
        void mermi_hareket();
        int ekrandanciktimi();
        int temizle();
        int getPosition_x();
        int getPosition_y();
    private:
        float speed=10.0f;
        int damage=50;
        sf::Vector2f yon_vek;
        sf::RectangleShape mermi_sekil;

};

#endif // BULLET_H
