#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(){
  fstream GameLoad("tests");
  string ch;
  int int1;
  GameLoad >> ch;
  GameLoad >> int1;
  cout << ch << int1 << endl;
  cout << int1 << endl;
  GameLoad.close();
  return 0;
}