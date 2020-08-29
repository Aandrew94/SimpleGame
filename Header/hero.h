#ifndef             HERO_H
#define             HERO_H

          
#include            <iostream>
#include            "player.h"


class Hero: public Player {
    private:
    

    public:
        Hero(std::string heroName);

        void    heal();
        void    is_attacked(int dmg);

};






#endif              //HERO_H