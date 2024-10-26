#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

template<class T>
class Grafo {
    private:
        std::vector<T> vertices;
        int** aristas;
    public:
        Grafo();
        void setVertices(std::vector<T> vertices);
        void setAristas (int** aristas);
        std::vector<T> getVertices();
        int** getAristas();
        int cantVertices();
        int cantAristas();
        int buscarVertice(T ver);
        bool insertarVertice(T ver);
        bool insertarArista(T ori, T des, int cos);
        int buscarArista(T origen, T destino);
        bool eliminarVertice(T ver);
        bool eliminarArista (T origen, T destino);
        std::vector<T> vecinosVertice(T ver);
        void plano();
        std::vector<T> DFS(T ver_inicial);
        std::vector<T> BFS(T ver_inicial);    
};

#include "Grafo.hxx"
#endif
