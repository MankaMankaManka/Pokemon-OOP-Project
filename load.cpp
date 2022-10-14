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
      Pokemon* adress = (Pokemon*)poke_ptr[i];
    }
    GameLoad.close();
  }
};