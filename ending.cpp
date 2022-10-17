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

  ending(start initial) { starter = initial; }
  string message3 = "Your opponent has run out of Pokemon to use, Congratulations you win.";
  string message4 = "You have run out of Pokemon to use. You lose.";
  string message5 = "Enter 3 if you wish to save your progress.";
  string message6 = "Game over";

  void selection() {
    system("clear");
    while (choice != 1 && choice != 2 && choice != 3) {
      looper(starter);
      starter.set_check(-1);
      while (choice < 1 || choice > 3) {
        while (!(std::cin >> choice)) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          system("clear");
          cout << "Invalid input, please try again." << endl;
        }
      }
    }
    if (choice == 1) {
      system("clear");
      starter.set_check(starter.begin.main_game());
      choice = 0;
      ending _new(starter);
      _new.selection();
    } else if (choice == 2) {
      system("clear");
      load load_game(begin);
      load_game.loader();
      starter.set_check(starter.begin.main_game2());
      choice = 0;
      ending _new(starter);

      _new.selection();
    } else if (choice == 3) {
      system("clear");
      save saver(starter.begin);
      saver.saving();
      choice = 0;
      ending _new(starter);
      _new.selection();
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
      sleep(5);
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
      sleep(5);
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