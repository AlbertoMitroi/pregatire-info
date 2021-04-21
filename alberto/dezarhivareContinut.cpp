#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream fcin("arh.in");
ofstream fcout("arh.out");

//caz1 n(C) -> 5(ab) = D: ababababab
//caz2 [*C] -> [*abc] = abccba
//caz3 [C*] ->  [abc*] = abcba

int main(){
  char sirPropiuT[100000] = "", sirArhivatS[10000];
  fcin.getline(sirArhivatS, 10000);
  int nrN = 0; // pt cazul 1
  char subSir[10000] = "";
  bool caz2 = false;
  bool caz3 = false;
  char subSirCaz2[10000];
  char subSirCaz3[10000];
  int nr_transformari = 0;
  fcout << "Sir: " << sirArhivatS << endl;
  for(int i = 0; i < 10000; i++){
    if(isdigit(sirArhivatS[i]) != 0){
      fcout << "If isdigit" << endl;
      if(isalnum(i+1) != 0){
        nrN = sirArhivatS[i] - 48;
        fcout << "nrN: (if)" << nrN << endl;
      } else{
          nrN = nrN * 10 + (sirArhivatS[i] - 48);
          fcout << "nrN: (else)" << nrN << endl;
      }
    }
    if(isalpha(sirArhivatS[i]) != 0){
      fcout << "If isalpha" << endl;
        fcout << "If nrN !=0" << endl;
        char aux[10000] = "";
        strcat(aux, sirArhivatS+i);
        // fcout << "aux:" << aux << endl;
        strcat(subSir, "");
        // fcout << "subSir:" << subSir << endl;
        strncat(subSir, aux, 1);
        fcout << "subSir:" << subSir << endl;
        fcout << sirArhivatS[i+1] << endl;
        if(isalpha(sirArhivatS[i+1]) == 0){
          if(nrN == 0){
            strcat(sirPropiuT, subSir);
            if(caz2 == true){
              strcat(subSirCaz2, subSir);
            }
            if(caz3 == true){
              strcat(subSirCaz3, subSir);
            }
          }else nr_transformari++;
          fcout << "If isalpha elementul i+1" << endl;
          for(int j = 0; j < nrN; j++){
            strcat(sirPropiuT, subSir);
            if(caz2 == true){
              strcat(subSirCaz2, subSir);
            }
            if(caz3 == true){
              strcat(subSirCaz3, subSir);
            }
          }
          nrN = 0;
          strcpy(subSir, "");
          strcpy(aux, "");
        }
    }
    if(sirArhivatS[i] == '['){
      if(sirArhivatS[i+1] == '*'){
        fcout << "If [*" << endl;
        caz2 = true;
      }else caz3 = true;
    }
    if(sirArhivatS[i] == ']' && sirArhivatS[i-1] != '*'){
      caz2 = false;
      nr_transformari++;
      for(int j = strlen(subSirCaz2)-1; j >= 0; j--){
        fcout << "elementul din caz2: " << subSirCaz2[j] << endl;
        char aux[10000] = "";
        strcat(sirPropiuT, subSirCaz2+j);
        strncat(aux, subSirCaz2, j);
        strcpy(subSirCaz2, aux);
      }
    }
    if(sirArhivatS[i] == '*'){
      if(sirArhivatS[i+1] == ']'){
        caz3 = false;
        nr_transformari++;
        fcout << "If *]" << subSirCaz3 << endl;
        char aux[10000] = "";
        strncpy(aux, subSirCaz3, strlen(subSirCaz3)-1);
        strcpy(subSirCaz3, aux);
        for(int j = strlen(subSirCaz3)-1; j >= 0; j--){
          fcout << "elementul din caz2: " << subSirCaz3[j] << endl;
          char aux[10000] = "";
          strcat(sirPropiuT, subSirCaz3+j);
          strncat(aux, subSirCaz3, j);
          strcpy(subSirCaz3, aux);
        }
      }
    }
    }
    fcout << endl << "================= Rezultatul final =================" << endl;
    fcout << nr_transformari << endl;
    fcout << sirPropiuT << endl;
    fcout << "====================================================" << endl;

    return 0;
  }
