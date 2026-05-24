#include "game_manager.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include <math.h>
game_manager::game_manager()
{
pencere.create(sf::VideoMode(1280,720),"Shooter Game");
pencere.setFramerateLimit(60);
if (!harita_resmi.loadFromFile("map.png"))
{}
harita_sprite.setTexture(harita_resmi);
}

void game_manager::run()
{
    srand(time(NULL));
    //added necessery variable
    start:
    sf::Vector2f dusman_konum;//enemy position
    int random=10;//random for orb drop rate initialized with starting value for prevent to garbage value
    int skor=0;//score
    p1.can_sifirla();//when game will be restarted players health will be 100 again
    enemies.clear();//when game will be restarted remaining enemies will be cleared from screen
    bullets.clear();//when game will be restarted remaining bullets will be cleared from screen
    can.clear();//clears orbs
    hiz.clear();
    damage.clear();
    sf::Clock mola1//for the power up timings
    ;sf::Clock mola;
    int dalga_sayisi=0;//wave counter
    int enemy_miktar=10;//starting value of enemies
    sf::Vector2f mermi_konum;//bullet position
    sf::Vector2f player_konum;//player position
    sf::Vector2i mouse_position;
    sf::Vector2f player_konum_initial;
    player_konum_initial.x=p1.getPosition_x();
    player_konum_initial.y=p1.getPosition_y();
    int counter=1;//for the calculations of the loop
    oyun_bitti=false;//game ends
    oyun_basladi=false;//game starts
    bool dmg_buff=false;
    while(pencere.isOpen()){
            if(oyun_basladi==false){
                  sf::Event olay;
                  //while window is open if user press to esc exits r to start
        while(pencere.pollEvent(olay))
        {
            printf(".");
                  if (olay.type == sf::Event::KeyPressed) {
        if (olay.key.code == sf::Keyboard::R) {
           oyun_basladi=true;
        }
                  }
                 if (olay.type == sf::Event::KeyPressed) {
        if (olay.key.code == sf::Keyboard::Escape) {
           exit(0);
        }
                 }
            if(olay.type==sf::Event::Closed)
            {
                pencere.close();
            }
        }
        sf::Font benim_fontum;
        if (!benim_fontum.loadFromFile("ROG Fonts STRIX SCAR Regular.ttf"))
{
}
        sf::Text welcome;
        sf::Text made;
        welcome.setFont(benim_fontum);
        welcome.setString("Welcome to the Shooter Game!!");
        welcome.setCharacterSize(45);
        welcome.setStyle(sf::Text::Bold);
        welcome.setFillColor(sf::Color::White);
        welcome.setPosition(125.f, 300.f);
        made.setFont(benim_fontum);
        made.setString("Made By Kayra Donmez\n press R to start ESC to exit...");
        made.setCharacterSize(20);
        made.setStyle(sf::Text::Italic);
        made.setFillColor(sf::Color::White);
        made.setPosition(125.f, 400.f);
        pencere.clear(sf::Color::Black);
        pencere.draw(welcome);
        pencere.draw(made);
        pencere.display();

                                    }
    else{
    if(oyun_bitti==false){
        sf::Event olay;
        while(pencere.pollEvent(olay))
            {

                printf(".");
            if(olay.type==sf::Event::Closed)
            {
                pencere.close();
            }
        }
        //wave relatable enemy amount
        //enemies must be created once when the wave is over
        if(enemies.size()==0)
        {
            if(counter%300==0)
            {
                dalga_sayisi++;
             if(dalga_sayisi==1)
        {
            enemy_miktar=5;
        }else
        {
            enemy_miktar+=dalga_sayisi;
            skor+=10*dalga_sayisi;
        }
        //enemies will come every wall on the screen
             for(int i=0;i<enemy_miktar;i++)
        {
            enemy dusman;
            dusman.setPosition();
            dusman.wave_speed();
            enemies.push_back(dusman);
        }
    }
}

        //enemies will move to the player constantly
        for(int i=0;i<enemies.size();i++)
        {
        player_konum.x=p1.getPosition_x();
        player_konum.y=p1.getPosition_y();
            enemies[i].hareket_et(player_konum);
        }
        //framerate limit set to 165 that means 60 loop per second so counter will increase 60 per second but  while player holding the left button 60/10  6 bullets per second
        if(counter%10==0){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
        player_konum.x=p1.getPosition_x()-25;
        player_konum.y=p1.getPosition_y()+5;
        mouse_position=sf::Mouse::getPosition(pencere);
        bullet yeni_mermi;
        if(dmg_buff==true)
        {
            yeni_mermi.dmg_up();
        }
        yeni_mermi.setPosition(player_konum);
        mermi_konum.x=yeni_mermi.getPosition_x();
        mermi_konum.y=yeni_mermi.getPosition_y();
        yeni_mermi.move_mermi(mouse_position,player_konum);
        yeni_mermi.buraya_bak(mouse_position,mermi_konum);
        bullets.push_back(yeni_mermi);
        }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            p1.changePosition_xright();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            p1.changePosition_xleft();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            p1.changePosition_ydown();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            p1.changePosition_yup();
        }
        //bullets direction is mouses location
        for(int i=0;i<bullets.size();i++)
        {
            bullets[i].mermi_hareket();
        }
        //delete bullets that out of the screen to prevent memory leak
        for(int i=0;i<bullets.size();i++)
        {
            if(bullets[i].temizle())
                bullets.erase(bullets.begin() + i);
        }
        //controls every bullet and every enemy to analyze crash and deletes hp 0 enemies and crashed bullets
            for(int i=0;i<enemies.size();i++)
            {
                for(int j=0;j<bullets.size();j++)
                {
                    mermi_konum.x=bullets[j].getPosition_x();
                    mermi_konum.y=bullets[j].getPosition_y();
                    enemies[i].mermi_carpti(mermi_konum,bullets[j].dmg_dondur());
                    if(enemies[i].mermi_sil(mermi_konum))
                    {
                        bullets.erase(bullets.begin() + j);

                    }
                    if(enemies[i].can_kac())
                    {
                        dusman_konum.x=enemies[i].getposition_x();
                        dusman_konum.y=enemies[i].getposition_y();
                        //its like rolling a dice if conditions met enemy drops a power up orb
                         random=rand()%20;
                         power_up power;
                        switch(random)
                        {
                        case 0:

                            power.can(dusman_konum);
                            can.push_back(power);
                            if(power.carpti_mi(p1.getGlobalbounds()))
                            {
                                p1.can_artir();
                            }

                        break;
                        case 1:
                            power.hiz(dusman_konum);
                            hiz.push_back(power);
                        break;
                        case 3:
                            power.dmg(dusman_konum);
                            damage.push_back(power);
                            break;
                        default:
                            break;
                        }
                        enemies.erase(enemies.begin()+i);
                        i--;
                        skor+=120;
                        break;

                    }
                }
            }
            //conrtols if orbs contacts with player and starts to working
            for(int i=0;i<can.size();i++)
            {
                        if(can[i].carpti_mi(p1.getGlobalbounds())){
                                p1.can_artir();
                                p1.can_kontrol();
                      can.erase(can.begin()+i);
                                i--;
                        }
            }
             for(int i=0;i<hiz.size();i++)
            {
                        if(hiz[i].carpti_mi(p1.getGlobalbounds())){
                                mola1.restart();
                                p1.hiz_artir();
                      hiz.erase(hiz.begin()+i);
                                i--;
                        }
            }
            if(mola1.getElapsedTime().asSeconds()>10)
                            {
                                p1.hiz_azalt();
                                mola1.restart();
                            }
             for(int i=0;i<damage.size();i++)
            {
                        if(damage[i].carpti_mi(p1.getGlobalbounds())){
                                for(int j=0;j<bullets.size();j++)
                                {
                                    bullets[j].dmg_up();
                                }
                                dmg_buff=true;
                                mola.restart();
                      damage.erase(damage.begin()+i);
                                i--;
                        }
            }
            if(mola.getElapsedTime().asSeconds()>5)
                            {
                               for(int j=0;j<bullets.size();j++)
                                {
                                    bullets[j].dmg_down();
                                }
                                dmg_buff=false;
                                mola.restart();
                            }
            // stack preventer
for (int i = 0; i < enemies.size(); i++)
{
    for (int j = i + 1; j < enemies.size(); j++)
    {

        if (enemies[i].getGlobalBounds().intersects(enemies[j].getGlobalBounds()))
        {

            sf::Vector2f posI = enemies[i].getPosition();
            sf::Vector2f posJ = enemies[j].getPosition();
            sf::Vector2f itme_yonu = posI - posJ;
            float mesafe = sqrt(itme_yonu.x * itme_yonu.x + itme_yonu.y * itme_yonu.y);
            if (mesafe == 0) mesafe = 0.1f;
            sf::Vector2f normal_itme = itme_yonu / mesafe;
            float itme_gucu = 0.3f;
            enemies[i].itil(normal_itme * itme_gucu);
            enemies[j].itil(-normal_itme * itme_gucu);
        }
    }
}
              for(int i=0;i<enemies.size();i++){
            player_konum.x=p1.getPosition_x();
                player_konum.y=p1.getPosition_y();
                if(enemies[i].oyuncu_carpti(player_konum))
                {
                    if(counter%120==0)
                    p1.can_azalt();
                }
              }
              for (int i = 0; i < enemies.size(); i++)
              {
                   if (enemies[i].getGlobalBounds().intersects(p1.getGlobalbounds())){
                sf::Vector2f konum;
                konum.x=p1.getPosition_x();
                konum.y=p1.getPosition_y();

                  sf::Vector2f posI = enemies[i].getPosition();
                   sf::Vector2f itme_yonu = posI - konum;
                    float mesafe = sqrt(itme_yonu.x * itme_yonu.x + itme_yonu.y * itme_yonu.y);
            if (mesafe == 0) mesafe = 0.1f;
            sf::Vector2f normal_itme = itme_yonu / mesafe;
            float itme_gucu = 2.0f;
            enemies[i].itil(normal_itme * itme_gucu);
              }
    }
    {
        player_konum.x=p1.getPosition_x();
        player_konum.y=p1.getPosition_y();
        mouse_position=sf::Mouse::getPosition(pencere);
        p1.karakteri_dondur(mouse_position,player_konum);
    }

            //clear the previous info and draw new info and print to the screen
        pencere.clear(sf::Color::White);
        pencere.draw(harita_sprite);
        if(enemies.size()==0 && counter%300!=0)
        {
                  sf::Font benim_fontum;
        if (!benim_fontum.loadFromFile("ROG Fonts STRIX SCAR Regular.ttf"))
{
}
             sf::Text dalga;
        dalga.setFont(benim_fontum);
        dalga.setString("Wave:"+ std::to_string(dalga_sayisi+1));
        dalga.setCharacterSize(25);
        dalga.setStyle(sf::Text::Regular);
        dalga.setFillColor(sf::Color::Green);
        dalga.setPosition(325.f, 100.f);
            pencere.draw(dalga);
        }
        sf::Font benim_fontum;
              if (!benim_fontum.loadFromFile("ROG Fonts STRIX SCAR Regular.ttf"))
{
}
               sf::Text skori;
        skori.setFont(benim_fontum);
        skori.setString("Score:"+ std::to_string(skor));
        skori.setCharacterSize(25);
        skori.setStyle(sf::Text::Regular);
        skori.setFillColor(sf::Color::Green);
        skori.setPosition(1000.0f, 0.0f);
            pencere.draw(skori);
                  sf::Text hp;
        skori.setFont(benim_fontum);
        skori.setString("health:"+ std::to_string(p1.can_dondur()));
        skori.setCharacterSize(25);
        skori.setStyle(sf::Text::Regular);
        skori.setFillColor(sf::Color::Green);
        skori.setPosition(0.0f, 0.0f);
            pencere.draw(skori);
            p1.can_cizim(p1,pencere);
           p1.draw(pencere);
       for(int i=0;i<bullets.size();i++)
        {
            bullets[i].draw_screen(pencere);
        }
        for(int i=0;i<enemies.size();i++)
        {
            enemies[i].yazdir(pencere);
        }
        for(int i=0;i<can.size();i++)
        {
            can[i].yazdir(pencere);
        }
        for(int i=0;i<hiz.size();i++)
        {
            hiz[i].yazdir(pencere);
        }
        for(int i=0;i<damage.size();i++)
        {
            damage[i].yazdir(pencere);
        }
         pencere.display();
        counter++;
        if(counter>=600)
        {
           counter=0;
        }
            if(p1.can_yok())
              {
                  oyun_bitti=true;
              }
    }
      else{
         while(pencere.isOpen()){
         sf::Event Olay;
        while(pencere.pollEvent(Olay))
        {
            printf(".");
                if (Olay.type == sf::Event::KeyPressed) {
        if (Olay.key.code == sf::Keyboard::B) {
            goto start;
        }
           }        if (Olay.type == sf::Event::KeyPressed) {
        if (Olay.key.code == sf::Keyboard::Escape) {
            exit(0);
        }
           }
            if(Olay.type==sf::Event::Closed)
            {
                pencere.close();
            }
        }
        sf::Font benim_fontum;
        sf::Text game_over_yazisi;
        sf::Text tekrar_mi;
        if (!benim_fontum.loadFromFile("ROG Fonts STRIX SCAR Regular.ttf"))
{
}
game_over_yazisi.setFont(benim_fontum);
tekrar_mi.setFont(benim_fontum);
tekrar_mi.setString("Play again?\n Press ESC to exit Press B to play again...");
tekrar_mi.setCharacterSize(30);
tekrar_mi.setStyle(sf::Text::Italic);
tekrar_mi.setFillColor(sf::Color::Black);
tekrar_mi.setPosition(325.f, 400.f);
        game_over_yazisi.setString("GAME OVER");
game_over_yazisi.setCharacterSize(75);
game_over_yazisi.setFillColor(sf::Color::Black);
game_over_yazisi.setStyle(sf::Text::Bold);
game_over_yazisi.setPosition(325.f, 300.f);
        pencere.clear(sf::Color::Red);
        pencere.draw(game_over_yazisi);
        pencere.draw(tekrar_mi);
        pencere.display();

                }
            }
        }
    }
}
