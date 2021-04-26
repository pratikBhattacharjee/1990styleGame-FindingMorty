#include <iostream>
#include <fstream>
#include "danger.h"

using namespace std;
//Reads from the ASCII text art files and prints the texts
void dangerPicture(int danger){
  string line;//to read lines from files
  ifstream fin;//input fstream
  if(danger == 15){
    fin.open("poisonGas.txt");//for poisonGas
  }
  if (danger == 16){
    fin.open("allienattack.txt");//for allien attack
  }
  while(getline(fin,line)){
    cout<<line<<endl;
  }
  fin.close();//closing file
  cout<<"USE EQUIPMENT/WEAPON TO SAVE YOURSELF!! QUICK"<<endl;
}
