# ENGG1340-FindingMorty

Game Title: Finding Morty!

Basic Information:
     It’s a text-based game where the player, who plays as a mega-genius scientist called Rick, has to overcome certain obstacles to find his missing grandson Morty, who has been kidnapped by an evil alien. We had a lot of fun making it, hope you like playing it!!

Description: 
    The Scientist Rick has to move from planet to planet and eventually galaxies to find his grandson Morty.The level of difficulty can be chosen by the player, Easy, Medium and Hard . The player can navigate by using text commands. 

Level of difficulty:(determines the time you get to save yourself from danger.)
    1. Easy - 20 seconds
    2. Medium - 15 seconds
    3. Hard - 10 seconds


    Features: 
    
    Accessible Items:
    Chest - Contains either space keys/weapons(rare)/empty.
    Power Chest - Contains weapons/Equipments like Lightsaber/Portal Gun/Gas Mask.
    Galaxy Stores - Can buy weapons/equipment using space keys.
    
    Weapons/Equipment: 
    (Every equipment/weapon has a passcode which needs to be typed by the player within limited time seconds in order to use it.)The weapon/equipment available are:
    Gas Mask: Helps you pass through gas planets.
    Lightsaber: Kills aliens
    Portalgun: takes you to the next planet.

    Dangers: 
    Gas Planet: Poisonous Gas that can kill Rick.
    Planets with Aliens: Powerful Aliens that can kill Rick.
    

    Commands:
    open chest: opens the chest you are facing
    use portal: move to the next planet
    use portal gun: uses portal gun to move to the next planet
    use gas mask: uses the gas mask to protect you against gas planets
    use light saber: uses the lightsaber to kill enemy aliens
    use store: uses keys to buy weapons from galaxy store
    see bag: see the weapon/equipment and space keys you have.


    How to Win:
    Pass all obstacles and move through the path with your wit to kill enemy aliens and find grandson Morty.
    (This game is not easy, one needs strong memory and wit to win. Averge gameplay takes about 10 minutes.)


    Implementation:
        1) The map of the game will be stored in a 2D array.
        2) Player attributes such as weapons and their attributes were stored in vectors(dynamic memory management)
        3) The path from Rick starting position to Morty's position through the 2D array is going to be randomly generated.
        4)The blocks in the array that do not represent the path, will contain chests/Power chests/Magic Doors/Equipment shops that the player can interact with or move to the             next block/planet in the path.
        5)The user can type in the commands to navigate through the game.
        6)The player attributes change as the user collects spacekeys and weapons.
        7) All the key parts of the game structure and code will be written and tested in seperate files(eg. command input, Map creation, Weapon and Equipment features etc) and            linked together to complete this game.

    Key Programming Features
        1)Generation of random events - This game generates a random path through the 2D array game every time the game is played. The key/passcode for every weapon is also               randomly generated. Chests/Power Chests are also placed randomly thoughout the map.
        2)Data Strusture - We will be using 2D arrays for the map of the game. We will be using vectors for player atttributes as they change as the player progresses in the               game.
        4)Dynamic Memory Management - The player attributes such as weapons and the list of locations in the map are handled through vectors as they change in length due to                random map creation.
        5)File input/output : This is an adventure game where player is provided with a lot of messages to navigate. Most messages are taken as input from external text file to            keep the code clean and easy to handle.
        6)Multiple file code - Every key feature of this game will be coded in 6 seperate c++ files and there are text files for messages, and header files and makefile to run             the game as a whole

 Special feature: The player has to save himself from danger within limited time. This makes the game more intense and cheating free.
 
 Quick Start-
 (Run code in linux terminal)
 To install the game- "make main" and then
 To run the game - "./main"
 
 
 Academy server used for creating/testing game: Academy Server 21

