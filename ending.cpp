#ifndef ENDING_H
#define ENDING_H

#include <unistd.h>

#include <iostream>
#include <string>

#include "start.cpp"
using namespace std;
class ending : public start {
 public:
  ending(){};
  start starter;
  start new_game;
  ending(start initial) { starter = initial; }
  string message3 = "Congratulations you win";
  string message4 = "You lose";
  string message5 = "Enter 3 if you wish to save your progress.";
  string message6 = "Game over";
  void selection() {
    while (choice != 1 && choice != 2 && choice != 3) {
      looper(starter);
      cin >> choice;
    }
    if (choice == 1) {
      system("clear");
      new_game.set_check(main_game());
      ending _new(new_game);
      _new.selection();
    } else if (choice == 2) {
      system("clear");
      cout << "loading game function called" << endl;
    } else if (choice == 3) {
      system("clear");
      // saving function called
      cout << "Game saved" << endl;
    }
  }
  void looper(start game_starter) {
    if (game_starter.get_check() == 0) {  // message for loosing game
      cout << message6;
      cout.flush();
      sleep(3);
      cout << "\r";
      cout << message4;
      cout.flush();
      sleep(3);
      cout << "\r";
      cout << "                                                                "
              "  "
              "                            ";
      cout << "\r";
    } else if (game_starter.get_check() == 1) {  // message for winning
      cout << message6;
      cout.flush();
      sleep(3);
      cout << "\r";
      cout << message3;
      cout.flush();
      sleep(3);
      cout << "\r";
      cout << "                                                                "
              "  "
              "                            ";
      cout << "\r";
    } else if (game_starter.get_check() == 2) {  // message for run
      cout << message5;
      cout << "\n\n"
           << "Alternatively";
    }
    cout << "\n\n";
    cout << message2 << endl;
  }
};
#endif