#include            <iostream>
#include            <cstdlib>
#include            <ctime>
#include            <limits>

#include            "Header/color.h"
#include            "Header/player.h"
#include            "Header/hero.h"
#include            "Header/enemy.h"
#include            "Header/exceptions.h"






Enemy*  randomEnemyGenerator()      //  fct  generate one random enemy 
{
    int hp{};
    int attack{};
    std::string names[] = {"Troll","Gnome","Orc","Devil"};

    std::string theName = names[rand() %4];
    hp = rand()%161 + 40;
    attack = rand()%29 + 2; 
    

    return new Enemy(theName,hp,attack);
}


//  fct fight sequence
void    fight(Player &firstPlayer, Player &secondPlayer)    
{
    int runda{1};

    while( firstPlayer.is_alive() && secondPlayer.is_alive() ){
        
        std::cout<< "\n\n\n";
        std::cout<< BOLD(FBLU("\t*** Round "<<runda<< " ***"));
        std::cout<<'\n'<<firstPlayer.getName()<<": HP = " <<firstPlayer.getHP()<<" | "<<
            secondPlayer.getName()<<": HP = "<<secondPlayer.getHP()<<'\n';

        firstPlayer.attacking(secondPlayer);
            if( secondPlayer.is_alive() ){
                secondPlayer.attacking(firstPlayer);
            }

        runda++;
    std::cout<< BOLD(FBLU( "\t*** End Round ***\n" ));
    }
    
}


//  fct constru t array of enemys
Enemy**   enemyTeamBuild(int &numberEnemys)
{   //  https://www.codespeedy.com/taking-only-integer-input-in-cpp/
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



//  the round - game itself 
void    theGame(Hero &hero)
{
    int numbersEnemys;
    Enemy** arrayEnemy = enemyTeamBuild(numbersEnemys);

    for(int i=0; i<numbersEnemys; i++){

        char startFight;
        
        do{
            std::cout<< "\nThe " << i+1 << "st is a : "<<arrayEnemy[i]->getName() << "\n";
            arrayEnemy[i]->enemyInfo();
        
            std::cout<< BOLD(FCYN(" Status Hero:\t "))<<hero.getName()<<" HP: "<<hero.getHP()<<'\n';
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
            std::cout<< BOLD(FWHT( "\n* * * * * * * * * * * * * *\n"));
            std::cout<< '\t'<< hero.getName() << " WON ";
            std::cout<< BOLD(FWHT( "\n* * * * * * * * * * * * * *\n\n\n"));
        
        }
 
    }

    for(int i=0; i<numbersEnemys ;i++){
        delete arrayEnemy[i];
    }

    delete [] arrayEnemy;

}





int main(){

    srand(time(NULL));

    
    Hero e1("Aragon");



    int scene{1};
    try{
        while(1){
            std::cout<< BOLD("\n***** Area "<< scene <<" *****\n");
            theGame(e1);
            e1.heal();
            std::cout<<'\n';
            scene++;
        }
    }   catch (DeadHeroException &hero){
        hero.is_dead();
    }



    return 0;
}