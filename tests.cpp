#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>

#include "ending.cpp"
using namespace std;
double hexadecimalToDecimal(string hexVal) {
  int len = hexVal.size();

  // Initializing base value to 1, i.e 16^0
  int base = 1;

  double dec_val = 0;

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
    else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') { //capitals need change!
      dec_val += ((int(hexVal[i]) - 55) * base);

      // incrementing base by power
      base = base * 16;
    }
  }
  return dec_val;
}

int main() {
  fstream GameLoad("tests");
  string a;
  // Pokemon* adress = (Pokemon*)a;
  GameLoad >> a;
  double adress = hexadecimalToDecimal(a);  // seems to give wrong numbers??//to do w/ capitals
  // Pokemon* poke_ptr = (Pokemon*)(1000000*adress); //long type too small
  // *million Pokemon* poke_ptr2 = (Pokemon*)a;
  //  stringstream ss("a");
  //  adress = a;
  //  GameLoad >> adress;
  cout.precision(20);
  cout << a << endl;
  cout << adress << endl;
  // cout << poke_ptr << endl;
  GameLoad.close();
  // double* x = (double*)adress;
  // Pokemon* f = (Pokemon*)a;
  return 0;
}