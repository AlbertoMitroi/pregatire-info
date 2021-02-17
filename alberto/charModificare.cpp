#include <iostream>
#include <string>
using namespace std;

int main(){
  char x[20], s[20];
  cout << "X: "; cin.getline(x, 20);
  cout << "S: "; cin.getline(s, 20);
  if(strlen(x) % 2 == 0){
    strcpy(x, s);
  }else {
    strcpy(x + strlen(x)/2, x + strlen(x)/2 +1);
  }
  cout << "X devine: " << x;
  return 0;
}
