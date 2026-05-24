#include "player.h"
#include <SFML/Graphics.hpp>
#include <math.h>
player::player(){

sekil.setFillColor(sf::Color::White);
if(!player_texture.loadFromFile("player.png"))
{}
sekil.setSize(sf::Vector2f(100.0f,100.0f));
sekil.setTexture(&player_texture);
sekil.setPosition(600.0f, 300.0f);
sekil.setOrigin(50.0f,50.0f);
}

void player::draw(sf::RenderWindow& pencere)
{
    pencere.draw(sekil);
}
void player::changePosition_xright(){
sf::Vector2f konum = sekil.getPosition();
sekil.move(speed,0);
if (konum.x > 1280.0f) {
        sekil.setPosition(0.0f, konum.y);
}
}
void player::changePosition_xleft(){
sf::Vector2f konum = sekil.getPosition();
sekil.move(-speed,0);
if (konum.x < 0.0f) sekil.setPosition(1280.0f, konum.y);
}
void player::changePosition_yup(){
    sf::Vector2f konum = sekil.getPosition();
    sekil.move(0,-speed);
    if (konum.y < 0.0f) sekil.setPosition(konum.x, 720.0f);
}
    void player::changePosition_ydown(){

sf::Vector2f konum = sekil.getPosition();
    sekil.move(0,speed);
if (konum.y > 720.0f) sekil.setPosition(konum.x, 0.0f);
    }

    int player::getPosition_x()
    {
        sf::Vector2f konum= sekil.getPosition();
        return konum.x;
    }
      int player::getPosition_y()
    {
        sf::Vector2f konum= sekil.getPosition();
        return konum.y;
    }

    void player::can_azalt()
    {
        health=health-20;
    }

    int player::can_yok()
    {
        if(health<=0)
            return true;
        else
            return false;
    }
    void player::can_sifirla()
    {
        health=100;
        sekil.setPosition(600.0f, 300.0f);
    }

    sf::FloatRect player::getGlobalbounds()
    {
        return sekil.getGlobalBounds();
    }


void player::karakteri_dondur(sf::Vector2i mouse_konum,sf::Vector2f konum_player)
{

     sf::Vector2f mouse_konum_f((float)mouse_konum.x, (float)mouse_konum.y);
    sf::Vector2f fark=mouse_konum_f-konum_player;
    float aci;
    aci=atan2(fark.y,fark.x)*(180/3.14);
    sekil.setRotation(aci);

}

void player::can_artir()
{
    health=health+10;
}
void player::can_kontrol()
{
    if(health>100)
    {
        health=100;
    }
}
void player::hiz_artir()
{
    speed=15.0f;
}
void player::hiz_azalt()
{
    speed=8.0f;
}
int player::can_dondur()
{
    return health;
}
void player::can_cizim(player p1,sf::RenderWindow& pencere)
{

sf::RectangleShape arka_bar(sf::Vector2f(200.0f, 20.0f));
arka_bar.setFillColor(sf::Color(50, 50, 50));

sf::RectangleShape on_bar(sf::Vector2f(200.0f * (p1.can_dondur() / 100.0f), 20.0f));
on_bar.setFillColor(sf::Color::Red);


arka_bar.setPosition(0.0f, 40.0f);
on_bar.setPosition(00.0f, 40.0f);

pencere.draw(arka_bar);
pencere.draw(on_bar);
}
