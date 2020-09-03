#include            <iostream>
#include            <cstdlib>
#include            <limits>

#include            "include/color.h"
#include            "include/player.h"
#include            "include/hero.h"
#include            "include/enemy.h"
#include            "include/exceptions.h"
#include            "include/base.h"



//  [Function]  Generate one random enemy
Enemy*  randomEnemyGenerator()      
{
    int hp{};
    int attack{};
    std::string names[] = {"Troll","Gnome","Orc","Devil"};

    std::string theName = names[rand() %4];
    hp = rand()%161 + 40;
    attack = rand()%29 + 2; 
    

    return new Enemy(theName,hp,attack);
}




//  [Function]  Build array of enemys
Enemy**   enemyTeamBuild(int &numberEnemys)
{   
    while(1){       
        std::cout<< "How many enemy do you want ?\t";
        std::cin>> numberEnemys;
    
        if (!numberEnemys || numberEnemys <= 0){
            std::cout << BOLD(FRED("\n[ERROR] Positive Numbers only !\n"));
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        else break;    

    }
        
    Enemy** enemys = new Enemy*[numberEnemys];

    for (int i=0; i<numberEnemys; i++){
        enemys[i] = randomEnemyGenerator();
    }

    return enemys;
}





//  [Function] Fight sequence
void    fight(Player &firstPlayer, Player &secondPlayer)    
{
    int round{1};

    while( firstPlayer.is_alive() && secondPlayer.is_alive() ){
        
        std::cout<< "\n\n\n";
        std::cout<< BOLD(FBLU("\t*** Round "<<round<< " ***"));
        std::cout<<'\n'<< firstPlayer <<": HP = " <<firstPlayer.getHP()<<" | "<<
            secondPlayer <<": HP = "<<secondPlayer.getHP()<<'\n';

        firstPlayer.attacking(secondPlayer);
            if( secondPlayer.is_alive() ){
                secondPlayer.attacking(firstPlayer);
            }

        round++;
    std::cout<< BOLD(FBLU( "\t*** End Round ***\n" ));
    }
    
}




//  [Function] The round - game itself 
void    theGame(Hero &hero)
{
    int numbersEnemys;
    Enemy** arrayEnemy = enemyTeamBuild(numbersEnemys);

    for(int i=0; i<numbersEnemys; i++){

        char startFight;
        
        do{
            std::cout<< "\nThe " << i+1 << "st is a : "<<*(arrayEnemy[i]) << "\n";
            arrayEnemy[i]->enemyInfo();
        
            std::cout<< BOLD(FCYN(" Status Hero:\t "))<< hero <<" HP: "<<hero.getHP()<<'\n';
            std::cout<< BOLD(" Start fight ? \t (Y/N): ");
            std::cin>> startFight;

            if (startFight == 'Y' || startFight == 'y'){
                fight(hero,*arrayEnemy[i]);
                break;
            }
            else if ( startFight == 'N' || startFight == 'n'){
               break;
            }


        }while(startFight != 'Y' || startFight != 'y' || startFight != 'N' || startFight != 'n');


        if ((startFight != 'N' && startFight != 'n') && hero.getHP()){
            std::cout<< BOLD(FWHT( "\n\n\n\t* * * * * * * * * * * * * *\n"));
            std::cout<< BOLD(FWHT( "\t\t" << hero << " WON "));
            std::cout<< BOLD(FWHT( "\n\t* * * * * * * * * * * * * *\n\n\n"));
        }
 
    }

    for(int i=0; i<numbersEnemys ;i++){
        delete arrayEnemy[i];
    }

    delete [] arrayEnemy;

}

