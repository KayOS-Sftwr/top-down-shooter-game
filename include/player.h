#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

class player
{
    public:
        player();
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
        void can_kontrol();
        int can_dondur();
        void hiz_artir();
        void hiz_azalt();
        void dmg_artir();
        void can_cizim(player p1,sf::RenderWindow& pencere);
    private:
        int health=100;
        float speed=8.0f;
        sf::RectangleShape sekil;
        sf::Texture player_texture;
};

#endif // PLAYER_H
