# SpaceShooterGame

<hr>

# Description
Take control of a spaceship in this classic arcade-style game, where you battle through waves of enemies and monsters. Upgrade your ship, collect power-ups, and unleash special abilities to conquer challenging bosses. Developed in C++ using SFML, this game leverages Object-Oriented Programming principles, delivering smooth graphics and immersive sound effects.

<hr>

# Features:
Object-Oriented Design: The game is built around core Object-Oriented Programming concepts, minimizing reliance on SFML's built-in graphics and focusing on custom mathematical procedures for visuals and animations.<br>

Three Massive Levels: Each level consists of multiple phases with increasing difficulty, featuring three types of enemies: Alpha Invaders, Beta Invaders, and Gamma Invaders.<br>

Diverse Shapes and Challenges:<br>

Level 1: Includes basic shapes like rectangles, triangles, and crosses.<br>
Level 2: Introduces more complex shapes such as circles, diamonds, and hearts.<br>
Level 3: Combines both basic and advanced shapes, but these shapes are filled for added complexity.<br>
Epic Boss Fights: Face off against formidable bosses, including Monsters, Dragons, and a hidden secret boss, each with unique attack patterns and strategies.<br>

Lives System: Players have 3 lives before their ship is destroyed, adding to the challenge.<br>

Powerful Addons: Collect random addons such as Life, Danger Sign, PowerUp, and Enhanced Fire, which temporarily upgrade your ship and weapons.<br>

Scoring and Highscores: The game tracks your score, saving the top 3 highscores with file handling via the fstream library. Top scorers earn medals displayed during gameplay.<br>

Immersive Details and Effects:<br>

Galaxy Environment: The game features a wrap-around galaxy where your ship disappears at one edge and reappears on the opposite side.<br>
Additional Effects: Includes periodic ship damage, screen shake, and other detailed animations.<br>
Audio and Sound Effects: Enjoy fully functional audio with an option to toggle music on or off from the menu.<br>

Comprehensive Screens: The game includes multiple screens for an immersive experience:<br>

Game Menu<br>
Instructions<br>
Main Gameplay<br>
Pause Functionality<br>
High Score and Player Name Display<br>
End Screen<br>

# Here are some images:


![image](https://github.com/user-attachments/assets/55ec54f4-5371-4825-bb22-1a02c5606930)



![image](https://github.com/user-attachments/assets/26434cc5-1678-4939-89d4-58f1d2e09fd0)

![image](https://github.com/user-attachments/assets/c89bbaee-64c3-485d-8870-a0a1544fab31)

![image](https://github.com/user-attachments/assets/8dd9824b-5353-4323-a138-b10dd2cf2dc5)

![image](https://github.com/user-attachments/assets/38ccab0a-4abc-4c1d-9157-25b5fd4a5c8d)

![image](https://github.com/user-attachments/assets/32809291-92e9-40d5-ab77-18d0a53d37cd)


# Gameplay Instructions:


In this game, the player pilots a spaceship through a space field filled with enemies. The objective is to destroy enemy ships while avoiding collisions. The spaceship can fire bullets to eliminate obstacles in its path. If the spaceship collides with an enemy or gets hit by a bomb from an enemy ship, it is destroyed.<br> A dragon appears randomly, remaining stationary but firing in three possible directions—downwards, right-downwards, and left-downwards—based on the spaceship's current location. Meanwhile, a monster moves horizontally across the screen, periodically unleashing a beam of lightning at the spaceship.<br> The player can maneuver the spaceship in all directions: right, left, up, down, and diagonally. As an advanced feature, players can activate a power-up mode, rendering the spaceship invincible and enabling it to fire a continuous beam of bullets instead of shooting at intervals.<br> At the start of each game, the shape of the enemies in the space field is randomly selected, and the number of enemies is based on that shape. The next level is unlocked once all enemies in the current field are defeated, with each new level featuring a different shape and an increased number of enemies.<br> Players start with three lives, and a life is lost if the spaceship is destroyed. Points are awarded for each enemy hit, and the remaining lives and current score are displayed at the top of the screen.<br>




