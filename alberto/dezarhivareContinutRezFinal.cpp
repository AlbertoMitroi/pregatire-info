#include <iostream>
#include <string>
using namespace std;

void test(string& sirArhivatS, int *i);
void multiplicare_caz1(string& sirArhivatS, int *i);
void reverse_caz2(string& sirArhivatS, int *i);
void reverse_caz3(string& sirArhivatS, int *i);
void stop(string& sirArhivatS, int *i);
int main(){
  string sirArhivatS = "2(a)[*a2(b)]xy[2(c)b*]d";
  int i = 0;
  test(sirArhivatS, &i);
  cout << sirArhivatS;
  return 0;
}
// [*a2(b)]xy[2(c)b*]  xy[2(c)b*]2(D[KL*])
// 0123456789*123456789*1
// aa[*a..

void test(string& sirArhivatS, int *i){
  cout << "test:" << endl << sirArhivatS << " " << *i << " " << sirArhivatS[*i] << endl << endl;
  switch (sirArhivatS[*i]) {
    case '[': sirArhivatS[*(i)+1] == '*' ? reverse_caz2(sirArhivatS, i) : reverse_caz3(sirArhivatS, i); break;
    case '*': sirArhivatS[*(i)+1] == ']' ? reverse_caz3(sirArhivatS, i) : reverse_caz2(sirArhivatS, i); break;
    // case ']': stop(); break;
  }
  if(isdigit(sirArhivatS[*i]) != 0){
    multiplicare_caz1(sirArhivatS, i);
  }
  if(isalpha(sirArhivatS[*i]) != 0){
    while(isalpha(sirArhivatS[*i]) != 0){
      (*i)++;
    }
    test(sirArhivatS, i);
  }
}

void change(string& sirArhivatS, int i_initial, string SubSir, int len){
  sirArhivatS.erase(i_initial, len);
  sirArhivatS.insert(i_initial, SubSir);
  cout << "Change face: " << sirArhivatS << endl;
}

void stop(string& sirArhivatS, int *i){
  if(isalpha(sirArhivatS[*i]) != 0){
    while(isalpha(sirArhivatS[*i]) != 0){
      (*i)++;
    }
    test(sirArhivatS, i);
  }
}

void multiplicare_caz1(string& sirArhivatS, int *i){
  cout << "multiplicare_caz1" << endl;
  int i_initial = *i, n = 0, len = 1, size;
  string subSirCaz1, SubSir;
  while(isdigit(sirArhivatS[*i]) != 0){
    n = n * 10 + sirArhivatS[*i] - 48;
    (*i)++;
    len++;
  }
  (*i)++;
  while(sirArhivatS[*i] != ')'){
    if(isalpha(sirArhivatS[*i]) != 0){
      subSirCaz1 += sirArhivatS[*i];
      (*i)++;
    }else {
      cout << "Se apeleaza test din caz 1" << endl;
      test(sirArhivatS, i);
    }
  }
  for(int j = 0; j < n; j++){
    SubSir += subSirCaz1;
  }
  size = SubSir.size();
  len += size;
  change(sirArhivatS, i_initial, SubSir, len);
  // cout << *i;
  (*i) = i_initial;
  size = sirArhivatS.size();
  cout << "Ajung la if, i: " << *i << ", size: " << size << endl;
  if(*i < size){
    cout << "MA DUC DIN 1" << endl;
    // stop(sirArhivatS, i);
    test(sirArhivatS, i);
  }
}

void reverse_caz2(string& sirArhivatS, int*i){
  cout << "reverse_caz2" << endl;
  int i_initial = *i, len = 3, size;
  string subSirCaz2;
  (*i) += 2;
  while(sirArhivatS[*i] != ']'){
    cout << sirArhivatS[*i] << endl;
    if(isalpha(sirArhivatS[*i]) != 0){
      subSirCaz2 += sirArhivatS[*i];
      cout << "subSirCaz2: " << subSirCaz2 << endl;
      (*i)++;
    }else {
      cout << "Apelez test din caz 2" << sirArhivatS[*i] << endl;
      test(sirArhivatS, i);
    }
  }
  size = subSirCaz2.size();
  for(int j = size-1; j >= 0; j--){
    subSirCaz2 += subSirCaz2[j];
  }
  len += size;
  change(sirArhivatS, i_initial, subSirCaz2, len);
  size = subSirCaz2.size();
  (*i) = size;
  size = sirArhivatS.size();
  cout << "Ajung la if, i: " << *i << ", size: " << size << endl;
  if(*i < size){
    cout << "MA DUC DIN 2" << endl;
    // while(isalpha(sirArhivatS[*i]) != 0){
    //   (*i)++;
    // }
    // stop(sirArhivatS, i);
    test(sirArhivatS, i);
  }
}

void reverse_caz3(string& sirArhivatS, int*i){
  cout << "reverse_caz3" << endl;
  int i_initial = *i, len = 3, size;
  string subSirCaz3;
  (*i)++;
  cout << "3." << *i << endl;
  while(sirArhivatS[*i] != '*'){
    if(isalpha(sirArhivatS[*i]) != 0){
      subSirCaz3 += sirArhivatS[*i];
      (*i)++;
      if(sirArhivatS[*i] == ']')
      (*i)++;
    }else{
      cout << sirArhivatS[*i] << " ";
      cout << "Apelez din caz 3" << endl;
       test(sirArhivatS, i);
     }
  }
  size = subSirCaz3.size();
  for(int j = size-2; j >= 0; j--){
    subSirCaz3 += subSirCaz3[j];
  }
  len += size;
  change(sirArhivatS, i_initial, subSirCaz3, len);
  (*i) = i_initial;
  size = sirArhivatS.size();
  cout << "3Ajung la if, i: " << *i << ", size: " << size << endl;
  if(*i < size){
    cout << "MA DUC DIN 3" << endl;
    // stop(sirArhivatS, i);
    test(sirArhivatS, i);
  }
}
