#include <iostream>
#include <vector>
#include <fstream>
#include "funcoes.hpp"

using namespace std;

class Grafo
{
private:
    vector<vector<int>> matriz;
    int quantidadeVertices;
    int quantidadeArestas;
    bool direcionado;
    vector<Vertice> vertices;

public:
    void menuPrincipal()
    {
        cout << "\n \t   1. Importar Grafo Pronto          ";
        cout << "\n \t   2. Criar Grafo Vazio              ";
        cout << "\n \t   3. Imprimir o Grafo               ";
        cout << "\n \t   4. Consultar Vértice Adjacente    ";
        cout << "\n \t   5. Inserir Novas Arestas          ";
        cout << "\n \t   6. Remover Arestas Existentes     ";
        cout << "\n \t   7. Editar Coordenadas dos Vértices";
        cout << "\n \t   8. Consultar Primeiro Adjacente   ";
        cout << "\n \t   9. Consultar Próximo Adjacente    ";
        cout << "\n \t   10. Consultar Lista de Adjacentes ";
        cout << "\n \t   11. Exportar Grafo                ";
        cout << "\n \t   0. Sair                           ";
    }

    void importarArquivo()
    {
        ifstream arquivo("grafo.txt");

        if (arquivo.is_open())
        {
            string linha;
            arquivo >> linha;
            direcionado = !(linha.compare("false") == 0);

            arquivo >> quantidadeVertices;
            criarGrafoVazio(quantidadeVertices);

            for (int i = 0; i < quantidadeVertices; i++)
            {
                int a, b, c;
                arquivo >> a >> b >> c;
                Vertice vertice(a, b, c);
                vertices[a] = vertice;
            }

            arquivo >> quantidadeArestas;

            for (int i = 0; i < quantidadeArestas; i++)
            {
                int origem, destino, peso;

                arquivo >> origem >> destino >> peso;
                inserirAresta(origem, destino, peso);

            }
            arquivo.close();
        }
        else
        {
            cout << "\n Não foi possível ler o arquivo!" << endl;
        }
    }

    void inserirAresta(int origem, int destino, int peso)
    {
        if (matriz[origem][destino] == -1)
        {
            matriz[origem][destino] = peso;
            menuPrincipal();
            if (!direcionado)
            {
                matriz[destino][origem] = peso;
            }

            quantidadeArestas++;
            menuPrincipal();
        }
    }

    void removerAresta(int origem, int destino)
    {
        if (matriz[origem][destino] != -1)
        {
            matriz[origem][destino] = -1;

            if (!direcionado)
            {
                matriz[destino][origem] = -1;
            }

            quantidadeArestas--;
        }
    }

    void resetarMatriz()
    {
        for (int i = 0; i < quantidadeVertices; i++)
        {
            for (int j = 0; j < quantidadeVertices; j++)
            {
                matriz[i][j] = -1;
            }
        }
    }

    void criarGrafoVazio(int quantidadeVertices)
    {
        this->quantidadeVertices = quantidadeVertices;
        vertices.resize(quantidadeVertices);
        matriz.resize(quantidadeVertices, vector<int>(quantidadeVertices, -1));
        resetarMatriz();
    }

    void imprimirMatriz()
    {
        for (int i = 0; i < quantidadeVertices; i++)
        {
            for (int j = 0; j < quantidadeVertices; j++)
            {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool verificarVizinhos(int origem, int destino)
    {
        if (matriz[origem][destino] != -1)
        {
            return true;
        }
        return false;
    }

    void editarCoordenadas(int vertice, int x, int y)
    {
        vertices[vertice].setCoordenadaX(x);
        vertices[vertice].setCoordenadaY(y);
    }

    int consultarPrimeiroAdjacente(int origem)
    {
        for (int i = 0; i < quantidadeVertices; i++)
        {
            if (matriz[origem][i] != -1)
            {
                return i;
            }
        }
        return -1;
    }

    int consultarProximoAdjacente(int vertice, int origem)
    {
        bool encontrado = false;

        for (int i = origem+1; i < quantidadeVertices; i++)
        {
           if (matriz[vertice][i] > -1)
           {
            encontrado = true;
            return i;
           }
           
        }
        return -1;
    }

    void consultarLista(int origem)
    {
        cout << "\n Os vértices adjacentes são: ";

        for (int i = 0; i < quantidadeVertices; i++)
        {
            if (matriz[origem][i] != -1)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    void exportarArquivo()
    {
        ofstream arquivo("resultado.txt");

        if (arquivo.is_open())
        {
            if (direcionado)
            {
                arquivo << "true" << endl;
            }
            else
            {
                arquivo << "false" << endl;
            }

            arquivo << quantidadeVertices << endl;

            for (int i = 0; i < quantidadeVertices; i++)
            {
                Vertice vertice = vertices[i];
                arquivo << vertice.getId() << " " << vertice.getCoordenadaX() << " " << vertice.getCoordenadaY() << endl;
            }

            if (direcionado)
            {
                arquivo << quantidadeArestas << endl;
            }
            else
            {
                arquivo << quantidadeArestas * 2 << endl;
            }

            for (int i = 0; i < quantidadeVertices; i++)
            {
                for (int j = 0; j < quantidadeVertices; j++)
                {
                    if (matriz[i][j] != -1)
                    {
                        arquivo << i << " " << j << " " << matriz[i][j] << endl;
                    }
                }
            }

            arquivo.close();
        }
        else
        {
            cout << "\n Não foi possível criar o arquivo!" << endl;
        }
    }

    void criarVertices()
    {
        int x, y;

        for (int i = 0; i < quantidadeVertices; i++)
        {
            cout << "\n Digite o eixo X do vértice: ";
            cin >> x;
            cout << "\n Digite o eixo Y do vértice: ";
            cin >> y;

            vertices[i] = Vertice(i, x, y);
        }
    }

    int getQuantidadeVertices()
    {
        return quantidadeVertices;
    }

    void setQuantidadeVertices(int quantidadeVertices)
    {
        this->quantidadeVertices = quantidadeVertices;
    }

    int getQuantidadeArestas()
    {
        return quantidadeArestas;
    }

    void setQuantidadeArestas(int quantidadeArestas)
    {
        this->quantidadeArestas = quantidadeArestas;
    }

    bool isDirecionado()
    {
        return direcionado;
    }

    void setDirecionado(bool direcionado)
    {
        this->direcionado = direcionado;
    }
};
