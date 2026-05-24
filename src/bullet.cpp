#include "bullet.h"
#include <math.h>
bullet::bullet()
{
    if(!mermi_texture.loadFromFile("mermi.png"))
    {}
    mermi_sekil.setSize(sf::Vector2f(60.0f,45.0f));
    mermi_sekil.setFillColor(sf::Color::White);
    mermi_sekil.setTexture(&mermi_texture);
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
    yon_vek=fark / vector_uzunluk;
}

void bullet::mermi_hareket()
{
     mermi_sekil.move(yon_vek.x*speed,yon_vek.y*speed);
}
void bullet::buraya_bak(sf::Vector2i mouse_konum,sf::Vector2f mermi_konum)
{
     sf::Vector2f mouse_konum_f((float)mouse_konum.x, (float)mouse_konum.y);
     mermi_sekil.setOrigin(30.0f,22.5f);
    sf::Vector2f fark=mouse_konum_f-mermi_konum;
    float aci;
     aci=atan2(fark.y,fark.x)*(180/3.14);
      mermi_sekil.setRotation(aci);

}
int bullet::temizle()
{
    sf::Vector2f konum=mermi_sekil.getPosition();
    if(konum.x>1280 || konum.x<0 || konum.y>720 || konum.y<0)
        return true;
    else
        return false;
}
int bullet::getPosition_x()
{
    sf::Vector2f konum=mermi_sekil.getPosition();
    return konum.x;
}
int bullet::getPosition_y()
{
    sf::Vector2f konum=mermi_sekil.getPosition();
    return konum.y;
}
void bullet::dmg_up()
{
    damage=100;
}
void bullet::dmg_down()
{
    damage=50;
}
bullet::bullet(const bullet& ornek)
{
    this->mermi_texture = ornek.mermi_texture;
    this->mermi_sekil = ornek.mermi_sekil;
    this->mermi_sekil.setTexture(&this->mermi_texture);
    this->damage = ornek.damage;
        this->speed=ornek.speed;
        this->yon_vek=ornek.yon_vek;
}
bullet& bullet::operator=(const bullet& ornek)
{
    if (this != &ornek)
    {
        this->mermi_texture = ornek.mermi_texture;
        this->mermi_sekil = ornek.mermi_sekil;
        this->mermi_sekil.setTexture(&this->mermi_texture);
        this->damage = ornek.damage;
        this->speed=ornek.speed;
        this->yon_vek=ornek.yon_vek;
    }
    return *this;
}
