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
  ending game_2(game_1);
  game_2.selection();
  return 0;
}
//g++ gametests.cpp -o t


// Dosen't offer selection choices, unknown move names, unknown pokemon names.