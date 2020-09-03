#include            "include/player.h"
#include            "include/color.h"
#include            <iostream>


Player::Player(std::string name, int hp, int atk)
        : playerName(name), playerHp(hp), playerAtk(atk)
{
    //  ctor
}

Player::~Player(){}


void    Player::is_attacked(int dmg)
{
    std::cout<< playerName <<" gets "<<dmg<<" damage <->";
    playerHp = playerHp - dmg;
    std::cout<<" "<< playerName <<" has now \t HP: "<<playerHp<<'\n';
}

void    Player::attacking(Player &other)
{
    if ( is_alive() ){
        std::cout<<'\n';
        std::cout<< playerName << " is attacking "<<other.playerName<<'\n';
        other.is_attacked(playerAtk);
    }
}

bool    Player::is_alive()
{
    return playerHp > 0;
}


int    Player::getHP()
{
    return playerHp;
}

std::string     Player::getName()
{
    return playerName;
}

