#include <fstream>
#include <iostream>
#include <string>

#include "save.cpp"
using namespace std;
class load {
 public:
  TheGame game_saved;
  load(){};
  load(TheGame theGame) { game_saved = theGame; }

  void loader() {
    fstream GameLoad("tests");
    for (int i = 0; i < 6; i++) {
      void* poke_ptr[i];
      GameLoad >> poke_ptr[i];
      game_saved.Pokemon_Array = (Pokemon*)poke_ptr[i];
    }
    for (int j = 0; j < 6; j++) {
      void* poke_ptr[j];
      GameLoad >> poke_ptr[j];
      game_saved.Pokemon_Array = (Pokemon*)poke_ptr[j];
    }
    void* playerKilled;
    GameLoad >> playerKilled;
    game_saved.trainerProgress = (int*)playerKilled;
    void* computerKilled;
    GameLoad >> computerKilled;
    game_saved.computerProgress = (int*)computerKilled;
    GameLoad.close();
  }
};