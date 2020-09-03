# [C++] SimpleGame  - Basic
<br>

## Task

Create a basic fight game, in with a Hero will fight against one, two, or more enemy's per act.


<br>


## Criteria
*   Create the blueprint of a Player class and the specific methods of a classic fight game
*   Build the subclasses for the Hero and Enemy
*   Generate and present a random enemy, with a random life and attack power 
*   Create an array(list) of enemy's based on random generation process
*   Describe the fight act and add the perspective of an Enemy/Hero attack per round

*   Implement the actual process of game, add the possibility for the Hero to regenerate it's HP at the end of any fight act and the possibility to select the number of enemy's.
*   End the game when the hero is dead.


<br>


## Summary 
A default hero meets different enemies. 
  
At the beginning of each act, the user decides how many enemies should be in a single act, and if the hero will fight with them or not.
  
The hero will fight against with one enemy for a couple of rounds:
  * at the begging of the fight we will see the status of both players
  * at the end of the fight, after the last round we will see who had won the fight
  
The hero will be able to fight with more than one enemy in a single act. At the end of any act, the hero life will be regenerated if he defeated all the enemy's for the specific act. 

An "act" represent a fight with a set of enemy's and "a round" means alternate blows between the hero and the enemy and the other way around


<br>


### Example of status

|   |Hero|  Enemy  |
|:--|:--:|:-------:|
|HP |200 | 40 - 200|
|ATK|20  |  2 - 30 |
      
<br>

### Run Locally
---
* Run the command `git clone https://github.com/Aandrew94/SimpleGame.git`
* From terminal, navigate into the folder named SimpleGame
* Run `make` 
* After the compile and linked process is complete, tun the application by `./SimpleGame`
* Enjoy :)
