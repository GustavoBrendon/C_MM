#include "Arvore.hpp"

bool insereItemnun(Item item) {
    TipoNo novo = new Arvore;
    novo->item = item;
    novo->direita = NULL;
    novo->esquerda = NULL;

    if(arvoreNUN == NULL) {
        arvoreNUN = novo;
        return true;
    }

    TipoNo anterior;
    TipoNo atual = arvoreNUN;

    while(atual != NULL) {
        anterior = atual;
        if(item.nun < atual->item.nun) {
            atual = atual->esquerda;
        } else if(item.nun > atual->item.nun) {
            atual = atual->direita;
        }
    }

    if(novo->item.nun < anterior->item.nun) {
        anterior->esquerda = novo;
        return true;
    }
    if(novo->item.nun > anterior->item.nun) {
        anterior->direita = novo;
        return true;
    }
    return false;
}

void Antecessor(TipoNo q, TipoNo* r) {
    if((*r)->direita != NULL) {
        Antecessor(q, &(*r)->direita);
        return;
    }
    q->item = (*r)->item;
    q = *r;
    *r = (*r)->esquerda;
    delete q;
}

void removeItemPornun(TipoNo* atual, int nun) {
    TipoNo aux;
    if(*atual == NULL) {
        return;
    }
    if(nun < (*atual)->item.nun) {
        removeItemPornun(&(*atual)->esquerda, nun);
        return;
    }
    if(nun > (*atual)->item.nun) {
        removeItemPornun(&(*atual)->direita, nun);
        return;
    }
    if((*atual)->direita == NULL) {
        aux = *atual;
        *atual = (*atual)->esquerda;
        delete aux;
        return;
    }
    if((*atual)->esquerda != NULL) {
        Antecessor(*atual, &(*atual)->esquerda);
        return;
    }
    aux = *atual;
    *atual = (*atual)->direita;
    delete atual;
}

bool insereItemNome(Item item) {
    TipoNo novo = new Arvore;
    novo->item = item;
    novo->direita = NULL;
    novo->esquerda = NULL;

    if(arvoreNome == NULL) {
        arvoreNome = novo;
        return true;
    }

    TipoNo anterior;
    TipoNo atual = arvoreNome;

    while(atual != NULL) {
        anterior = atual;
        if(item.nome < atual->item.nome) {
            atual = atual->esquerda;
        } else if(item.nome > atual->item.nome) {
            atual = atual->direita;
        }
    }

    if(novo->item.nome < anterior->item.nome) {
        anterior->esquerda = novo;
        return true;
    }
    if(novo->item.nome > anterior->item.nome) {
        anterior->direita = novo;
        return true;
    }
    return false;
}

void removeItemPorNome(TipoNo* atual, string nome) {
    TipoNo aux;
    if(*atual == NULL) {
        return;
    }
    if(nome < (*atual)->item.nome) {
        removeItemPorNome(&(*atual)->esquerda, nome);
        return;
    }
    if(nome > (*atual)->item.nome) {
        removeItemPorNome(&(*atual)->direita, nome);
        return;
    }
    if((*atual)->direita == NULL) {
        aux = *atual;
        *atual = (*atual)->esquerda;
        delete aux;
        return;
    }
    if((*atual)->esquerda != NULL) {
        Antecessor(*atual, &(*atual)->esquerda);
        return;
    }
    aux = *atual;
    *atual = (*atual)->direita;
    delete atual;
}

void imprimeArvore(TipoNo atual) {
    if(atual != NULL) {
        imprimeArvore(atual->esquerda);
        cout << "CPF: " << atual->item.nun << " - Nome: " << atual->item.nome << endl;
        imprimeArvore(atual->direita);
    }
        
   

}

TipoNo pesquisaPornun(TipoNo raiz, int nun) {
    TipoNo aux = raiz;
    bool encontrou = false;
    while(aux != NULL) {
        if(aux->item.nun == nun) {
            encontrou = true;
            break;
        }
        if(nun < aux->item.nun) {
            aux = aux->esquerda;
        }
        if(nun > aux->item.nun) {
            aux = aux->direita;
        }
    }
    if(encontrou) {
        return aux;
    }
    return NULL;
}

TipoNo pesquisaPorNome(TipoNo raiz, string nome) {
    TipoNo aux = raiz;
    bool encontrou = false;
    while(aux != NULL) {
        if(aux->item.nome == nome) {
            encontrou = true;
            break;
        }
        if(nome < aux->item.nome) {
            aux = aux->esquerda;
        }
        if(nome > aux->item.nome) {
            aux = aux->direita;
        }
    }
    if(encontrou) {
        return aux;
    }
    return NULL;
}

void imprimeItem(Item item) {
    cout << endl;
    cout << "FUNCIONARIO ABAIXO" << endl;
    cout << "CPF: " << item.nun << endl;
    cout << "Nome: " << item.nome << endl;
    system("pause");
}