#include <iostream>
using namespace std;

int main(){
  char text_1[100], text_2[100];
  int ascii[130];
  int a, z;
  a = int('a');
  z = int('z');
  ascii[int(' ')] = 0;
  for(int i = a; i <= z; i++){
    ascii[i] = 0;
  }
  cout << "text 1: "; cin.getline(text_1, 100);
  cout << "text 2: "; cin.getline(text_2, 100);
  int size_1 = strlen(text_1);
  int size_2 = strlen(text_2);
  for(int i = 0; i < size_1; i++){
    ascii[int(text_1[i])]++;
  }
  for(int i = 0; i < size_2; i++){
    ascii[int(text_2[i])]++;
  }
  for(int i = 97; i <= 122; i++){
    if(ascii[i] % 2 == 1  && ascii[i] != 0){
      cout << "Nu";
      return 0;
    }
  }
  cout << "Da";
  return 0;
}
