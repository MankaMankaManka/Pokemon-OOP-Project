#ifndef START_H
#define START_H
#include <unistd.h>

#include <iostream>
#include <string>
using namespace std;
#include "load.cpp"
#include "loop.cpp"
using namespace std;
class start : public loop {
 private:
  int check = -1;
 public:
  TheGame begin;
  start(){};
  start(TheGame Game) { begin = Game; }
  string message1 = "Hello. Welcome to Pokemon, get ready to battle.";
  string message2 = "Enter 1 to start a new game or enter 2 to load a game.";
  int choice = 0;
  int set_check(int CHECK) {
    check = CHECK;
    return 0;
  }
  int get_check() { return check; }
  virtual void selection() {
    system("clear");
    while (choice != 1 && choice != 2) {
      looper();
      while (choice < 1 || choice > 2) {
        while (!(std::cin >> choice)) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          system("clear");
          cout << "Invalid input, please try again." << endl;
          cout << message2 << endl;
        }
      }
    }
    if (choice == 1) {
      system("clear");
      check = begin.main_game();
    } else if (choice == 2) {
      system("clear");
      load load_game(begin);
      load_game.loader();
      check = begin.main_game2();
    }
  }
  void looper() {
    cout << message1;
    cout.flush();
    sleep(3);
    cout << "\r";
    cout << message2;
    cout.flush();
    sleep(5);
    cout << "\r";
    cout << "                                                                  "
            "                            ";
    cout << "\r";
  }
};
#endif