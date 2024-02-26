#include <iostream>
#include "Metodos.hpp"
 
using namespace std;

void ordenaVetor(auto vet[],string nome,int tam){ //  Função que lê valores do arquivo de entrada e armazena em um vetor.
    ifstream arqEntrada;
    arqEntrada.open(nome);
    for(int i = 0;i<tam;i++){
        arqEntrada >> vet[i];
    }
}
 
int BubbleSort(auto vet[], int tamanho){  //Função que consiste em percorrer o vetor várias vezes, comparando elementos e trocando-os se estiverem fora de ordem.
                                            // O algoritmo tem complexidade O(n²) no pior caso, onde "n" é o número de elementos do vetor.    
    auto aux = vet[0];
    int troca,cmp=0;

    for (int i = 0; i < tamanho -1; i++) { 
         troca = 0;                         
       
        for (int j = 1; j < tamanho-i; j++) { 
            cmp++;                               
            if (vet [j] < vet [j-1]) { 
                aux = vet [j];
              
                vet [j] = vet[j-1];
                vet [j-1]  = aux;
                troca = 1;
            }                       
        }
        if (troca == 0){ 
            
            break;
        }
    }
    return cmp; 
}

int InsertionSort(auto vet[],int tamanho){ // Função que percorre um vetor de elementos desordenados e vai posicionando cada um deles na posição correta, de forma que o vetor fique ordenado ao final do processo.
    auto aux = vet[0];                      // Complexidade O(n²) no pior caso, onde "n" é o número de elementos do vetor.
    int i=0,j=1,cmp = 0;
    cmp++;
    while(j<tamanho){
        aux = vet[j];
        i=j-1;
        cmp += 2;
        while((i>=0) && (vet[i]>aux)){
            vet[i+1] = vet[i];
            i = i-1;
        }
        vet[i+1] = aux;
        j = j+1;
    }
    return cmp;
}

int SelectionSort(auto vet[], int tamanho){ // Função que consiste em encontrar o menor elemento do vetor e trocá-lo de posição com o primeiro elemento. Em seguida, o segundo menor elemento é encontrado e trocado com o segundo elemento, e assim por diante, até que o vetor esteja completamente ordenado.
    auto aux = vet[0];                        // O algoritmo tem complexidade O(n²) no pior caso, onde "n" é o número de elementos do vetor.
    int min,cmp = 0;
    for(int i = 0; i<tamanho-1;i++){
        min = i;
        for(int j=i+1;j<tamanho;j++){
            cmp++;
            if(vet[j]<vet[min]){
                min = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
    return cmp;
}

int ShellSort(auto vet[],int tamanho){ // Função que é uma variação do algoritmo Insertion Sort que utiliza um incremento "h" para realizar a ordenação.
    auto valor = vet[0];                 // O algoritmo tem complexidade O(n log² n) no pior caso.
    int i,j,cmp=0;

    int h=1;
    while(h<tamanho){
       h=3*h+1;
    }

    while(h>0){
        for(i=h;i<tamanho;i++){
            valor = vet[i];
            j=i;
            cmp+=2;
            while(j>h-1 && valor <= vet[j-h]){
                vet[j] = vet[j-h];
                j = j-h;
            }
            vet[j] = valor;
        }
        h=h/3;
    }
    return cmp;
}

int QuickSort(auto vet[],int E,int D){ // Função que é chamada recursivamente para ordenar as duas metades do array, selecionando um elemento pivô.
    int i = E, j= D,cmp = 0;
    auto aux = vet[0], pivo = vet[(E + D)/2];

    while (i<=j){
        cmp++;
        while(vet[i]< pivo){
            i++;
            cmp++;
        }
        cmp++;
        while(vet[j] > pivo){
            j--;
            cmp++;
        }
        cmp++;
        if(i <= j){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    }
    cmp++;
    if(E < j)
        QuickSort(vet,E,j);
    cmp++;
    if(i < D)
        QuickSort(vet,i,D);
    return cmp;
}

int IntercalaMMerge(int vet[], int inicio, int meio, int fim){ //Função que recebe um vetor, um índice de início, um índice de meio e um índice de fim, indicando as partes do vetor a serem IntercalaMMergedas.
    int * vetAux = (int *) malloc(sizeof(int)*(fim+1));
    int i,j,cmp = 0;

    for(i=inicio;i<=meio;i++){
        vetAux[i] = vet[i];
    }

    for(j=meio+1; j<=fim;j++){
        vetAux[fim+meio+1-j] = vet[j];
    }

    i=inicio;
    j=fim;

    for(int k=inicio;k<=fim;k++){
        cmp++;
        if(vetAux[i]<=vetAux[j]){
            vet[k]=vetAux[i];
            i++;
        }else{
            vet[k] = vetAux[j];
            j--;
        }
    }
    free(vetAux);
    return cmp;
}

int MMergeSort(int vet[], int inicio, int fim){ // Função recebe um vetor, um índice de início, um índice de meio e um índice de fim, indicando as partes do vetor a serem intercaladas.
    int meio,cmp=0;
    cmp++;
    if(inicio < fim){
        meio = (inicio + fim)/2;
        cmp += MMergeSort(vet,inicio,meio);
        cmp += MMergeSort(vet,meio+1,fim);
        cmp += IntercalaMMerge(vet,inicio,meio,fim);
    }
    return cmp;
}

int MMerge(string vet[], int inicio, int meio, int fim){ // Função que realiza a intercalação de dois subvetores de strings ordenados em ordem crescente.

    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int cmp = 0;
    string L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = vet[inicio + i];
    for (int j = 0; j < n2; j++)
        M[j] = vet[meio + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2)
    {
        cmp++;
        if (L[i] <= M[j])
        {
            vet[k] = L[i];
            i++;
        }
        else
        {
            vet[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vet[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vet[k] = M[j];
        j++;
        k++;
    }
    return cmp;
}

int MMergeSortP(string vet[], int inicio, int fim){ //Função divide o array em duas metades e ordena cada metade recursivamente usando Merge Sort, depois combina as duas metades ordenadas usando a função MMerge.
    int cmp = 0;
    cmp++;
    if (inicio < fim)
    {
        int m = inicio + (fim - inicio) / 2;

        cmp += MMergeSortP(vet, inicio, m);
        cmp += MMergeSortP(vet, m + 1, fim);

        cmp += MMerge(vet, inicio, m, fim);
    }
    return cmp;
}