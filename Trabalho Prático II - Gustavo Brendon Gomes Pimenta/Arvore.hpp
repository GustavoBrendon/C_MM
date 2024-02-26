#ifndef ARVORE
#define ARVORE

#include <iostream>

using namespace std;


struct Item { 
                        // Struct do Funcionario      
    long int nun;
    string nome;
};

struct Arvore{           
                        // Nó da árvore
    Item item;
    Arvore* esquerda;
    Arvore* direita;
};

typedef Arvore* TipoNo;


TipoNo arvoreNUN = NULL; // Árvore em CPF

TipoNo arvoreNome = NULL; // Árvore em Nome

// Coloca o item na arvoreNUN baseada em CPF.
bool insereItemnun(Item item);
bool insereItemNome(Item item);

// Pega o antecessor do item 
void Antecessor(TipoNo q, TipoNo* r);

// Remove o item no CPF
void removeItemPornun(TipoNo* atual, int nun);

// Remove o item no Nome
void removeItemPorNome(TipoNo* atual, string nome);

// Imprime a árvore
void imprimeArvore(TipoNo atual);

#endif