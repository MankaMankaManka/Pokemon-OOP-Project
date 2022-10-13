#include <fstream>
#include <iostream>
#include <string>

#include "noBattleClass.cpp"
using namespace std;
class save {
 public:
  TheGame game_being_saved;
  save(){};
  save(TheGame theGame) { game_being_saved = theGame; }
  int saving() {
    ofstream GameSave("tests");
    cout << "saved called" << endl;
    GameSave << game_being_saved.Pokemon_Array->currentHitPoints;
    return 1;
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