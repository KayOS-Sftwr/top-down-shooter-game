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
        void can_azalt();
        int can_yok();
        void can_sifirla();
        sf::FloatRect getGlobalbounds();
        void karakteri_dondur(sf::Vector2i mouse_konum,sf::Vector2f konum_player);
        void can_artir();
        void hiz_artir();
        void dmg_artir();
    private:
        int health;
        float speed;
        sf::RectangleShape sekil;
        sf::Texture player_texture;
};

#endif // PLAYER_H
