#include <iostream>
#include <fstream>
#include <string>
#include "store.h"

using namespace std;

int equipmentStore(int &spacekeys){
  string line;
  ifstream fin;
  int input = 0;
  fin.open("store.txt");
  while(getline(fin,line)){
    cout<<line<<endl;
  }
  if(spacekeys < 30){
    cout<<"NOT ENOUGH KEYS!!"<<endl;
    cout<<"CANNOT BUY ANYTHING!";
    return 0;
  }else{
    while(true){
      cout<<"WHAT DO YOU WANT TO BUY(ENTER NUMBER) : ";
      cin>>input;
      if(input <=0 || input > 4){
        cout<<"WRONG INPUT!! ENTER AGAIN."<<endl;
        continue;
    }
      if(input == 1){
        spacekeys -= 30;
        return 1;
      }
      if(input == 2){
        spacekeys -= 30;

        return 2;
      }
      if(input == 3){
        if(spacekeys<50){
          cout<<"NOT ENOUGH SPACE KEYS FOR PORTAL GUN!!"<<endl;
          continue;
        }else{
          spacekeys-= 50;
          return 3;
        }
      }
      if(input == 4){
        return 0;
      }
    }
  }
}
