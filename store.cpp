#include <iostream>
#include <fstream>
#include <string>
#include "store.h"

using namespace std;

//Function runs when player wants to access galaxy store
int equipmentStore(int &spacekeys){
  string line;
  ifstream fin;
  int input = 0;
  fin.open("store.txt");//Reads store messages from text file
  while(getline(fin,line)){//Reading each line
    cout<<line<<endl;
  }
  if(spacekeys < 30){//checks if enough keys available
    cout<<"NOT ENOUGH KEYS!!"<<endl;
    cout<<"CANNOT BUY ANYTHING!";
    return 0;
  }else{
    while(true){
      cout<<"WHAT DO YOU WANT TO BUY(ENTER NUMBER) : ";
      cin>>input;
      if(input <=0 || input > 4){//ask again
        cout<<"WRONG INPUT!! ENTER AGAIN."<<endl;
        continue;
    }
      if(input == 1){
        spacekeys -= 30;
        return 1;//gas mask
      }
      if(input == 2){
        spacekeys -= 30;

        return 2;//light saber
      }
      if(input == 3){
        if(spacekeys<50){//check for portal gun
          cout<<"NOT ENOUGH SPACE KEYS FOR PORTAL GUN!!"<<endl;
          continue;
        }else{
          spacekeys-= 50;
          return 3;
        }
      }
      if(input == 4){//Nothing brought
        return 0;
      }
    }
  }
}
