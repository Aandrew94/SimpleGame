#include            <iostream>
#include            <cstdlib>
#include            <ctime>

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
        
        std::cout<< "\n*** Runda "<<runda<< " ***\t\t";
        std::cout<<firstPlayer.getName()<<": HP = " <<firstPlayer.getHP()<<" | "<<
            secondPlayer.getName()<<": HP = "<<secondPlayer.getHP()<<'\n';

        firstPlayer.attacking(secondPlayer);
            if( secondPlayer.is_alive() ){
                secondPlayer.attacking(firstPlayer);
            }

        runda++;
    
    }
}


//  fct constru t array of enemys
Enemy**   enemyTeamBuild(int &numberEnemys)
{
    std::cout<< "How many enemy do you want ?\n";
    std::cin>> numberEnemys;

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
        arrayEnemy[i]->enemyInfo();
        
        std::cout<< "Start fight ? \t (Y/N): ";
        
        char startFight;
        std::cin>> startFight;

        if (startFight == 'Y' || startFight == 'y'){
            fight(hero,*arrayEnemy[i]);
        }
    }

    for(int i=0; i<numbersEnemys ;i++){
        delete arrayEnemy[i];
    }
    delete [] arrayEnemy;
}



int main(){

    srand(time(NULL));
    //int howMany{};
    
    Hero e1("Gigi");


/*   PRESENT THE ENEMYS
    
    std::cout<<"There are "<<howMany<<" enemys\n";

    for(int i=0;i<howMany;i++){
        std::cout<<"\n\n";
        listEnemy[i]->enemyInfo();
        std::cout<<"\n\n";
    }
*/

    int scene{1};
    try{
        while(1){
            std::cout<< "\n***** Scene "<< scene <<" *****\n";
            theGame(e1);
            e1.heal();
            std::cout<<std::endl;
            scene++;
        }
    }   catch (DeadHeroException &hero){
        std::cout<<"\n\n";
        std::cout<<"\t -=[Your hero is dead]=-\n";
        std::cout<<"\t\t \\(X_X)/\n\n";
    }

    return 0;
}