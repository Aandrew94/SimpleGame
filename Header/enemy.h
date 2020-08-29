#ifndef             ENEMY_H
#define             ENEMY_H


#include            <iostream>
#include            "player.h"


class Enemy: public Player{
    private:

    public:
        Enemy(std::string enemyName, int enemyHp, int enemyAtk);

        void    enemyInfo();
        virtual ~Enemy();
};





#endif              //ENEMY_H