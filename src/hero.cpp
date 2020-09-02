#include            "include/hero.h"
#include            "include/exceptions.h"
#include            "include/color.h"
#include            <iostream>


Hero::Hero (std::string heroName): Player(heroName, 200, 20)
{
    //  ctor
    std::cout<< BOLD(FYEL("\n\t -=[Hero Info]=-\n"));
    std::cout<< BOLD(FYEL("____________________________________\n"));
    std::cout<< BOLD(FYEL("\t| Name: "<<heroName<<"\t |\n"));
    std::cout<< BOLD(FYEL("\t| HP  : "<<playerHp<<"\t |\n"));
    std::cout<< BOLD(FYEL("\t| ATK : "<<playerAtk<<"\t |\n\n"));

}


void    Hero::heal()
{
    playerHp = 200;
    std::cout<< FGRN("\n\t\t   [HEALING]\n");
    std::cout<< FGRN("\t\t "<<playerName<<" HP: "<<playerHp<<"\n\n");
}


void    Hero::is_attacked(int dmg)
{
    Player::is_attacked(dmg);

    if ( !is_alive() ){
        throw   DeadHeroException();
    }
}