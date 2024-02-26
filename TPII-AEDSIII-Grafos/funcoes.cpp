#include <iostream>
#include <vector>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <climits>
#include <algorithm>
#include "funcoes.hpp"

using namespace std;

class Grafo
{
private:
    vector<vector<int>> matriz;
    int quantidadeVertices;
    int quantidadeArestas = 0;
    bool direcionado;
    vector<Vertice> vertices;

int encontrarVerticeChaveMinima(const vector<int> &chave, const vector<bool> &incluido) // Encontra o vértice com a chave mínima durante o algoritmo de Prim.
    {
        int minimo = INT_MAX, indiceMinimo;

        for (int v = 0; v < quantidadeVertices; v++)
        {
            if (!incluido[v] && chave[v] < minimo)
            {
                minimo = chave[v];
                indiceMinimo = v;
            }
        }

        return indiceMinimo;
    }

    void mostrarAGMParcial(const vector<int> &pai) //Mostram a árvore geradora mínima durante o algoritmo de Prim.
    {
        cout << "   Vértice pai - Peso" << endl;
        for (int i = 1; i < quantidadeVertices; i++)
        {
            cout << "   " << pai[i] << "          - " << matriz[i][pai[i]] << endl;
        }
        cout << "--------------------------" << endl;
    }

    void mostrarAGMCompleta(const vector<int> &pai) //Mostram a árvore geradora mínima durante o algoritmo de Prim.
    {
        cout << "   Vértice pai - Peso" << endl;
        for (int i = 1; i < quantidadeVertices; i++)
        {
            cout << "   " << pai[i] << "          - " << matriz[i][pai[i]] << endl;
        }
        cout << "--------------------------" << endl;
        cout << " Peso total da Árvore Geradora Mínima: " << calcularPesoAGM(pai) << endl;
    }

    int calcularPesoAGM(const vector<int> &pai) //Calcula o peso total da árvore geradora mínima.
    {
        int pesoTotal = 0;
        for (int i = 1; i < quantidadeVertices; i++)
        {
            pesoTotal += matriz[i][pai[i]];
        }
        return pesoTotal;
    }

    bool verificarConexo() // Verifica se o grafo é conexo usando busca em profundidade.
    {
        // Utilizando busca em profundidade para verificar a conexidade
        vector<bool> visitado(quantidadeVertices, false);
        buscaConexo(0, visitado);

        for (bool v : visitado)
        {
            if (!v)
            {
                return false;
            }
        }

        return true;
    }

    void buscaConexo(int vertice, vector<bool> &visitado) //Realiza a busca em profundidade para verificar a conexidade.
    {
        visitado[vertice] = true;
        for (int i = 0; i < quantidadeVertices; i++)
        {
            if (matriz[vertice][i] != -1 && !visitado[i])
            {
                buscaConexo(i, visitado);
            }
        }
    }

public:
    void menuPrincipal() // Exibe um menu para interação com o usuário.
    {
        cout << "\n \t   1. Importar Grafo Pronto          ";
        cout << "\n \t   2. Criar Grafo Vazio              ";
        cout << "\n \t   3. Imprimir o Grafo               ";
        cout << "\n \t   4. Consultar Vértice Adjacente    ";
        cout << "\n \t   5. Inserir Novas Arestas          ";
        cout << "\n \t   6. Remover Arestas Existentes     ";
        cout << "\n \t   7. Editar Coordenadas dos Vértices";
        cout << "\n \t   8. Editar Nomes dos Vértices      ";
        cout << "\n \t   9. Consultar Primeiro Adjacente   ";
        cout << "\n \t   10. Consultar Próximo Adjacente   ";
        cout << "\n \t   11. Consultar Lista de Adjacentes ";
        cout << "\n \t   12. Menor Caminho (Dijkstra)      "; 
        cout << "\n \t   13. Busca em Profundidade         ";
        cout << "\n \t   14. Busca em Largura              ";
        cout << "\n \t   15. Árvore Geradora Mínima (Prim) ";
        cout << "\n \t   16. Exportar Grafo                ";
        cout << "\n \t   0.  Sair                          ";
    }

    void importarArquivo() //Importa um grafo a partir de um arquivo.
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
            string nome;
            arquivo >> a >> b >> c >> nome;
            Vertice vertice(a, b, c);
            vertice.setNome(nome);
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

    void inserirAresta(int origem, int destino, int peso) // Insere arestas no grafo.
    {
        if (matriz[origem][destino] == -1)
        {
            matriz[origem][destino] = peso;
            if (!direcionado)
            {
                matriz[destino][origem] = peso;
            }
            quantidadeArestas++;
        }
    }

        void editarNomeVertice(int vertice, string nome) //Edita os nomes dos vértices.
    {
        if (vertice >= 0 && vertice < quantidadeVertices)
        {
            vertices[vertice].setNome(nome);
        }
        else
        {
            cout << "\n Vértice inválido!" << endl;
        }
    }

        void buscaProfundidade(int verticeInicial) // Realiza busca em profundidade.
    {
        // Vector para marcar os vértices visitados
        vector<bool> visitado(quantidadeVertices, false);
        // Pilha para realizar a busca
        stack<int> pilha;
        // Inicia a busca a partir do vértice inicial
        pilha.push(verticeInicial);
        cout << "\n Ordem de visita durante a busca em profundidade:" << endl;

        while (!pilha.empty())
        {
            // Pop o vértice do topo da pilha
            int verticeAtual = pilha.top();
            pilha.pop();
            // Se o vértice não foi visitado ainda
            if (!visitado[verticeAtual])
            {
                cout << " " << verticeAtual;
                // Marca o vértice como visitado
                visitado[verticeAtual] = true;
                // Empilha os vizinhos não visitados
                for (int i = quantidadeVertices - 1; i >= 0; i--)
                {
                    if (matriz[verticeAtual][i] != -1 && !visitado[i])
                    {
                        pilha.push(i);
                    }
                }
            }
        }

        cout << endl;
    }

     void buscaLargura(int verticeInicial) // Realiza busca em largura.
    {
        // Marcar todos os vértices como não visitados
        vector<bool> visitado(quantidadeVertices, false);
        // Criar uma fila para a busca
        queue<int> fila;
        // Marcar o vértice inicial como visitado e enfileirar
        visitado[verticeInicial] = true;
        fila.push(verticeInicial);
        cout << "\n Busca em Largura a partir do vértice " << verticeInicial << ": ";

        while (!fila.empty())
        {
            // Desenfileirar um vértice da fila e imprimir
            int atual = fila.front();
            cout << atual << " ";
            fila.pop();

            // Obter todos os vértices adjacentes ao vértice desenfileirado
            for (int i = 0; i < quantidadeVertices; i++)
            {
                // Verificar se o vértice ainda não foi visitado e se há uma aresta
                if (!visitado[i] && matriz[atual][i] != -1)
                {
                    // Marcar o vértice como visitado e enfileirar
                    visitado[i] = true;
                    fila.push(i);
                }
            }
        }

        cout << endl;
    }

    void primAGM() // Encontra a árvore geradora mínima usando o algoritmo de Prim.
    {
        // Verificar se o grafo é conexo
        if (!verificarConexo())
        {
            cout << "\n O grafo não é conexo. A árvore geradora mínima não pode ser construída." << endl;
            return;
        }

        vector<bool> incluido(quantidadeVertices, false);
        vector<int> chave(quantidadeVertices, INT_MAX);

        // Árvore Geradora Mínima (AGM)
        vector<int> pai(quantidadeVertices, -1);

        // Iniciar com o primeiro vértice
        chave[0] = 0;

        cout << "\n Construindo Árvore Geradora Mínima (Prim):" << endl;

        for (int i = 0; i < quantidadeVertices - 1; i++)
        {
            // Encontrar o vértice com a chave mínima
            int u = encontrarVerticeChaveMinima(chave, incluido);

            // Incluir o vértice na AGM
            incluido[u] = true;

            // Atualizar as chaves dos vértices adjacentes
            for (int v = 0; v < quantidadeVertices; v++)
            {
                if (matriz[u][v] != -1 && !incluido[v] && matriz[u][v] < chave[v])
                {
                    pai[v] = u;
                    chave[v] = matriz[u][v];
                }
            }

            // Mostrar informações do processo
            cout << "\n Passo " << i + 1 << ": Adicionado vértice " << u << " à Árvore Geradora Mínima." << endl;
            mostrarAGMParcial(pai);
        }

        // Mostra a AGM final
        cout << "\n Árvore Geradora Mínima (Prim) Concluída:" << endl;
        mostrarAGMCompleta(pai);
    }

        void menorCaminhoDijkstra(string nomeOrigem, string nomeDestino) // Método para encontrar o menor caminho usando o algoritmo de Dijkstra.
    {
        // Encontrar os índices dos vértices de origem e destino
        int indiceOrigem = encontrarIndicePorNome(nomeOrigem);
        int indiceDestino = encontrarIndicePorNome(nomeDestino);

        for (int i = 0; i < quantidadeVertices; i++)
        {
            if (vertices[i].getNome() == nomeOrigem)
            {
                indiceOrigem = i;
            }
            else if (vertices[i].getNome() == nomeDestino)
            {
                indiceDestino = i;
            }
        }

        // Verificar se os vértices de origem e destino foram encontrados
        if (indiceOrigem == -1 || indiceDestino == -1)
        {
            cout << "\n Vértices de origem ou destino não encontrados." << endl;
            return;
        }

        // Inicializar estruturas de dados para o algoritmo de Dijkstra
        vector<int> distancia(quantidadeVertices, INT_MAX);
        vector<bool> visitado(quantidadeVertices, false);

        // A distância de um vértice para ele mesmo é sempre 0
        distancia[indiceOrigem] = 0;

        // Algoritmo de Dijkstra
        for (int count = 0; count < quantidadeVertices - 1; count++)
        {
            // Escolher o vértice com a menor distância ainda não visitado
            int u = encontrarVerticeChaveMinima(distancia, visitado);

            // Marcar o vértice escolhido como visitado
            visitado[u] = true;

            // Atualizar as distâncias dos vértices adjacentes ao vértice escolhido
            for (int v = 0; v < quantidadeVertices; v++)
            {
                if (!visitado[v] && matriz[u][v] != -1 &&
                    distancia[u] != INT_MAX &&
                    distancia[u] + matriz[u][v] < distancia[v])
                {
                    distancia[v] = distancia[u] + matriz[u][v];
                }
            }
        }

    // Exibir a distância mínima do vértice de origem para o vértice de destino
    cout << "\n Menor caminho de " << nomeOrigem << " para " << nomeDestino << ": " << distancia[indiceDestino] << endl;
}

// Dentro da classe Grafo, adicione a função
int encontrarIndicePorNome(string nome)
{
    for (int i = 0; i < quantidadeVertices; i++)
    {
        if (vertices[i].getNome() == nome)
        {
            return i;
        }
    }
    return -1; // Retorna -1 se o nome do vértice não for encontrado
}

    void removerAresta(int origem, int destino) // Remove Aresta Existente.
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

    void resetarMatriz() // Reseta a matriz de adjacência para valores padrão.
    {
        for (int i = 0; i < quantidadeVertices; i++)
        {
            for (int j = 0; j < quantidadeVertices; j++)
            {
                matriz[i][j] = -1;
            }
        }
    }

        void criarGrafoVazio(int quantidadeVertices) // Inicializa um grafo vazio com a quantidade de vértices especificada.
        {
            this->quantidadeVertices = quantidadeVertices;
            vertices.resize(quantidadeVertices);
            matriz.resize(quantidadeVertices, vector<int>(quantidadeVertices, -1));
            resetarMatriz();
        }

        void imprimirMatriz() //  Imprime a matriz de adjacência.   
    {
        cout << "  ";
        for (int i = 0; i < quantidadeVertices; i++)
        {
            cout << vertices[i].getNome() << " ";
        }
        cout << endl;

        for (int i = 0; i < quantidadeVertices; i++)
        {
            cout << vertices[i].getNome() << " ";

            for (int j = 0; j < quantidadeVertices; j++)
            {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }


    bool verificarVizinhos(int origem, int destino) // Verifica se dois vértices são vizinhos.
    {
        if (matriz[origem][destino] != -1)
        {
            return true;
        }
        return false;
    }

    void editarCoordenadas(int vertice, int x, int y) // Edita as Coordenadas do Vértice.
    {
        vertices[vertice].setCoordenadaX(x);
        vertices[vertice].setCoordenadaY(y);
    }

    // Função para consultar o primeiro vértice adjacente a um vértice de origem em um grafo representado por uma matriz de adjacência.
int consultarPrimeiroAdjacente(int origem)
{
    // Percorre todos os vértices do grafo.
    for (int i = 0; i < quantidadeVertices; i++)
    {
        // Verifica se há uma aresta entre o vértice de origem e o vértice atual.
        if (matriz[origem][i] != -1)
        {
            // Se uma aresta for encontrada, retorna o índice do vértice adjacente.
            return i;
        }
    }
    
    // Fora do loop, se nenhum vértice adjacente for encontrado, retorna -1.
    return -1;
}


    int consultarProximoAdjacente(int vertice, int origem)
{
    // Variável para indicar se um vértice adjacente foi encontrado
    bool encontrado = false;

    // Itera sobre os vértices começando do índice seguinte ao vértice de origem
    for (int i = origem + 1; i < quantidadeVertices; i++)
    {
        // Verifica se há uma aresta entre o vértice e o vértice atual na matriz de adjacência
        if (matriz[vertice][i] > -1)
        {
            // Se uma aresta for encontrada, marca como encontrado e retorna o índice do vértice adjacente
            encontrado = true;
            return i;
        }
    }

    // Retorna -1 se nenhum vértice adjacente foi encontrado após o índice origem
    return -1;
}


    void consultarLista(int origem) // Realiza consultas relacionadas a vértices e arestas.
{
    // Exibe uma mensagem indicando o propósito da consulta
    cout << "\n Os vértices adjacentes são: ";

    // Itera sobre os vértices para verificar se há arestas saindo do vértice de origem
    for (int i = 0; i < quantidadeVertices; i++)
    {
        // Verifica se há uma aresta entre os vértices origem e i
        if (matriz[origem][i] != -1)
        {
            // Se houver, imprime o índice do vértice adjacente
            cout << i << " ";
        }
    }

    // Pula uma linha após a exibição dos vértices adjacentes
    cout << endl;
}


   void exportarArquivo() // Exporta o grafo para um arquivo.
{
    // Abre o arquivo "resultado.txt" para escrita
    ofstream arquivo("resultado.txt");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo.is_open())
    {
        // Escreve no arquivo se o grafo é direcionado ou não
        if (direcionado)
        {
            arquivo << "true" << endl;
        }
        else
        {
            arquivo << "false" << endl;
        }

        // Escreve no arquivo a quantidade de vértices
        arquivo << quantidadeVertices << endl;

        // Itera sobre os vértices e escreve suas informações no arquivo
        for (int i = 0; i < quantidadeVertices; i++)
        {
            Vertice vertice = vertices[i];
            arquivo << vertice.getId() << " " << vertice.getCoordenadaX() << " " << vertice.getCoordenadaY() << " " << vertice.getNome() << endl;
        }

        // Escreve no arquivo a quantidade de arestas
        arquivo << quantidadeArestas << endl;

        // Itera sobre a matriz de adjacência e escreve as arestas no arquivo
        for (int i = 0; i < quantidadeVertices; i++)
        {
            for (int j = 0; j < quantidadeVertices; j++)
            {
                // Verifica se há uma aresta entre os vértices i e j
                if (matriz[i][j] != -1)
                {
                    arquivo << i << " " << j << " " << matriz[i][j] << endl;
                }
            }
        }

        // Fecha o arquivo após a escrita
        arquivo.close();
    }
    else
    {
        // Exibe uma mensagem se não foi possível criar o arquivo
        cout << "\n Não foi possível criar o arquivo!" << endl;
    }
}


   void criarVertices() 
{
    // Variáveis para armazenar as coordenadas dos vértices
    int x, y;

    // Itera sobre a quantidade de vértices desejados
    for (int i = 0; i < quantidadeVertices; i++)
    {
        // Solicita a entrada do usuário para as coordenadas X e Y do vértice
        cout << "\n Digite o eixo X do vértice: ";
        cin >> x;
        cout << "\n Digite o eixo Y do vértice: ";
        cin >> y;

        // Cria um objeto da classe Vertice e o armazena no vetor de vértices
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
