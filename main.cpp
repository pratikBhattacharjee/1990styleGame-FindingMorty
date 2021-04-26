#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include "map.h"
#include "help.h"
#include "chestandstore.h"
#include "store.h"
#include "danger.h"
//#include "movement.h"

using namespace std;

//Defining the user defined classes and structs
struct Weapon{//Struct for weapons
  string type;
  int password;
};
vector<Weapon> weapons;//declaring weapon vecttor
vector<string> planets;//stores list of planets
vector<string> galaxies;//stores list of galaxies

struct Position{//Position struct
  int row;
  int col;
};

void welcomeMessage(){
  //Welcome message;
  string line = "";//for reading each lin
  ifstream fin;
  fin.open("welcome.txt");//opening the file for reading
  while(getline(fin,line)){
    cout<<line<<endl;
  }
  fin.close();//
}

//function to search items in in map
void fetchitem(int map[][8], Position Pos, Position &findPos, int val){
  for(int row = Pos.row -1;row <= Pos.row +1;row++){//scanning rows
    if(row < 0 || row>7){//if out of map range
      continue;
    }
    for(int col = Pos.col-1;col<= Pos.col+1; col++){//scanning columns
      if(col<0 || col>7){//if out of map range
        continue;
      }
      if(col == Pos.col && row == Pos.row)//avoid player position
        continue;

      if((row == Pos.row || col == Pos.col)){
          if (map[row][col] == val){//item found
            findPos.row = row;
            findPos.col = col;
          }
    }
    }
  }
}

//function to create weapons
void createweapon(int val){
  Weapon n;//create new weapon
  if(val == 0 )
    n.type = "GAS MASK";
  if(val == 1 )
    n.type = "LIGHT SABER";
  if(val == 2 )
    n.type = "PORTAL GUN";
  n.password = createPass();//Generate random password
  weapons.push_back(n);//add weapon to vector
  //Weapon information to player
  cout<<"****************"<<endl;
  cout<<"YOU GOT: "<<n.type<<endl;
  cout<<"PassWord: "<<n.password<<endl;
  cout<<"****************"<<endl;
}

bool checkbag(string item){//check for item
  vector<Weapon>::iterator iter;//iterator to loop through weapon vector
  for(iter = weapons.begin();iter != weapons.end();iter++){
    if((*iter).type == item){
      return true;
    }
  }
  return false;
}
bool useWeapon(int pass,string type){//using weapon
  vector<Weapon>::iterator iter2;
  for(iter2 = weapons.begin();iter2 != weapons.end();iter2++){
    if((*iter2).type == type && (*iter2).password == pass){//matching password
      (*iter2).type = "NULL";
      return true;
    }
  }
  return false;
}
//Read all locations from location text file and store locations in vectors
void readLocation(){
  string line = "";//To read each line
  ifstream fin;
  fin.open("location.txt");//open file to read
  int count = 1;
  while(getline(fin,line)){//read each line
    if(count<=4){
      galaxies.push_back(line);//adding to vector galaxies
    }else{
      planets.push_back(line);//adding to vector planets
    }
    count++;
  }
}
//Printing location of player in the map.
//Example: You are in Milky Way. Planet: Mars
void printLocation(int row,int col){
  cout<<"You are in ";
  if(row>5){
    cout<<galaxies[0]<<" Galaxy. ";
    cout<<"Planet: ";
    cout<<planets[col]<<"."<<endl;
  }else{
    if(row>3){
      cout<<galaxies[1]<<" Galaxy. ";
      cout<<"Planet: ";
      cout<<planets[7+col]<<"."<<endl;
    }else{
      if(row>1){
        cout<<galaxies[2]<<" Galaxy. ";
        cout<<"Planet: ";
        cout<<planets[14+col]<<"."<<endl;
      }else{
        cout<<galaxies[3]<<" Galaxy. ";
        cout<<"Planet: ";
        cout<<planets[21+col]<<"."<<endl;
      }
    }
  }
}

//declaring functions
void clearItem(int map[][8], Position Pos);
void startPos(int map[][8], Position &pos);

//the mainfunction
int main(){
  welcomeMessage();//welcome message
  //Enter name
  cout<<endl;
  string name = "";
  cout<<"ENTER YOUR NAME: ";//Enter player name
  cin>>name;
  cout<<endl;

  //setting difficulty
  double timeAllowed = 0;
  char difficulty = 'a';
  while(true){
  cout<<"DIFFICULTIES: (1)EASY (2)MEDIUM (3)HARD"<<endl;
  cout<<"Enter Number: ";
  cin>>difficulty;
  if(difficulty == '1' || difficulty == '2' || difficulty == '3')
    break;
  }
  if(difficulty =='1'){
    timeAllowed = 20;//time allowed 20second
    cout<<"YOU HAVE 20 seconds to save yourself from a danger!!"<<endl;
  }
  if(difficulty =='2'){
    timeAllowed = 15;//time allowed 15 seconds
    cout<<"YOU HAVE 15 seconds to save yourself from a danger!!"<<endl;
  }
  if(difficulty =='3'){
    timeAllowed = 10;//time allowed 10 seconds
    cout<<"YOU HAVE 10 seconds to save yourself from a danger!!"<<endl;
  }
  //map creation
  int map[8][8] = {0};//initialising the map array
  createmap(map);//creating the map
  printmap(map);//For the purpose of checking the map

  readLocation();//Read location from location file
  //Creating variables for gameplay
  bool alive = true;
  bool mortyFound = false;
  Position pos;//Player Position
  Position findPos;//Position of search item
  int spacekeys = 0;//space key count
  int result = 0;
  string command = "";//user command
  int isdanger = 0;
  int maxChance = 2;
  int chances = 0;
  int enterPassword = 0;
  time_t dangerStart;//for storing time when danger start
  time_t dangerEnd;//storing time when danger ends
  time_t gameStart;//storing time when game starts
  time_t gameEnd;//storing time when game ends
  int diff = 0;//for storing time diff
  bool itemFound = false;//check for item found

  gameStart = time(NULL);
  //player starting point
  startPos(map, pos);//starting position
  //print starting point
  printLocation(pos.row,pos.col);

  //checking items available in the planet
  cout<<"Items Available: ";
  findPos.row = 10;
  findPos.col = 10;
  itemFound = false;
  fetchitem(map,pos,findPos, 10);//search for chest

  if(findPos.row != 10 || findPos.col != 10){//If chest found!!
    cout<<"CHEST ";
    itemFound = true;
  }
  findPos.row = 10;
  findPos.col = 10;
  fetchitem(map,pos,findPos, 20);//search for power chest
  if(findPos.row != 10 || findPos.col != 10){//If power chest found!!
    cout<<"POWER CHEST ";
    itemFound = true;
  }
  if(itemFound == false){
    cout<<"NONE";
  }
  itemFound = false;
  cout<<endl;

  while(true){
    if(pos.row == 0){//Morty found
      mortyFound = true;
      break;
    }
    //Check if danger planet
    if (map[pos.row][pos.col] != 1){//danger
      chances++;
      if(chances == maxChance){//check if user input wrong input
        alive  = false;//player dead : Game OVER
        break;
      }
      isdanger = map[pos.row][pos.col];//check danger type
      dangerPicture(isdanger);
      dangerStart = time(NULL);//start time
    }

    //Reading User input
    command = "";

    cout<<"***********------**********"<<endl;
    cout<<"ENTER COMMAND: ";
    while (true){
    getline(cin,command);
    if(command.length()>2){
      break;
    }
  }

    cout<<endl;
    //intitialising search positions
    findPos.row = 10;
    findPos.col = 10;

    if (command == "help"){//help command
      printHelp();//prints out instruction
    }

    if(command == "quit"){//for quitting the game
      break;
    }

    if(command == "open chest"){//for opening normal chest
      fetchitem(map,pos,findPos, 10);//search for chest

      if(findPos.row == 10 || findPos.col == 10){//If no chest found!!
        cout<<"No Chest Found!!"<<endl;
      }else{
        clearItem(map,findPos);//removing the chest
        result = normalChest(spacekeys);
        if (result == 10){
          spacekeys = spacekeys + 10;//adding space keys
          cout<<"***********************"<<endl;
          cout<<"YOU GOT: 10 spacekeys!"<<endl;
          cout<<"***********************"<<endl;
        }else{
          createweapon(result);//for creating weapon
        }
      }

    }

    if(command == "open power chest"){//for opening power chest
      fetchitem(map,pos,findPos, 20);//searching for power chest
      if(findPos.row == 10 || findPos.col == 10){
        cout<<"No Power Chest Found!!"<<endl;
      }else{
        clearItem(map,findPos);//remove chest
        result = powerChest();
        createweapon(result);//create weapon
      }
    }


    if(command == "use portal"){//to move to the next portal
      if (map[pos.row][pos.col] == 1){//checks if danger free
      fetchitem(map,pos,findPos, 1);//looking for next planet
      if(findPos.row == 10 || findPos.col == 10){
        fetchitem(map,pos,findPos, 15);//check for gas planet

      }
      if(findPos.row == 10 || findPos.col == 10){
        fetchitem(map,pos,findPos, 16);//check for gas planet

      }
      //move to next planet
      clearItem(map,pos);//clear previous position
      pos.row = findPos.row;
      pos.col = findPos.col;


      //print new locations
      printLocation(pos.row,pos.col);

      //checking items available in the planet
      cout<<"Items Available: ";
      findPos.row = 10;
      findPos.col = 10;
      itemFound = false;
      fetchitem(map,pos,findPos, 10);//search for chest

      if(findPos.row != 10 || findPos.col != 10){//If chest found!!
        cout<<"CHEST ";
        itemFound = true;
      }
      findPos.row = 10;
      findPos.col = 10;
      fetchitem(map,pos,findPos, 20);//search for power chest
      if(findPos.row != 10 || findPos.col != 10){//If power chest found!!
        cout<<"POWER CHEST ";
        itemFound = true;
      }
      if(itemFound == false){
        cout<<"NONE";
      }
      itemFound = false;
      cout<<endl;

    }else{
      cout<<"CLEAR DANGER FIRST!!"<<endl;
    }
  }


    if (command == "use store"){//using store
      if(map[pos.row][pos.col] != 1){
        cout<<"CLEAR DANGER FIRST!!"<<endl;
      }else{
        result = equipmentStore(spacekeys);//function to help buy equipment
        if(result == 1)
          createweapon(0);//creates a gas mask
        if(result == 2)
          createweapon(1);//creates a light saber
        if(result == 3)
          createweapon(2);//creates a portal gun
      }
    }
    if(command == "see bag"){//checks inventory
      cout<<"******YOUR BAG*******"<<endl;
      cout<<"SPACE KEYS: "<<spacekeys<<endl;
      cout<<"WEAPON BAG: ";
      int mask = 0;//gas mask dangerCount
      int saber = 0;//light saber dangerCount
      int gun = 0;//portal gun count
      vector<Weapon>::iterator itr = weapons.begin();//loop through weapon vector
      for(itr = weapons.begin();itr != weapons.end();itr++){
        if((*itr).type == "GAS MASK")
          mask++;
        if((*itr).type == "LIGHT SABER")
          saber++;
        if((*itr).type == "PORTAL GUN")
          gun++;
      }
      if (mask > 0){
        cout<<"GAS MASK("<<mask<<") ";
      }
      if (saber > 0){
        cout<<"LIGHT SABER("<<saber<<") ";
      }
      if (gun > 0){
        cout<<"PORTAL GUN("<<gun<<") ";
      }
      if (mask == 0 && saber == 0 && gun == 0)//No weapons
        cout<<"NO WEAPONS IN THE BAG!";
      cout<<endl;
    }

    //Using gas mask
    if (command == "use gas mask"){
      if(isdanger != 15){
        cout<<"No need to use mask!!"<<endl;
      }else{
        if(checkbag("GAS MASK")){//check if gas mask available
          cout<<"MASK READY!!"<<endl;
          cout<<"Enter password: ";
          cin>>enterPassword;
          if (useWeapon(enterPassword,"GAS MASK")){//using gas mask if password enter is correct
            dangerEnd = time(NULL);
            if((dangerEnd - dangerStart)< timeAllowed){//check if input is within time
              cout<<"YOU ARE WEARING THE GAS MASK, POISON CAN'T KILL YOU"<<endl;
              //clearing danger
              map[pos.row][pos.col] = 1;
              isdanger = 0;
              chances = 0;
            }else{
              cout<<"YOU HAVE TAKEN TOO MUCH TIME!!"<<endl;
            }
          }else{
            cout<<"Wrong PassWord!!"<<endl;
          }
        }else{
          cout<<"No GAS MASK!!!";
        }
      }
    }
    if(command == "use light saber"){
      if(isdanger != 16){
        cout<<"LIGHT SABER CANNOT HELP!!"<<endl;
      }else{
        if(checkbag("LIGHT SABER")){
          cout<<"LIGHT SABER READY!!"<<endl;
          cout<<"Enter password: ";
          cin>>enterPassword;
          if (useWeapon(enterPassword,"LIGHT SABER")){
            dangerEnd = time(NULL);
            if((dangerEnd - dangerStart)< timeAllowed){
              cout<<"ALIEN KILLED, YOU ARE SAFE"<<endl;
              map[pos.row][pos.col] = 1;
              isdanger = 0;
              chances = 0;
            }else{
              cout<<"YOU HAVE TAKEN TOO MUCH TIME!!"<<endl;
            }
          }else{
            cout<<"Wrong PassWord!!"<<endl;
          }
        }else{
          cout<<"No LIGHT SABER!!!"<<endl;
        }
      }
    }
    //if player wants to use a portal gun
    if(command == "use portal gun"){
      if(isdanger != 16 && isdanger != 15){//check for danger
        cout<<"DO NOT WASTE PORTAL GUN!!"<<endl;
      }else{
        if(checkbag("PORTAL GUN")){//check if portal gun in bag
          cout<<"PORTAL GUN READY!!"<<endl;
          cout<<"enter password: ";
          cin>>enterPassword;
          if (useWeapon(enterPassword,"PORTAL GUN")){//using weapon if password match
            dangerEnd = time(NULL);
            if((dangerEnd - dangerStart)< timeAllowed){//check time
              cout<<"MOVING TO THE NEXT PLANET!"<<endl;
              fetchitem(map,pos,findPos, 1);//fetch next planet
              if(findPos.row == 10 || findPos.col == 10){
                fetchitem(map,pos,findPos, 15);//check for gas planet

              }
              if(findPos.row == 10 || findPos.col == 10){
                fetchitem(map,pos,findPos, 16);//check for gas planet

              }
              //move to the next planet
              clearItem(map,pos);
              pos.row = findPos.row;
              pos.col = findPos.col;

              isdanger = 0;
              chances = 0;
            }else{
              cout<<"YOU HAVE TAKEN TOO MUCH TIME!!"<<endl;
            }
          }else{
            cout<<"Wrong PassWord!!"<<endl;
          }
        }else{
          cout<<"No PORTAL GUN!!!"<<endl;
        }
      }
    }
    //printmap(map);


  }
  if(mortyFound){
    gameEnd = time(NULL);//GAME END TIME
    diff = gameEnd - gameStart;//TIME TAKEN TO COMPLETE GAME
    cout<<endl;
    cout<<"YOU HAVE SAVED MORTY"<<endl;
    cout<<"YOU COMPLETED THE GAME IN "<<diff/60<<" MINS and "<<diff%60<<" SECONDS."<<endl;
    cout<<endl;
    cout<<"MORTY:OHH GEEZ RICK!! THAT WAS CLOSE!"<<endl;
    cout<<"RICK: I'M THERE FOR YOU MORTY, YOUR GRANDPA!!"<<endl;

  }else{
    cout<<endl;
    cout<<"YOU COULD NOT SAVE MORTY!!!"<<endl;
    cout<<"GAME OVER"<<endl;
    cout<<endl;
    cout<<"THIS IS A DIFFICULT GAME, IT'S NOT EASY TO BE RICK"<<endl;
    cout<<endl;
  }

  cout<<"Thanks for playing finding morty"<<endl;

  return 0;
}



void clearItem(int map[][8], Position pos){//Remove an item from map
  map[pos.row][pos.col] = 0;
}
void startPos(int map[][8],Position &pos){//provides the starting position of the player in the map
  for(int i = 0;i<5;i++){
    if(map[7][i] == 1){
      pos.row = 7;
      pos.col = i;
      break;
    }
  }
}
