#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

//Probability of getting space keys: 90%
//Probability of getting light saber: 5%
//Probability of getting gas mask: 5%
int normalChest(int &spacekeys){
  int result = 0;
  srand(time(NULL));
  int random = 0;
  random = rand()%10;
  if(random == 9){
    return rand()%2;//if returns 0, player gets gas mask and if returns 1 player gets a light saber
  }else{
    return 10;
  }
}
int powerChest(){
  int result = 0;
  srand(time(NULL));
  int random = 0;
  random = rand()%10;
  if (random >= 8)
    return  2;
  if (random >= 4 && random <=7)
    return 1;
  if(random <= 3)
    return 0;
}
int createPass(){
  srand(time(NULL));
  int num = 0;
  for(int i = 0;i<4;i++){
    num = num*10 + (rand()%9 + 1);
  }
  return num;
}
