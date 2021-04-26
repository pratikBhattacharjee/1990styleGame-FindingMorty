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
