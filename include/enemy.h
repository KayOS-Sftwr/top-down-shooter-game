#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>

class enemy
{
    public:
        enemy();
    void mermi_carpti(sf::Vector2f mermi_konum);
    int oyuncu_carpti(sf::Vector2f player_konum);
    void hareket_et(sf::Vector2f player_konum);
    void setPosition();
    void yazdir(sf::RenderWindow& pencere);
    int can_kac();
    int mermi_sil(sf::Vector2f mermi_konum);
    int getPosition();
    private:
        int health=100;
        float speed=2.0f;
        int damage=25;
        sf::RectangleShape enemy_sekil;

};

#endif // ENEMY_H
