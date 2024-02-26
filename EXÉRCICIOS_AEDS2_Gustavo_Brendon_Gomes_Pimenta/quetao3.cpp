#include <iostream>
#include <windows.h>
 
using namespace std;

void iV(int vetor[], int tam, int aux1){
    tam--;
    if(tam==1 || tam==0){
        return;
    }

    int aux= vetor[tam];
    vetor[tam] = vetor[aux1 - tam];
    vetor[aux1 - tam]=aux;
    iV(vetor,tam,aux1);
}
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int vetor[]={10,11,12,13,14};
  int tamanho=5;
  iV(vetor,tamanho, tamanho-1);
  for(int i=0;i<5;i++){
    cout << vetor[i]<<" ";
  }
 
 
  cout << endl;
  return 0;
}