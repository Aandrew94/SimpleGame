#include            "Header/hero.h"
#include            "Header/exceptions.h"
#include            "Header/color.h"
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
    std::cout<< FGRN("\n\t [HEALING]\n");
    std::cout<< FGRN("\t"<<playerName<<" HP: "<<playerHp<<"\n\n");
}


void    Hero::is_attacked(int dmg)
{
    Player::is_attacked(dmg);

    if ( !is_alive() ){
        throw   DeadHeroException();
    }
}