#include "enemy.h"
#include <time.h>
#include <math.h>
enemy::enemy()
{
    enemy_sekil.setSize(sf::Vector2f(75.0f,75.0f));
    if (!enemy_texture.loadFromFile("zombie.png"))
    {printf("hata");
    }
    enemy_sekil.setTexture(&enemy_texture);
    enemy_sekil.setFillColor(sf::Color::White);
}


void enemy::mermi_carpti(sf::Vector2f mermi_konum, int hasar)
{
    sf::FloatRect konum=enemy_sekil.getGlobalBounds();
    if (konum.contains(mermi_konum))
      health=health-hasar;
}

int enemy::oyuncu_carpti(sf::Vector2f player_konum)
{
     sf::FloatRect konum=enemy_sekil.getGlobalBounds();
         if (konum.contains(player_konum))
        return true;
    else
        return false;
}
void enemy::hareket_et(sf::Vector2f player_konum)
{
    sf::Vector2f konum=enemy_sekil.getPosition();
    sf::Vector2f fark= player_konum-konum;
    float uzunluk= sqrt(fark.x *fark.x + fark.y * fark.y);
     sf::Vector2f yon_vek=fark/uzunluk;
    enemy_sekil.move(yon_vek*speed);
}
void enemy::yazdir(sf::RenderWindow& pencere)
{
pencere.draw(enemy_sekil);
}
void enemy::setPosition()
{
sf::Vector2f konum;


    int kenar = rand() % 4;

    if (kenar == 0) {
        konum.x = rand() % 1280;
        konum.y = 0;
    }
    else if (kenar == 1) {
        konum.x = rand() % 1280;
        konum.y = 720;
    }
    else if (kenar == 2) {
        konum.x = 0;
        konum.y = rand() % 720;
    }
    else if (kenar == 3) {
        konum.x = 1280;
        konum.y = rand() % 720;
    }

    enemy_sekil.setPosition(konum);
}

int enemy::can_kac()
{
    if(health<=0)
        return true;
    else
        return false;
}
int enemy::mermi_sil(sf::Vector2f mermi_konum)
{
     sf::FloatRect konum=enemy_sekil.getGlobalBounds();
    if (konum.contains(mermi_konum))
        return true;
    else
        return false;

}

void enemy::itil(sf::Vector2f itme_vektoru)
{
    enemy_sekil.move(itme_vektoru);
}

sf::Vector2f enemy::getPosition()
{
    return enemy_sekil.getPosition();
}
sf::FloatRect enemy::getGlobalBounds()
{
    return enemy_sekil.getGlobalBounds();
}
enemy::enemy(const enemy& ornek)
{
    this->enemy_texture = ornek.enemy_texture;
    this->enemy_sekil = ornek.enemy_sekil;
    this->enemy_sekil.setTexture(&this->enemy_texture);
    this->health = ornek.health;
    this->damage=ornek.damage;
}
enemy& enemy::operator=(const enemy& ornek)
{
    if (this != &ornek)
    {
        this->enemy_texture = ornek.enemy_texture;
        this->enemy_sekil = ornek.enemy_sekil;
        this->enemy_sekil.setTexture(&this->enemy_texture);
        this->health = ornek.health;
         this->damage=ornek.damage;
    }
    return *this;
}
int enemy::getposition_x()
{
    sf::Vector2f konum=enemy_sekil.getPosition();
    return konum.x;
}
int enemy::getposition_y()
{
    sf::Vector2f konum=enemy_sekil.getPosition();
    return konum.y;
}
