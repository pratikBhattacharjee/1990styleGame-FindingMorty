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
