# ENGG1340-FindingMorty
Group Number: 79
Team members:
1) Pratik Bhattacharjee UID: 3035767425
2) Gurbaksh Kaur        UID: 3035781744



Game Title: Finding Morty!

Basic Information:
    We would like to design our own game called Finding Morty. It’s a text-based game where the player, who plays as a mega-genius scientist called Rick, has to overcome certain obstacles to find his missing grandson Morty, who has been kidnapped by an evil alien.

Description: 
    The Scientist Rick has to move from planet to planet and eventually galaxies to find his grandson Morty.The level of difficulty can be chosen by the player, Easy( 5 galaxies ), Medium (7 galaxies) and Hard ( 9 galaxies). The player can look in all four directions by using commands, and can find chest,power chest, magic doors, equipment shops.

    Features: 
    Chest - Contains either space keys/weapons(rare)/empty.
    Power Chest - Contains weapons/Equipments like Lightsaber/Portal Gun/Gas Mask.
    Magic Doors - Directly takes you to the next galaxy.
    Equipment Shops - Can buy weapons/equipment using space keys.
    
    Weapons/Equipment: Every equipment/weapon has a passcode which needs to be typed by the player within 5 seconds in order to use it.The weapon/equipment available are:
    Gas Mask: Helps you pass through gas planets.
    Lightsaber: Kills aliens
    Portalgun: takes you to the next safe planet.

    Dangers: 
    Gas Planet: Poisonous Gas that can kill Rick.
    Planets with Aliens: Powerful Aliens that can kill Rick.

    Commands:
    look front: looks front
    look back: looks back
    look right: looks right
    look left: looks left
    open chest: opens the chest you are facing
    open door: open door to the next planet
    use gun: uses portal gun to move to the next safe planet
    use mask: uses the gas mask to protect you against gas planets
    use sword: uses the lightsaber to kill enemy aliens
    use keys: uses keys to buy weapons
    see bag: see the weapon/equipment and space keys you have.


    How to Win:
    Pass all obstacles and move through the path with your wit to kill enemy aliens and find grandson Morty.


    Implementation:
        1) The map of the game will be stored in a 2D array via Dynamic memory management.
        2) The path from Rick starting position to Morty's position through the 2D array is going to be randomly generated.
        3)The blocks in the array that do not represent the path, will contain chests/Power chests/Magic Doors/Equipment shops that the player can interact with or move to the             next block/planet in the path.
        4)The user can type in the commands to navigate through the game.
        5)The previous game data of a users can be stored in files to keep track of fastest time to solve the game and also game status.
        6) All the key parts of the game structure and code will be written and tested in seperate files(eg. command input, Map creation, Weapon and Equipment features etc) and            linked together to complete this game.

    Key Programming Features
        1)Generation of random events - This game generates a random path through the 2D array game every time the game is played. The key/passcode for every weapon is also               randomly generated. Equipments/Weapons are also placed randomly thoughout the map.
        2)Data Strusture - We will be using 2D arrays for the map of the game.
        3)Dynamic Memory Management - The data structure in this game is managed by dynamic memory management.
        4)File input/output : Every player will have a seperate file in which their records and previous unfinished game status will be stored.
        5)Multiple file code - Every key feature of this game will be coded in seperate files for better management of the whole code.
 


