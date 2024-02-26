#include <iostream>
#include <windows.h>
#include "funcoes.cpp"

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    Grafo* grafo = new Grafo();

    int resposta = 0, direcionado = 0;
    int origem, destino, peso, quantidadeVertices;
    int vertice, x, y;
    string nome;

    do
    {
        system("cls");
        grafo->menuPrincipal();
        cout << endl << "\n \t Digite a opção desejada: ";
        cin >> resposta;

        switch (resposta)
        {
        case 1:
            system("cls");
            grafo->importarArquivo();
            cout << "Arquivo Importado" << endl;
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "\n O grafo é direcionado? 1-(Sim) 2-(Não): ";
            cin >> direcionado;

            if (direcionado == 1)
            {
                grafo->setDirecionado(true);
            }
            else if (direcionado == 2)
            {
                grafo->setDirecionado(false);
            }

            cout << "\n Digite a quantidade de vértices: ";
            cin >> quantidadeVertices;

            grafo->criarGrafoVazio(quantidadeVertices);
            grafo->criarVertices();
            break;

        case 3:
            system("cls");
            grafo->imprimirMatriz();
            system("pause");
            break;

        case 4:
            system("cls");
            cout << "\n Digite a origem do vértice: ";
            cin >> origem;
            cout << "\n Digite o destino do vértice: ";
            cin >> destino;

            if (grafo->verificarVizinhos(origem, destino))
            {
                cout << "\n Os vértices " << origem << " e " << destino << " são adjacentes!";
            }
            else
            {
                cout << "\n Os vértices " << origem << " e " << destino << " não são adjacentes!";
            }
            system("pause");
            cout << endl;
            break;

        case 5:
            system("cls");

            cout << "\n Digite a origem do vértice: ";
            cin >> origem;
            cout << "\n Digite o destino do vértice: ";
            cin >> destino;
            cout << "\n Digite o peso do vértice: ";
            cin >> peso;

            grafo->inserirAresta(origem, destino, peso);

            break;

        case 6:
            system("cls");
            cout << "\n Digite a origem do vértice: ";
            cin >> origem;
            cout << "\n Digite o destino do vértice: ";
            cin >> destino;
            system("pause");
            grafo->removerAresta(origem, destino);
            break;

        case 7:
            system("cls");
            cout << "\n Digite o vértice que deseja editar: ";
            cin >> vertice;
            cout << "\n Digite a coordenada do eixo X: ";
            cin >> x;
            cout << "\n Digite a coordenada do eixo Y: ";
            cin >> y;

            grafo->editarCoordenadas(vertice, x, y);
            break;

        case 8:
            system("cls");
            cout << "\n Digite o vértice que deseja editar: ";
            cin >> vertice;
            cout << "\n Digite o novo nome: ";
            cin >> nome;
            grafo->editarNomeVertice(vertice, nome);
            break;

        case 9:
            system("cls");
            cout << "\n Digite a origem: ";
            cin >> origem;
            cout << "\n O primeiro adjacente é: " << grafo->consultarPrimeiroAdjacente(origem) << endl;
            system("pause");
            break;

        case 10:
            system("cls");
            cout << "\n Digite o vértice: ";
            cin >> vertice;
            cout << "\n Digite a origem: ";
            cin >> origem;
            cout << "\n O próximo adjacente é: " << grafo->consultarProximoAdjacente(vertice, origem) << endl;
            system("pause");
            break;

        case 11:
            system("cls");
            cout << "\n Digite a origem: ";
            cin >> origem;
            grafo->consultarLista(origem);
            cout << endl;
            system("pause");
            break;

        case 12:
             system("cls");
                {
                    string nomeOrigem, nomeDestino;
                    cout << "\n Digite o nome do vértice de origem: ";
                    cin >> nomeOrigem;
                    cout << "\n Digite o nome do vértice de destino: ";
                    cin >> nomeDestino;
                    grafo->menorCaminhoDijkstra(nomeOrigem, nomeDestino);
                    cout << endl;
                    system("pause");
                    break;
                }
        case 13:
            system("cls");
            cout << "\n Digite o vértice inicial para a busca em profundidade: ";
            cin >> origem;
            grafo->buscaProfundidade(origem);
            system("pause");
            break;

        case 14:
            system("cls");
            cout << "\n Digite o vértice inicial para a busca em largura: ";
            cin >> origem;
            grafo->buscaLargura(origem);
            system("pause");
            break;

        case 15:
            system("cls");
            grafo->primAGM();
            system("pause");
            break;

        case 16:
            system("cls");
            grafo->exportarArquivo();
            cout << "Arquivo Exportado Com Sucesso" << endl;
            system("pause");
            break;

        default:
            if (resposta != 0)
            {
                cout << "\n Nenhuma função corresponde a essa opção! Tente novamente!";
                system("pause");
            }
        }
    } while (resposta != 0);

    cout << endl;
    return 0;
}

