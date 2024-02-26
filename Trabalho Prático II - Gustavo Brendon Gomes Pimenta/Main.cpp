#include <iostream>
#include <windows.h>
#include "FMain.cpp"
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int a;
        
       do
       {
        do
        {
            cout << " |-------------------------|\n";
            cout << " |     MENU PRINCIPAL      |\n";
            cout << " |(1) Cadastrar funcionario|"<< endl;
            cout << " |(2) Buscar funcionario   |" << endl;
            cout << " |(3) Remover funcionario  |" << endl;
            cout << " |(4) Imprimir             |" << endl;
            cout << " |(5) Sair                 |" << endl;
            cout << " |-------------------------|\n";

            cout << " Qual opcao deseja prosseguir: " ;
            cin >> a;

           
        } while (a < 1 || a > 5);
            switch(a) {
                case 1:
                    cadastrarFuncionario();
                break;

                case 2:
                    buscarFuncionario();
                break;

                case 3:
                    removerFuncionario();
                 break;

                case 4:
                    system("cls");
                    imprimeArvore(arvoreNUN);
                    cout<< "\n";
                    cout<< "\n";
                    cout<< "\n";
                    cout<< "\n";
                break;

                case 5:
                    system("cls");
                    cout << "PROGRAMA FECHADO!!!";
                    exit(0);   
                break;
        }

       } while (a != 5);
 
 
  cout << endl;
  return 0;
}