#include <iostream>
#include <stdlib.h>
#include <time.h>//header file
#include "map.h"

using namespace std;

void createmap(int map[][8]){
  srand(time(NULL));
  int startPos = rand()%3;
  int endPos = 5+rand()%3;
  char bridgeJoint = 's';//To connect two rows
  //Creating a random path for player across the 2D array
  for(int i = 1;i<8;i+=2){
    if(bridgeJoint == 's'){
      map[i-1][startPos] =1;
      endPos = 5+rand()%3;
      bridgeJoint ='e';
    }
    else{
      map[i-1][endPos] =1;
      startPos = rand()%3;
      bridgeJoint ='s';
    }
    for(int j = startPos;j<=endPos;++j){
      map[i][j] = 1;
    }
  }


  //Adding Chest and PowerChest in level one to 3;
  int chestType = 0;
  for(int i = 5;i<=7;i++){
    for(int j = 0;j<=7;j++){
      if(map[i][j] != 1){
        chestType = rand()%10;
        if(chestType<=3)
          map[i][j] = 0;//Blank No chest
        if(chestType >7)
          map[i][j] = 20;//20 means powerChest available
        if(chestType>3 && chestType<8)
          map[i][j] = 10;//10 means normal chest

      }
    }
  }


  //Adding danger at level 2;
  int dangerCount = 0;
  int isDanger = 0;
  while (dangerCount < 1){
    for(int i = 0;i<8;i++){
      if(map[5][i] == 1){
        isDanger = rand()%11;
        if(isDanger == 7 || isDanger == 8){
          map[5][i] = 15;//Gas planet
          dangerCount++;
          break;
        }
        if(isDanger == 9 || isDanger ==10){
          map[5][i] = 16;//Alien attack
          dangerCount++;
          break;
        }
      }
    }
  }

  //Adding danger at level 3;
  dangerCount = 0;
  isDanger = 0;
  while (dangerCount < 2){
    for(int i = 0;i<8;i++){
      if(map[3][i] == 1){
        isDanger = rand()%11;
        if(isDanger == 7 || isDanger == 8){
          map[3][i] = 15;//Gas planet
          dangerCount++;
          break;
        }
        if(isDanger == 9 || isDanger ==10){
          map[3][i] = 16;//Alien attack
          dangerCount++;
          break;
        }
      }
    }
  }

  //Adding danger at level 4;
  dangerCount = 0;
  isDanger = 0;
  while (dangerCount < 2){
    for(int i = 0;i<8;i++){
      if(map[1][i] == 1){
        isDanger = rand()%11;
        if(isDanger == 7 || isDanger == 8){
          map[1][i] = 15;//Gas planet
          dangerCount++;
          break;
        }
        if(isDanger == 9 || isDanger ==10){
          map[1][i] = 16;//Alien attack
          dangerCount++;
          break;
        }
      }
    }
  }

  //Completing the map
  int randomNumber = 0;
  for(int i = 0;i<=4;i++){
    for(int j = 0;j< 8;j++){
      if (map[i][j] != 1 && map[i][j] != 16 && map[i][j] != 15){
        randomNumber = rand()%10;
        if(randomNumber == 9){
          map[i][j] = 10;//This is equipment store
        }
        if (randomNumber > 5 && randomNumber<9)
          map[i][j] = 10;//Normal Chest
        if(randomNumber == 5){
          map[i][j] = 20;//Power chest;
        }
      }
    }
  }

}
//Prints the entire 2D map. Used for testing.
void printmap(int map[][8]){
  for(int i = 0;i<8;i++){
    for(int j = 0;j<8;j++){
      cout<<map[i][j]<<" ";
    }
    cout<<endl;
  }
}
