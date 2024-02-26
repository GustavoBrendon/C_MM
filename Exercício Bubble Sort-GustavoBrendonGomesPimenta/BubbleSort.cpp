#include <iostream>
#include <windows.h>

using namespace std;

int BubbleSortCrescente(int Vetor[], int tamanho)
{
    int aux1, nuntrocas;
    cout<<"Vetor Original: ";
    for(int i = 0; i< tamanho; i++)
    {
        cout<<Vetor[i]<<", ";
    }
    cout<<endl;
    nuntrocas = 0;
    for (int i = 0; i < tamanho - 1; i++)
    { 
        
        for (int j = 1; j < tamanho - i; j++)
        {
            if (Vetor[j] < Vetor[j - 1])
            {
                aux1 = Vetor[j];
                Vetor[j] = Vetor[j - 1];
                Vetor[j - 1] = aux1;
                nuntrocas++;
            }
        }
        if (nuntrocas == 0)
        {
            break;
        }
    }
    cout<<"Vetor Crescente: ";
    for(int i = 0; i< tamanho; i++)
    {
        cout<<Vetor[i]<<", ";
    }
    cout<<endl<<"nuntrocass: "<<nuntrocas<<endl;
    
}

int BubbleSortDecrescente(int Vetor[], int tamanho)
{
    int aux1, nuntrocas;
    nuntrocas = 0;
    for (int i = 0; i < tamanho; i++)
    {
        
        for (int j = i+1; j < tamanho; j++)
        {
            if (Vetor[j] > Vetor[i])
            {
                aux1 = Vetor[j];
                Vetor[j] = Vetor[i];
                Vetor[i] = aux1;
                nuntrocas++;
                
            }
        }
        
        if (nuntrocas == 0)
        {
            break;
        }
    }
    cout<<"Vetor Decrescente: ";
    for(int i = 0; i< tamanho; i++)
    {
        cout<<Vetor[i]<<", ";
    }
    cout<<endl<<"nuntrocass: "<<nuntrocas<<endl;
    
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int tamanho = 10;
    int Vetor[tamanho] = {8,11,20,5,17,30,14,15,28,19};
    BubbleSortCrescente(Vetor, tamanho);
    BubbleSortDecrescente(Vetor, tamanho);

    cout << endl;
    return 0;
}