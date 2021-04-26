#include <iostream>
#include <fstream>
#include "danger.h"

using namespace std;

void dangerPicture(int danger){
  string line;//to read lines from files
  ifstream fin;//input fstream
  if(danger == 15){
    fin.open("poisonGas.txt");
  }
  if (danger == 16){
    fin.open("alienattack.txt");
  }
  while(getline(fin,line)){
    cout<<line<<endl;
  }
  fin.close();
  cout<<"USE EQUIPMENT/WEAPON TO SAVE YOURSELF!! QUICK"<<endl;
}
