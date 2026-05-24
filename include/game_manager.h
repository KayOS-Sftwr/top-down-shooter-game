#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <SFML/Graphics.hpp>
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "power_up.h"
using namespace std;
class game_manager
{
    public:
        game_manager();
        void run();
        bool oyun_bitti= false;
        bool oyun_basladi=false;
    private:
    sf::RenderWindow pencere;
    sf::Texture harita_resmi;
    sf::Sprite harita_sprite;
    player p1;
    vector<bullet> bullets;
    vector<enemy> enemies;
    vector<power_up> can;
    vector<power_up> hiz;
    vector<power_up> damage;

};

#endif // GAME_MANAGER_H
