# SpaceShooterGame
<hr>

# Description
A classic game where you control a spaceship and fight and score against hordes of enemies and monsters. You can upgrade your ship, collect power- ups and use special abilities to defeat the bosses. This game is created with C++ and SFML using Object Oriented Programming techniques and features smooth graphics and sound effects.
<hr>

# Features:
The game is primarily designed to utilize Object Oriented Programming concepts. Therefore it relies very little on the pre-defined SFML features of graphics, but the core mathematical procedures in the code, which produce the visuals and the animations.
<br>
Three huge levels with variety of phases with difficulty increase in each phase. The phases in each level include three types of enemies: Alpha Invaders, Beta Invaders and Gamma Invaders.
<br>
Each phase has different shapes. Level 1 includes the preliminary shapes such as rectangle, triangle and cross sign. Level 2 includes the advanced shapes such as circle, diamond and heart. Level 3 includes the combination of both the preliminary and advanced shapes but these shapes would be filled.
<br>
Boss fights, including Monsters, Dragons and a secret boss. Each boss has different patterns and different kind of attacks they can damage the player with.
<br>
Lives system, there are 3 Lives a player has, before the ship blasts.
<br>
Player can make use of addons, which fall at random intervals from above. Included addons: Life, Danger Sign, PowerUp, Enhanced Fire. Player ship and Bullets are upgraded according to the addon gained temporarily.
<br>
Scoring functionality, the highscores are saved using File Handling utilizing fstream library. The top 3 positions are awarded medals which can are displayed when they are playing the game.
<br>
Many misc details and animations, such as the galaxy is a wrap-around environment for the spaceship i.e., a spaceship disappears at one corner of the screen and then reappears from the exact opposite corner, periodic damage to the ship, and screen shake etc.
<br>
The game features fully functional audio and sound effects. Music can be turned on or off from the menu.
<br>
The game includes following screens:
<br>
Game Menu screen
<br>
Instructions screen
<br>
Main Screen for gameplay
v
Pause Screen/Functionality
<br>
High Score and Players Names Display
<br>
End screen
<br>

# Here are some images:


![image](https://github.com/user-attachments/assets/55ec54f4-5371-4825-bb22-1a02c5606930)



![image](https://github.com/user-attachments/assets/26434cc5-1678-4939-89d4-58f1d2e09fd0)

![image](https://github.com/user-attachments/assets/c89bbaee-64c3-485d-8870-a0a1544fab31)

![image](https://github.com/user-attachments/assets/8dd9824b-5353-4323-a138-b10dd2cf2dc5)

![image](https://github.com/user-attachments/assets/38ccab0a-4abc-4c1d-9157-25b5fd4a5c8d)

![image](https://github.com/user-attachments/assets/32809291-92e9-40d5-ab77-18d0a53d37cd)


# Gameplay Instructions:


The player of the game controls a spaceship in an enemy filled space field. The goal is to destroy the enemy ships, avoiding a collision with any of them. The spaceship can fire bullets to destroy the objects in the space field. The spaceship is destroyed in case of a collision with an object (enemy ships) or impact with a bomb fired by the enemy ship. Similarly, the dragon appears after a random interval whereby its position is fixed, however, it could fire in 3 directions (downwards, right-downwards and left-downwards). The direction of the fire would also be decided on the basis of the position of the spaceship i.e. the dragon would fire in the zone where the spaceship is currently located. On the other hand, the monster’s vertical position is fixed however it can move in left and right directions. The monster will throw a beam of lightning on the spaceship after regular intervals.
<br>
The player can move the spaceship in any direction (right, left, up, down and diagonally). The spaceship moves in all possible directions. As an advanced move, a player can boost the spaceship into powerup mode, i.e. a spaceship cannot be destroyed and fire a continuous beam of bullets instead of periodic intervals. At the start of the game, the shape of the enemies in the space field is randomly selected. The number of enemies will be selected on the basis of that shape. Next level is achieved once all enemies in the current field are destroyed. The next level starts with a different shape and an increased number of enemies in the space field. The player is awarded three lives initially. A life is decreased if the spaceship is destroyed. The player gets points for hitting the objects. The number of remaining lives, and the score is displayed on the top of the screen.




