#include            "Header/hero.h"
#include            "Header/exceptions.h"
#include            <iostream>


Hero::Hero (std::string heroName): Player(heroName, 200, 20)
{
    //  ctor
    std::cout<<"\n-=[Hero Info]=-\n";
    std::cout<< "______________________________________\n";
    std::cout<< "| Hello ! I'm "<<heroName<<", the hero :)\n";
    std::cout<< "| HP  : "<<playerHp<<"\n";
    std::cout<< "| ATK : "<<playerAtk<<"\n";
    std::cout<< "\t* * * \n";

}


void    Hero::heal()
{
    playerHp = 200;
    std::cout<<"\n\t [HEALING]\n";
    std::cout<<"\t"<<playerName<<" HP: "<<playerHp<<"\n\n";
}


void    Hero::is_attacked(int dmg)
{
    Player::is_attacked(dmg);

    if ( !is_alive() ){
        throw   DeadHeroException();
    }
}