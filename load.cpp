#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(){
  fstream GameLoad("tests");
  int int1;
  GameLoad >> int1;
  cout << int1 << endl;
  GameLoad.close();
  return 0;
}