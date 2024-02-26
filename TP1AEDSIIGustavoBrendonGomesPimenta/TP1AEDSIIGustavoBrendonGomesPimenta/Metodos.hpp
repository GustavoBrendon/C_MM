#ifndef ORDENACAO_H
#define ORDENACAO_H
#include "Metodos.cpp"

void ordenaVetor(auto vet[],string nome,int tam);// Função que lê valores do arquivo de entrada e armazena em um vetor.
int BubbleSort(auto vet[], int tamanho); // Função algoritma de ordenação simples que percorre o vetor várias vezes, comparando pares de elementos adjacentes e trocando-os se estiverem na ordem errada.
int InsertionSort(auto vet[],int tamanho); // Função algoritma de ordenação que percorre o vetor e insere cada elemento em sua posição correta em relação aos elementos anteriores.
int SelectionSort(auto vet[], int tamanho); // Função algoritma de ordenação que percorre o vetor várias vezes, selecionando o menor elemento e colocando-o na posição correta.
int ShellSort(auto vet[],int tamanho); // Função algoritma de ordenação que é uma variação do InsertionSort e divide o vetor em subvetores menores para ordená-los separadamente.
int QuickSort(auto vet[],int esquerda,int direita); // Função algoritma de ordenação que usa a estratégia "dividir para conquistar", escolhendo um pivô e dividindo o vetor em duas partições: elementos menores que o pivô e elementos maiores que o pivô. Essa divisão é feita recursivamente até que todo o vetor esteja ordenado.
int MergeSort(int vet[], int inicio, int fim); // Função algoritma de ordenação que também usa a estratégia "dividir para conquistar", dividindo o vetor em duas metades e ordenando cada uma delas recursivamente. Em seguida, mescla as duas metades em um vetor ordenado.
int MergeSortP(string vet[], int inicio, int fim); // Função que é uma variação do MergeSort que recebe um vetor de strings em vez de um vetor de inteiros.

#endif