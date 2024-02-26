#include <iostream>
#include <time.h>
#include <fstream>
#include "Metodos.hpp"
 
using namespace std;

void PrimeiroMenu(){  // Primeiro Menu, seleção de método de ordenação.
    cout << "\n" << endl;
    cout << "Digite qual o metodo de ordenacao deseja selecionar: " << endl;
    cout << "1-> Bubble Sort.               " << endl;
    cout << "2-> Shell Sort.                " << endl;
    cout << "3-> Selection Sort.            " << endl;
    cout << "4-> Insertion Sort.            " << endl;
    cout << "5-> Quick Sort.                " << endl;
    cout << "6-> Merge Sort.                " << endl;
    cout << "7-> Sair.                      " << endl;
    cout << "\n" << endl;
}

void SegundoMenuInstancias(){ // Segundo menu, seleção de qual instância a ser utilizada pelo método de ordenação já selecionado.
    
    cout << "Digite a instancia que voce deseja selecionar:                  " << endl << endl;
    cout << "1-> DicionarioAleatorio-29855.txt             " << endl;
    cout << "2-> DicionarioAleatorio-261791.txt            " << endl;
    cout << "3-> DicionarioInversamenteOrdenado-29855.txt  " << endl;
    cout << "4-> DicionarioInversamenteOrdenado-261791.txt " << endl;
    cout << "5-> DicionarioOrdenado-29855.txt              " << endl;
    cout << "6-> DicionarioOrdenado261791.txt              " << endl;
    cout << "7-> ListaAleatoria-1000.txt                   " << endl;
    cout << "8-> ListaAleatoria-10000.txt                  " << endl;
    cout << "9-> ListaAleatoria-100000.txt                 " << endl;
    cout << "10-> ListaAleatoria-1000000.txt               " << endl;
    cout << "11-> ListaInversamenteOrdenada-1000.txt       " << endl;
    cout << "12-> ListaInversamenteOrdenada-10000.txt      " << endl;
    cout << "13-> ListaInversamenteOrdenada-100000.txt     " << endl;
    cout << "14-> ListaInversamenteOrdenada-1000000.txt    " << endl;
    cout << "15-> ListaOrdenada-1000.txt                   " << endl;
    cout << "16-> ListaOrdenada-10000.txt                  " << endl;
    cout << "17-> ListaOrdenada-100000.txt                 " << endl;
    cout << "18-> ListaOrdenada-1000000.txt                " << endl;
    cout << "19-> ListaQuaseOrdenada-1000.txt              " << endl;
    cout << "20-> ListaQuaseOrdenada-10000.txt             " << endl;
    cout << "21-> ListaQuaseOrdenada-100000.txt            " << endl;
    cout << "22-> ListaQuaseOrdenada-1000000.txt            " << endl;
}

 
int main() {
    int escolha=0;
    int tam,comp;
    int *vInt;
    time_t temp,temp2; // 00:00 1 Jan de 1970
    string *vString;
    
    PrimeiroMenu(); // Imprime Menu
    
    cout << "Qual a sua escolha: ";
    cin >> escolha;
    while(escolha<1 && escolha>7){
        cout << "Inválido!"<<endl;
        cin >> escolha;
    }
    switch (escolha)
    {
    case 1:
        system("cls");
        SegundoMenuInstancias(); // Imprime o Menu das Instâncias
        cout << "\n"<<"Qual a sua escolha: ";
        cin >> escolha;
        while(escolha<1 && escolha>22){
            cout << "Invalido!"<<endl;
            cin >> escolha;
        }
        switch (escolha) 
        {
            // Cada escolha, tem a finalidade de preencher o array com valores lidos do arquivo.

        case 1:
            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioAleatorio-29855.txt",tam);
            break;
        case 2:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioAleatorio-261791.txt",tam);
            break;
        case 3:
            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioInversamenteOrdenado-29855.txt",tam);
            break;
        case 4:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioInversamenteOrdenado-261791.txt",tam);
            break;
        case 5:
            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioOrdenado-29855.txt",tam);
            break;
        case 6:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioOrdenado-261791.txt",tam);
            break;
        case 7:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-1000.txt",tam);
            break;
        case 8:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-10000.txt",tam);
            break;
        case 9:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-100000.txt",tam);
            break;
        case 10:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-1000000.txt",tam);
            break;
        case 11:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-1000.txt",tam);
            break;
        case 12:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-10000.txt",tam);
            break;
        case 13:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-100000.txt",tam);
            break;
        case 14:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-1000000.txt",tam);
            break;
        case 15:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-1000.txt",tam);
            break;
        case 16:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-10000.txt",tam);
            break;
        case 17:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-100000.txt",tam);
            break;
        case 18:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-1000000.txt",tam);
            break;
        case 19:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-1000.txt",tam);
            break;
        case 20:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-10000.txt",tam);
            break;
        case 21:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-100000.txt",tam);
            break;
        case 22:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-1000000.txt",tam);
            break;
        default:
            break;
        }

        
        temp = time(NULL); // Ordenação de um vetor de strings ou inteiro usando o algoritmo de ordenação por seleção BubbleSort. 
                            //Em seguida mede o tempo decorrido pela ordenação e imprime o número de comparações realizadas.
        if(escolha < 7){
            comp = BubbleSort(vString,tam);
        }else{
            comp = BubbleSort(vInt,tam);
        }
        temp2 = time(NULL);
        cout  << " Tempo: " << difftime(temp2,temp) << " Numero de Comparacoes: " << comp ; // difftime calcula a diferença entre as duas variáveis de tempo.
        break;
    case 2:
        system("cls");
        SegundoMenuInstancias(); // Imprime o Menu das Instâncias
        cout << "\n"<<"Qual a sua escolha: ";
        cin >> escolha;
        while(escolha<1 && escolha>22){
            cout << "Invalido!"<<endl;
            cin >> escolha;
        }
        switch (escolha)
        {
            // Cada escolha, tem a finalidade de preencher o array com valores lidos do arquivo.

        case 1:
            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioAleatorio-29855.txt",tam);
            break;
        case 2:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioAleatorio-261791.txt",tam);
            break;
        case 3:
            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioInversamenteOrdenado-29855.txt",tam);
            break;
        case 4:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioInversamenteOrdenado-261791.txt",tam);
            break;
        case 5:
            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioOrdenado-29855.txt",tam);
            break;
        case 6:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioOrdenado-261791.txt",tam);
            break;
        case 7:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-1000.txt",tam);
            break;
        case 8:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-10000.txt",tam);
            break;
        case 9:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-100000.txt",tam);
            break;
        case 10:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-1000000.txt",tam);
            break;
        case 11:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-1000.txt",tam);
            break;
        case 12:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-10000.txt",tam);
            break;
        case 13:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-100000.txt",tam);
            break;
        case 14:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-1000000.txt",tam);
            break;
        case 15:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-1000.txt",tam);
            break;
        case 16:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-10000.txt",tam);
            break;
        case 17:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-100000.txt",tam);
            break;
        case 18:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-1000000.txt",tam);
            break;
        case 19:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-1000.txt",tam);
            break;
        case 20:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-10000.txt",tam);
            break;
        case 21:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-100000.txt",tam);
            break;
        case 22:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-1000000.txt",tam);
            break;
        default:
            break;
        }
    
        temp = time(NULL); // Ordenação de um vetor de strings ou inteiro usando o algoritmo de ordenação por seleção ShellSort. 
                            //Em seguida mede o tempo decorrido pela ordenação e imprime o número de comparações realizadas.
        if(escolha < 7){
            comp = ShellSort(vString,tam);
        }else{
            comp = ShellSort(vInt,tam);
        }
        temp2 = time(NULL);
        cout  << " Tempo: " << difftime(temp2,temp) << " Numero de Comparacoes: " << comp ; // difftime calcula a diferença entre as duas variáveis de tempo.
        break;
    case 3:
        system("cls");
        SegundoMenuInstancias(); // Imprime o Menu das Instâncias
        cout << "\n"<<"Qual a sua escolha: ";
        cin >> escolha;
        while(escolha<1 && escolha>22){
            cout << "Invalido!"<<endl;
            cin >> escolha;
        }
        switch (escolha)
        {
            // Cada escolha, tem a finalidade de preencher o array com valores lidos do arquivo.

        case 1:
            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioAleatorio-29855.txt",tam);
            break;
        case 2:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioAleatorio-261791.txt",tam);
            break;
        case 3:
            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioInversamenteOrdenado-29855.txt",tam);
            break;
        case 4:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioInversamenteOrdenado-261791.txt",tam);
            break;
        case 5:
            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioOrdenado-29855.txt",tam);
            break;
        case 6:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioOrdenado-261791.txt",tam);
            break;
        case 7:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-1000.txt",tam);
            break;
        case 8:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-10000.txt",tam);
            break;
        case 9:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-100000.txt",tam);
            break;
        case 10:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-1000000.txt",tam);
            break;
        case 11:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-1000.txt",tam);
            break;
        case 12:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-10000.txt",tam);
            break;
        case 13:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-100000.txt",tam);
            break;
        case 14:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-1000000.txt",tam);
            break;
        case 15:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-1000.txt",tam);
            break;
        case 16:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-10000.txt",tam);
            break;
        case 17:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-100000.txt",tam);
            break;
        case 18:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-1000000.txt",tam);
            break;
        case 19:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-1000.txt",tam);
            break;
        case 20:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-10000.txt",tam);
            break;
        case 21:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-100000.txt",tam);
            break;
        case 22:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-1000000.txt",tam);
            break;
        default:
            break;
        }
    
        temp = time(NULL); // Ordenação de um vetor de strings ou inteiro usando o algoritmo de ordenação por seleção SelectionSort. 
                            //Em seguida mede o tempo decorrido pela ordenação e imprime o número de comparações realizadas.
        if(escolha < 7){
            comp = SelectionSort(vString,tam);
        }else{
            comp = SelectionSort(vInt,tam);
        }
        temp2 = time(NULL);
        cout  << " Tempo: " << difftime(temp2,temp) << " Numero de Comparacoes: " << comp ; // difftime calcula a diferença entre as duas variáveis de tempo.
        break;
    case 4:
        system("cls");
        SegundoMenuInstancias(); // Imprime o Menu das Instâncias
        cout << "\n"<<"Qual a sua escolha: ";
        cin >> escolha;
        while(escolha<1 && escolha>22){
            cout << "Invalido!"<<endl;
            cin >> escolha;
        }
        switch (escolha)
        {
            // Cada escolha, tem a finalidade de preencher o array com valores lidos do arquivo.

        case 1:
            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioAleatorio-29855.txt",tam);
            break;
        case 2:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioAleatorio-261791.txt",tam);
            break;
        case 3:
            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioInversamenteOrdenado-29855.txt",tam);
            break;
        case 4:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioInversamenteOrdenado-261791.txt",tam);
            break;
        case 5:
            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioOrdenado-29855.txt",tam);
            break;
        case 6:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioOrdenado-261791.txt",tam);
            break;
        case 7:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-1000.txt",tam);
            break;
        case 8:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-10000.txt",tam);
            break;
        case 9:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-100000.txt",tam);
            break;
        case 10:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-1000000.txt",tam);
            break;
        case 11:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-1000.txt",tam);
            break;
        case 12:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-10000.txt",tam);
            break;
        case 13:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-100000.txt",tam);
            break;
        case 14:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-1000000.txt",tam);
            break;
        case 15:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-1000.txt",tam);
            break;
        case 16:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-10000.txt",tam);
            break;
        case 17:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-100000.txt",tam);
            break;
        case 18:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-1000000.txt",tam);
            break;
        case 19:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-1000.txt",tam);
            break;
        case 20:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-10000.txt",tam);
            break;
        case 21:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-100000.txt",tam);
            break;
        case 22:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-1000000.txt",tam);
            break;
        default:
            break;
        }
    
        temp = time(NULL); // Ordenação de um vetor de strings ou inteiro usando o algoritmo de ordenação por seleção InsertionSort. 
                            //Em seguida mede o tempo decorrido pela ordenação e imprime o número de comparações realizadas.
        if(escolha < 7){
            comp = InsertionSort(vString,tam);
        }else{
            comp = InsertionSort(vInt,tam);
        }
        temp2 = time(NULL);
        cout  << " Tempo: " << difftime(temp2,temp) << " Numero de Comparacoes: " << comp ; // difftime calcula a diferença entre as duas variáveis de tempo.
        break;
    case 5:
        system("cls");
        SegundoMenuInstancias(); // Imprime o Menu das Instâncias
        cout << "\n"<<"Qual a sua escolha: ";
        cin >> escolha;
        while(escolha<1 && escolha>22){
            cout << "Invalido!"<<endl;
            cin >> escolha;
        }
        switch (escolha)
        {
            // Cada escolha, tem a finalidade de preencher o array com valores lidos do arquivo.

        case 1:
            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioAleatorio-29855.txt",tam);
            break;
        case 2:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioAleatorio-261791.txt",tam);
            break;
        case 3:
            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioInversamenteOrdenado-29855.txt",tam);
            break;
        case 4:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioInversamenteOrdenado-261791.txt",tam);
            break;
        case 5:
            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioOrdenado-29855.txt",tam);
            break;
        case 6:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioOrdenado-261791.txt",tam);
            break;
        case 7:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-1000.txt",tam);
            break;
        case 8:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-10000.txt",tam);
            break;
        case 9:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-100000.txt",tam);
            break;
        case 10:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-1000000.txt",tam);
            break;
        case 11:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-1000.txt",tam);
            break;
        case 12:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-10000.txt",tam);
            break;
        case 13:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-100000.txt",tam);
            break;
        case 14:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-1000000.txt",tam);
            break;
        case 15:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-1000.txt",tam);
            break;
        case 16:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-10000.txt",tam);
            break;
        case 17:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-100000.txt",tam);
            break;
        case 18:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-1000000.txt",tam);
            break;
        case 19:
            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-1000.txt",tam);
            break;
        case 20:
            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-10000.txt",tam);
            break;
        case 21:
            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-100000.txt",tam);
            break;
        case 22:
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-1000000.txt",tam);
            break;
        default:
            break;
        }
    
        temp = time(NULL); // Ordenação de um vetor de strings ou inteiro usando o algoritmo de ordenação por seleção QuickSort. 
                            //Em seguida mede o tempo decorrido pela ordenação e imprime o número de comparações realizadas. 
        if(escolha < 7){
            comp = QuickSort(vString,0,tam-1);
        }else{
            comp = QuickSort(vInt,0,tam-1);
        }
        temp2 = time(NULL);
        cout  << " Tempo: " << difftime(temp2,temp) << " Numero de Comparacoes: " << comp ; // difftime calcula a diferença entre as duas variáveis de tempo.
        break;
    case 6:
        system("cls");
        SegundoMenuInstancias(); // Imprime o Menu das Instâncias
        cout << "\n"<<"Qual a sua escolha: ";
        cin >> escolha;
        while(escolha<1 && escolha>22){
            cout << "Invalido!"<<endl;
            cin >> escolha;
        }
        switch (escolha)
        {
            // Cada escolha, tem a finalidade de preencher o array com valores lidos do arquivo.

        case 1:

            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioAleatorio-29855.txt",tam);
            break;
        case 2:
            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioAleatorio-261791.txt",tam);
            break;
        case 3:

            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioInversamenteOrdenado-29855.txt",tam);
            break;
        case 4:

            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioInversamenteOrdenado-261791.txt",tam);
            break;
        case 5:

            tam = 29855;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioOrdenado-29855.txt",tam);
            break;
        case 6:

            tam = 261791;
            vString = new string[tam];
            ordenaVetor(vString,"DicionarioOrdenado-261791.txt",tam);
            break;
        case 7:

            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-1000.txt",tam);
            break;
        case 8:

            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-10000.txt",tam);
            break;
        case 9:

            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-100000.txt",tam);
            break;
        case 10:

            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaAleatoria-1000000.txt",tam);
            break;
        case 11:

            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-1000.txt",tam);
            break;
        case 12:

            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-10000.txt",tam);
            break;
        case 13:

            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-100000.txt",tam);
            break;
        case 14:

            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaInversamenteOrdenada-1000000.txt",tam);
            break;
        case 15:

            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-1000.txt",tam);
            break;
        case 16:

            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-10000.txt",tam);
            break;
        case 17:

            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-100000.txt",tam);
            break;
        case 18:

            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaOrdenada-1000000.txt",tam);
            break;
        case 19:

            tam = 1000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-1000.txt",tam);
            break;
        case 20:

            tam = 10000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-10000.txt",tam);
            break;
        case 21:

            tam = 100000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-100000.txt",tam);
            break;
        case 22:
        
            tam = 1000000;
            vInt = new int[tam];
            ordenaVetor(vInt,"ListaQuaseOrdenada-1000000.txt",tam);
            break;

        default:
            break;
        }
    
        temp = time(NULL); // Ordenação de um vetor de strings ou inteiro usando o algoritmo de ordenação por seleção MergeSortP. 
                            //Em seguida mede o tempo decorrido pela ordenação e imprime o número de comparações realizadas. 
        if(escolha < 7){
            comp = MMergeSortP(vString,0,tam-1);
        }else{
            comp = MMergeSort(vInt,0,tam-1);
        }
        temp2 = time(NULL);
        cout  << " Tempo: " << difftime(temp2,temp) << " Numero de Comparacoes: " << comp ; // difftime calcula a diferença entre as duas variáveis de tempo.
        break;
    case 7:
        cout << "";
        break;

    default:
        break;
   

    }

}