#include <unistd.h>

#include <iostream>

#include "start.cpp"
using namespace std;
int main() {
  system("clear");
  start game;
  game.selection();
  return 0;
}