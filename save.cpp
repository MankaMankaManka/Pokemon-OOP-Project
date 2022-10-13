#include <fstream>
#include <iostream>
#include <string>
#include "start.cpp"
#include "noBattleClass.cpp"
using namespace std;
class save{
start game_being_saved;
save(){};
save(start theGame){
    game_being_saved = theGame;
}
void saving(){
    ofstream GameSave("tests");
    GameSave << 1;
}


}






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
}*/;