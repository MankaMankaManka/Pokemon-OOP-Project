#include <unistd.h>

#include <iostream>

#include "ending.cpp"
//#include "start.cpp"
using namespace std;
int main() {
  system("clear");
  start game_1;
  game_1.selection();
  ending game_2(game_1);
  game_2.selection();
  return 0;
}