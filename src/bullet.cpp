#include "bullet.h"
#include <math.h>
bullet::bullet(int dmg, float spd) : damage(dmg), speed(spd)
{
    mermi_sekil.setSize(sf::Vector2f(20.0f,10.0f));
    mermi_sekil.setFillColor(sf::Color::Red);
}

void bullet::draw_screen(sf::RenderWindow& pencere)
{
    pencere.draw(mermi_sekil);
}
void bullet::setPosition(sf::Vector2f konum){

mermi_sekil.setPosition(konum.x,konum.y);
}

void bullet::move_mermi(sf::Vector2i mouse_konum, sf::Vector2f konum_player)
{
    sf::Vector2f mouse_konum_f((float)mouse_konum.x, (float)mouse_konum.y);
    sf::Vector2f fark=mouse_konum_f-konum_player;
    float vector_uzunluk=sqrt(fark.x *fark.x + fark.y * fark.y);
    sf::Vector2f yon_vek=fark / vector_uzunluk;
    mermi_sekil.move(yon_vek.x*speed,yon_vek.y*speed);
}
