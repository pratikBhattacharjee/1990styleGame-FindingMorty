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
//Probalility of getting weapons = 100%
//Probalility of getting portal gun = 20%
//Probability of getting light saber = 40%
//Probability of getting gas mask = 40%
int powerChest(){
  int result = 0;
  srand(time(NULL));//making sure the sequence of numbers generated are not the same
  int random = 0;
  random = rand()%10;//creating number from 0-9
  if (random >= 8)
    return  2;//portal gun
  if (random >= 4 && random <=7)
    return 1;//light saber
  if(random <= 3)
    return 0;//gas mask
}
//Creates a four digit Number password that is randomly renerated
int createPass(){
  srand(time(NULL));
  int num = 0;
  for(int i = 0;i<4;i++){
    num = num*10 + (rand()%9 + 1);
  }
  return num;
}
