#include <iostream>
#include <windows.h>
 
using namespace std;

int sV(int vetor[], int tam){
    if(tam==0){
        return 0;
    }else{
        return vetor[tam-1] + sV(vetor, tam-1);

    }
}
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int vetor[]={10,11,12,13,14,15};
  int soma;
  int tamanho=5;
  soma= sV(vetor,tamanho);
  cout << soma;
 
 
  cout << endl;
  return 0;
}