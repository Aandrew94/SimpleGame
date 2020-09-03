#include            <iostream>
#include            <ctime>
#include            "include/color.h"
#include            "include/player.h"
#include            "include/hero.h"
#include            "include/enemy.h"
#include            "include/exceptions.h"
#include            "include/base.h"




int main(){

    srand(time(NULL));

    
    Hero e1("Aragon");


    int act{1};
    try{
        while(1){
            std::cout<< BOLD("\n***** Act "<< act <<" *****\n");
            theGame(e1);
            e1.heal();
            std::cout<<'\n';
            act++;
        }
    }   catch (DeadHeroException &hero){
        hero.is_dead();
    }



    return 0;
}