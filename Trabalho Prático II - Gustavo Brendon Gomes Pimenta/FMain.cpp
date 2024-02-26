#include "FMain.hpp"
#include "Arvore.cpp"

void cadastrarFuncionario() {
    Item funcionario;

    system("cls");
    cout << "CPF do Funcionario: ";
    cin >> funcionario.nun;
    cout << "Nome do Funcionario: ";
    cin >> funcionario.nome;

    system("cls");
    if(insereItemnun(funcionario) && insereItemNome(funcionario)) {
        cout << "FUNCIONARIO CADASTRADO" << endl;
    } else {
        cout << "ERRO OU JA CADASTRADO" << endl;
    }
}

void buscarFuncionario() {
    int nun;
    string nome;

    int opcao;

    do {
        system("cls");
        cout << " |1 - Buscar por CPF |" << endl;
        cout << " |2 - Buscar por Nome|" << endl;
        cout << " Digite a opcao que deseja prosseguir: ";
        cin >> opcao;
    } while(opcao != 1 && opcao != 2);

    TipoNo aux;

    if(opcao == 1) {
        cout << "CPF do Funcionario: ";
        cin >> nun;
        aux = pesquisaPornun(arvoreNUN, nun);
    } else {
        cout << "Nome do Funcionario: ";
        cin >> nome;
        aux = pesquisaPorNome(arvoreNome, nome);
    }
    system("cls");
    if(aux == NULL) {
        cout << "NAO ENCONTRADO!!!" << endl;
    } else {
        imprimeItem(aux->item);
    }
}

void removerFuncionario() {
    int nun;
    string nome;

    int opcao;

    do {
        system("cls");
        cout << " |1 - Remover por CPF |" << endl;
        cout << " |2 - Remover por Nome|" << endl;
        cout << " Digite a opcao que deseja prosseguir: ";
        cin >> opcao;
    } while(opcao != 1 && opcao != 2);

    TipoNo aux;

    system("cls");
    if(opcao == 1) {
        cout << "CPF do Funcionario: ";
        cin >> nun;
        aux = pesquisaPornun(arvoreNUN, nun);
    } else {
        cout << "Nome do Funcionario: ";
        cin >> nome;
        aux = pesquisaPorNome(arvoreNome, nome);
    }
    
    system("cls");
    if(aux == NULL) {
        cout << "NAO ENCONTRADO !!!" << endl;
    } else {
        removeItemPornun(&arvoreNUN, aux->item.nun);
        removeItemPorNome(&arvoreNUN, aux->item.nome);
        cout << "FUNCIONARIO REMOVIDO !!!" << endl;
    }
}