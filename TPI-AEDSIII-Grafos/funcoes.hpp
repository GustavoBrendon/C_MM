#ifndef GRAFO_HPP
#define GRAFO_HPP

class Vertice 
{
    private:
    int id;
    int coordenadaX;
    int coordenadaY;

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
};

#endif
