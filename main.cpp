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
