#ifndef             PLAYER_H
#define             PLAYER_H

#include            <iostream>

class Player{
    protected:
        std::string playerName;
        int         playerHp;
        int         playerAtk;

    public:
        Player(std::string name, int hp, int atk);
        virtual ~Player();

        void    attacking(Player &other);
        virtual void    is_attacked(int dmg);
        bool    is_alive();
        int    getHP();

        friend std::ostream& operator<< (std::ostream &out, const Player &player);

};





#endif              //PLAYER_H