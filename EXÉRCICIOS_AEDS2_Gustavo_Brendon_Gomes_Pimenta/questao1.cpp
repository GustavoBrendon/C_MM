#include <iostream>
#include <windows.h>
 
using namespace std;

float potencia(int x, int y){
    if (y==0){
        return 1;
    }else if (y==1){
        return x;
    }else{
        x *= potencia(x,y-1);
        return x;
    }
}
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int a=2, b=6;

  cout<< potencia(a,b);
 
 
  cout << endl;
  return 0;
}