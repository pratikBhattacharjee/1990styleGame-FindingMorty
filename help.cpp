#include <iostream>
#include <fstream>
#include "help.h"

using namespace std;

//Reads Text from help.txt and prints it
void printHelp(){
  ifstream fin;//input file stream
  fin.open("help.txt");//opening file
  if(fin.fail()){
    cout<<"Error Printing Help!!";
  }else{
  string line;//input line
  cout<<"*****About Finding Morty Game******"<<endl;
  while(getline(fin,line)){//printing each line
    cout<<line<<endl;
  }
  fin.close();//closing file
}
}
