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
