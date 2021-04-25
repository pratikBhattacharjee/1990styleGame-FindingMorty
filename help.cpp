#include <iostream>
#include <fstream>
#include "help.h"

using namespace std;

void printHelp(){
  ifstream fin;
  fin.open("help.txt");//opening file
  if(fin.fail()){
    cout<<"Error Printing Help!!";
  }else{
  string line;
  cout<<"*****About Finding Morty Game******"<<endl;
  while(getline(fin,line)){//printing each line
    cout<<line<<endl;
  }
  fin.close();
}
}
