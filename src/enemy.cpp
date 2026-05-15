#include "enemy.h"
#include <time.h>
#include <math.h>
enemy::enemy()
{
    enemy_sekil.setFillColor(sf::Color::Black);
    enemy_sekil.setSize(sf::Vector2f(25.0f,25.0f));
}


void enemy::mermi_carpti(sf::Vector2f mermi_konum)
{
    sf::FloatRect konum=enemy_sekil.getGlobalBounds();
    if (konum.contains(mermi_konum))
      health=health-50;
}

int enemy::oyuncu_carpti(sf::Vector2f player_konum)
{
     sf::Vector2f konum=enemy_sekil.getPosition();
         if (player_konum==konum)
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

//int enemy::getPosition()
//{
//    sf::IntRect konum=enemy_sekil.getGlobalBounds();
//    return konum;
//}
