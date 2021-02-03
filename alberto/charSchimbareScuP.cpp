#include <iostream>
using namespace std;

int main(){
  char text[150], s[20], p[20], text_nou[150] = "";
  int ok = 0;
  cout << "Text: "; cin.getline(text, 150);
  cout << "s: "; cin >> s;
  cout << "p: "; cin >> p;
  char *cuvant = strtok(text, " ");
  while(cuvant != NULL){
    if(strcmp(cuvant, s) == 0){
      strcpy(cuvant, p);
      ok++;
    }
    strcat(text_nou, cuvant);
    strcat(text_nou, " ");
    cuvant = strtok(NULL, " ");
  }
  if(ok != 0){
      cout <<text_nou;
  }else cout << "Nu exista";
  return 0;
}
