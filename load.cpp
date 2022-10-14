#include <fstream>
#include <iostream>
#include <string>
#include "save.cpp"
using namespace std;
class load {
 public:
long long int hexadecimalToDecimal(string hexVal) {
  int len = hexVal.size();

  // Initializing base value to 1, i.e 16^0
  int base = 1;

  long long int dec_val = 0;

  // Extracting characters as digits from last
  // character
  for (int i = len - 1; i >= 0; i--) {
    // if character lies in '0'-'9', converting
    // it to integral 0-9 by subtracting 48 from
    // ASCII value
    if (hexVal[i] >= '0' && hexVal[i] <= '9') {
      dec_val += ((int(hexVal[i]) - 48) * base);

      // incrementing base by power
      base = base * 16;
    }

    // if character lies in 'A'-'F' , converting
    // it to integral 10 - 15 by subtracting 55
    // from ASCII value
    else if (hexVal[i] >= 'a' && hexVal[i] <= 'f') {
      dec_val += ((int(hexVal[i]) - 87) * base);

      // incrementing base by power
      base = base * 16;
    }
  }
  return dec_val;
}

TheGame game_saved;
  load(){};
  load(TheGame theGame) { game_saved = theGame; }

void loader() {
  fstream GameLoad("tests");
  string a;
  void* b;
  
  GameLoad >> a;
  long long int adress = hexadecimalToDecimal(a);  // too big for 32 bit.
  Pokemon* poke_ptr = (Pokemon*)(adress);
  game_saved.Pokemon_Array = poke_ptr;
  //cout.precision(20);
  //cout << a << endl;
  //cout << adress << endl;
  //cout << poke_ptr << endl;
  GameLoad.close();
}
};