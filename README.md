# [C++] SimpleGame  - Basic 
 
A hero meets different enemies.

At the beginning of each fight (rounds), the hero decides how many
enemies want to fight.

A fight means alternate blows between the hero and the enemy.

### Example of status
|   |Hero|  Enemy  |
|:--|:--:|:-------:|
|HP |200 | 40 - 200|
|ATK|20  |  2 - 30 |
      




Enemy:
     HP: 40 - 200
     ATK: 2-30

At the end of each battle, the hero regenerates his HP.

We think of the class hierarchy.
As a basic class we will have: Character
And as subclasses: Hero & Enemy
Character:
  - Hero
  - Enemy
* Both sub-classes inherit from the Character

