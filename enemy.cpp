#include            "enemy.h"
#include            <iostream>


Enemy::Enemy(std::string enemyName, int enemyHp, int enemyAtk)
    : Player(enemyName,enemyHp,enemyAtk)
{
    //  ctor
}

Enemy::~Enemy(){}

void    Enemy::enemyInfo()
{
    std::cout<<"-=[Enemy Info]=-\n";
    std::cout<< " ___________________\n";
    std::cout<< "| Name :\t"<<playerName<<"\n";
    std::cout<< "| HP   :\t"<<playerHp  <<"\n";
    std::cout<< "| ATK  :\t"<<playerAtk <<"\n";
    std::cout<< "|___________________\n";
}