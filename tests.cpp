#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>

#include "ending.cpp"
using namespace std;
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

int main() {
  fstream GameLoad("tests");
  //string a;
  //GameLoad >> a;
  void* b;
  GameLoad >> b;
  Pokemon* x = (Pokemon*)b;
  //long long int adress = hexadecimalToDecimal(a);  // too big for 32 bit.
  //Pokemon* poke_ptr = (Pokemon*)(adress);
  //cout.precision(20);
  //cout << a << endl;
  //cout << adress << endl;
  //cout << poke_ptr << endl;
  cout << b << endl;
  cout << x << endl;
  GameLoad.close();
  return 0;
}