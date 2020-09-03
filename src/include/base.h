#ifndef                 BASE_H
#define                 BASE_H


//  [Function]  Generate one random enemy
Enemy*  randomEnemyGenerator();


//  [Function]  Build array of enemys
Enemy**   enemyTeamBuild(int &numberEnemys);


//  [Function] Fight sequence
void    fight(Player &firstPlayer, Player &secondPlayer);


//  [Function] The round - game itself 
void    theGame(Hero &hero);




#endif                          //BASE_H