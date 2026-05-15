#include "game_manager.h"
#include <SFML/Graphics.hpp>
#include <time.h>
game_manager::game_manager() : p1(100,5.0f)
{
pencere.create(sf::VideoMode(1280,720),"Shooter Game");
pencere.setFramerateLimit(165);
}

void game_manager::run()
{
    //added necessery variable
    sf::Clock mola;
    int dalga_sayisi=0;
    int enemy_miktar=10;
    sf::Vector2f mermi_konum;
    sf::Vector2f player_konum;
    sf::Vector2i mouse_position;
    sf::Vector2f player_konum_initial;
    player_konum_initial.x=p1.getPosition_x();
    player_konum_initial.y=p1.getPosition_y();
    int counter=1;
    while(pencere.isOpen()){
        sf::Event olay;
        while(pencere.pollEvent(olay))
        {
            printf(".");
           if (olay.type == sf::Event::MouseButtonPressed) {
        if (olay.mouseButton.button == sf::Mouse::Left) {
//        player_konum.x=p1.getPosition_x();
//        player_konum.y=p1.getPosition_y();
//        mouse_position=sf::Mouse::getPosition(pencere);
//        bullet yeni_mermi;
//        yeni_mermi.setPosition(player_konum);
//        yeni_mermi.move_mermi(mouse_position,player_konum);
//        bullets.push_back(yeni_mermi);
//        counter++;
        }
           }
            if(olay.type==sf::Event::Closed)
            {
                pencere.close();
            }
        }
        //wave relatable enemy amount
        //enemies must be created once when the wave is over
        if(enemies.size()==0)
        {

            if(counter%825==0)
            {
                dalga_sayisi++;
             if(dalga_sayisi==1)
        {
            enemy_miktar=10;
        }else
        {
            enemy_miktar+=5*dalga_sayisi;
        }
        //enemies will come every wall on the screen
             for(int i=0;i<enemy_miktar;i++)
        {
            enemy dusman;
            dusman.setPosition();
            enemies.push_back(dusman);
        }
    }
}
//        for(int i=0;i<enemies.size();i++)
//        {
//            enemies[i].getPosition()
//        }
        //enemies will move to the player constantly
        for(int i=0;i<enemies.size();i++)
        {
        player_konum.x=p1.getPosition_x();
        player_konum.y=p1.getPosition_y();
            enemies[i].hareket_et(player_konum);
        }
        //framerate limit set to 165 that means 165 loop per second so counter will increase 165 per second but  while player holding the left button 165/23  7 bullets per second
        if(counter%23==0){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
        player_konum.x=p1.getPosition_x();
        player_konum.y=p1.getPosition_y();
        mouse_position=sf::Mouse::getPosition(pencere);
        bullet yeni_mermi;
        yeni_mermi.setPosition(player_konum);
        yeni_mermi.move_mermi(mouse_position,player_konum);
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
                    enemies[i].mermi_carpti(mermi_konum);
                    if(enemies[i].mermi_sil(mermi_konum))
                    {
                        bullets.erase(bullets.begin() + j);

                    }
                    if(enemies[i].can_kac())
                    {
                        enemies.erase(enemies.begin()+i);
                        break;
                    }
                }
            }
            //clear the previous info and draw new info and print to the screen
        pencere.clear(sf::Color::Blue);
           p1.draw(pencere);
       for(int i=0;i<bullets.size();i++)
        {
            bullets[i].draw_screen(pencere);
        }
        for(int i=0;i<enemies.size();i++)
        {
            enemies[i].yazdir(pencere);
        }
         pencere.display();
        counter++;
        if(counter==825)
            counter=0;
    }
}
