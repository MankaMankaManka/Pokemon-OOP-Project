#include <unistd.h>

#include <iostream>

#include "start.cpp"
using namespace std;
int main() {
  system("clear");
  start game;
  game.selection();
  if (game.check == 0) {
    // call end
  } else {
    // call end
  }
  return 0;
}