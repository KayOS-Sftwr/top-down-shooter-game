#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>

class enemy
{
    public:
        enemy();
        enemy(const enemy& ornek);
    void mermi_carpti(sf::Vector2f mermi_konum);
    int oyuncu_carpti(sf::Vector2f player_konum);
    void hareket_et(sf::Vector2f player_konum);
    void setPosition();
    void yazdir(sf::RenderWindow& pencere);
    int can_kac();
    int mermi_sil(sf::Vector2f mermi_konum);
    sf::Vector2f getPosition();
    void itil(sf::Vector2f itme_vektoru);
    sf::FloatRect getGlobalBounds();
    enemy& operator=(const enemy& ornek);
    private:
        int health=100;
        float speed=5.0f;
        int damage=25;
        sf::RectangleShape enemy_sekil;
        sf::Texture enemy_texture;
};

#endif // ENEMY_H
