#include <fstream>
#include <iostream>
#include <string>

#include "mainGame.cpp"
using namespace std;
class save {
 public:
  TheGame game_being_saved;
  save(){};
  save(TheGame theGame) { game_being_saved = theGame; }
  void saving() {
    ofstream GameSave("tests");
    for (int i = 0; i < 6; i++) {
      GameSave << game_being_saved.Pokemon_Array + i << endl;
    }
    for (int j = 0; j < 6; j++) {
      GameSave << game_being_saved.Computer_Array + j << endl;
    }
    GameSave << game_being_saved.trainerProgress << endl;
    GameSave << game_being_saved.computerProgress << endl;
  }
};

/*#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(){
  fstream GameSave("???");
  string ch;
  GameSave >> ch;
  cout << ch << endl;
  GameSave.close();
  return 0;
}*/
;