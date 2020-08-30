#include            "Header/enemy.h"
#include            "Header/color.h"


#include            <iostream>


Enemy::Enemy(std::string enemyName, int enemyHp, int enemyAtk)
    : Player(enemyName,enemyHp,enemyAtk)
{
    //  ctor
}

//Enemy::~Enemy(){}

void    Enemy::enemyInfo()
{
    std::cout<<"\n";
    std::cout<< BOLD(FMAG("\t-=[Enemy Info]=-\n"));
    std::cout<< BOLD(FMAG("____________________________________\n"));
    std::cout<< BOLD(FMAG("\t| Name :\t"<<playerName<<"\n"));
    std::cout<< BOLD(FMAG("\t| HP   :\t"<<playerHp  <<"\n"));
    std::cout<< BOLD(FMAG("\t| ATK  :\t"<<playerAtk <<"\n"));
    std::cout<< "\n\n\n";
}