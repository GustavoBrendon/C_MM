#ifndef GRAFO_HPP
#define GRAFO_HPP
#include <string>

using namespace std;
class Vertice 
{
    private:
    int id;
    int coordenadaX;
    int coordenadaY;
    string nome;

    public:
    Vertice()
    {
        id = 0;
        coordenadaX = 0;
        coordenadaY = 0;
    }

    Vertice(int id, int x, int y)
    {
        this->id = id;
        this->coordenadaX = x;
        this->coordenadaY = y;
    }

     string getNome() 
    {
        return nome;
    }

    void setNome(string nome) 
    {
        this->nome = nome;
    }

    int getCoordenadaX() 
    {
        return coordenadaX;
    }

    void setCoordenadaX(int x) 
    {
        this->coordenadaX = x;
    }

    int getCoordenadaY() 
    {
        return coordenadaY;
    }

    void setCoordenadaY(int y) 
    {
        this->coordenadaY = y;
    }

    int getId() 
    {
        return id;
    }

    void setId(int id) 
    {
        this->id = id;
    }

    void editarNomeVertice(int vertice, char nome);
    void buscaProfundidade(int verticeInicial);
    void buscaLargura(int verticeInicial);
    void arvoreMinimaPrim();
    void menorCaminhoDijkstra(int origem, int destino);
};

#endif
