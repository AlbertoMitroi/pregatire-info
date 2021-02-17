#include <iostream>
using namespace std;

int main(){
  int n, **m;
  cout << "N: "; cin >> n;
  m = new int*[n];
  for(int i = 0; i < n; i++){
    m[i] = new int[n];
    for(int j = 0; j < n; j++){
      if(j == n-i-1 || j == n-i-2 || j == n-i){
        m[i][j] = 1;
      }else m[i][j] = 2;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
}
