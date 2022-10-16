#include <unistd.h>

#include <fstream>
#include <iostream>

#include "ending.cpp"
//#include "start.cpp"
using namespace std;
int main() {  // stand alone functions only
  // system("clear");
  TheGame starter;
  start game_1(starter);
  game_1.selection();
  //cout << game_1.begin.Pokemon_Array->nickname << endl;
  ending game_2(game_1);
  //cout << game_1.begin.Pokemon_Array->nickname << endl;
  //cout << game_2.begin.Pokemon_Array->nickname << endl;
  game_2.selection();
  return 0;
}
//g++ gametests.cpp -o t


// Dosen't offer selection choices, unknown move names, unknown pokemon names.