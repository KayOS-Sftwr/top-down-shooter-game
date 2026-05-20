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
        void buraya_bak(sf::Vector2i mouse_konum,sf::Vector2f mermi_konum);
        int ekrandanciktimi();
        int temizle();
        int getPosition_x();
        int getPosition_y();
        bullet(const bullet& ornek);
        bullet& operator=(const bullet& ornek);
    private:
        float speed=25.0f;
        int damage=50;
        sf::Vector2f yon_vek;
        sf::RectangleShape mermi_sekil;
        sf::Texture mermi_texture;

};

#endif // BULLET_H
