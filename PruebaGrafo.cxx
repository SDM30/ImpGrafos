#include <iostream>
#include "Grafo.h" // Asegúrate de que el archivo esté correctamente referenciado

template <class T>
void mostrarMatrizAdyacencia(Grafo<T>& grafo);
void pruebaNumeros();
void pruebaLetras();
void pruebaDijkstra();

int main() {

    //pruebaNumeros();
    //pruebaLetras();
    pruebaDijkstra();

}

template <class T>
void mostrarMatrizAdyacencia(Grafo<T>& grafo) {
    std::cout << "Matriz de Adyacencia:" << std::endl;
    int numVer = grafo.cantVertices();
    if (numVer == 0) {
        std::cout << "La matriz está vacía." << std::endl;
        return;
    }
    for (int i = 0; i < numVer; ++i) {
        for (int j = 0; j < numVer; ++j) {
            std::cout << grafo.obtenerAristas()[i][j] << " "; // Asegúrate de que 'aristas' sea accesible.
        }
        std::cout << std::endl;
    }
}

void pruebaNumeros() {
    // Crear un grafo de tipo int
    Grafo<int> grafo;

    // Insertar vértices
    std::cout << "Insertando vértices..." << std::endl;
    grafo.insertarVertice(1);
    grafo.insertarVertice(2);
    grafo.insertarVertice(3);
    grafo.insertarVertice(4);

    // Mostrar los vértices
    grafo.plano();

    // Insertar aristas
    std::cout << "Insertando aristas..." << std::endl;
    grafo.insertarArista(1, 2, 10);
    grafo.insertarArista(1, 3, 15);
    grafo.insertarArista(2, 4, 20);
    grafo.insertarArista(3, 4, 25);

    // Mostrar la matriz de adyacencia
    mostrarMatrizAdyacencia(grafo);

    std::vector<int> vecinos = grafo.vecinosVertice(1);
    std::vector<int>::iterator it_v = vecinos.begin();
    for (;it_v != vecinos.end(); it_v++) {
        std::cout<< *it_v << " ";
    }
    std::cout<< std::endl;

    std::cout << "Recorrido en profundidad: ";
    grafo.DFS(1);
    std::cout << "Recorrido en anchura: ";
    grafo.BFS(1);

    // Mostrar las aristas
    std::cout << "Aristas desde vértice 1:" << std::endl;
    for (int i = 0; i < grafo.cantVertices(); ++i) {
        int peso = grafo.buscarArista(1, grafo.obtenerVertices()[i]);
        if (peso != 0) {
            std::cout << "  Vértice 1 a Vértice " << grafo.obtenerVertices()[i] << " con peso " << peso << std::endl;
        }
    }

    // Eliminar un vértice
    std::cout << "Eliminando vértice 2..." << std::endl;
    if (grafo.eliminarVertice(2)) {
        std::cout << "Vértice 2 eliminado." << std::endl;
    } else {
        std::cout << "Vértice 2 no encontrado." << std::endl;
    }
    // Mostrar los vértices después de la eliminación
    std::cout << "Vértices después de la eliminación: ";
    grafo.plano();

    // Mostrar la matriz de adyacencia después de la eliminación
    mostrarMatrizAdyacencia(grafo);


    std::cout << "Recorrido en profundidad: ";
    grafo.DFS(1);
    std::cout << "Recorrido en anchura: ";
    grafo.BFS(1);

    // Insertar nuevas aristas entre los vértices restantes
    std::cout << "Insertando nuevas aristas entre los vértices restantes..." << std::endl;
    grafo.insertarArista(1, 4, 30);
    grafo.insertarArista(3, 1, 5);

    // Mostrar la nueva matriz de adyacencia
    mostrarMatrizAdyacencia(grafo);

    std::cout << "Recorrido en profundidad: ";
    grafo.DFS(1);
    std::cout << "Recorrido en anchura: ";
    grafo.BFS(1);

    // Eliminar una arista
    std::cout << "Eliminando la arista entre 1 y 3..." << std::endl;
    if (grafo.eliminarArista(1, 3)) {
        std::cout << "Arista entre 1 y 3 eliminada." << std::endl;
    } else {
        std::cout << "Arista entre 1 y 3 no encontrada." << std::endl;
    }

    // Mostrar las aristas desde el vértice 1 después de la eliminación
    std::cout << "Aristas desde vértice 1 después de la eliminación:" << std::endl;
    for (int i = 0; i < grafo.cantVertices(); ++i) {
        int peso = grafo.buscarArista(1, grafo.obtenerVertices()[i]);
        if (peso != 0) {
            std::cout << "  Vértice 1 a Vértice " << grafo.obtenerVertices()[i] << " con peso " << peso << std::endl;
        }
    }

    // Eliminar todos los vértices uno por uno
    std::cout << "Eliminando todos los vértices uno por uno..." << std::endl;
    std::vector<int> verticesAEliminar = grafo.obtenerVertices(); // Copiar los vértices actuales
    for (const auto& vertice : verticesAEliminar) {
        std::cout << "Eliminando vértice " << vertice << "..." << std::endl;
        grafo.eliminarVertice(vertice);
        mostrarMatrizAdyacencia(grafo);
    }
}

void pruebaLetras() {
    // Crear un grafo de tipo char
    Grafo<char> grafo;

    // Insertar vértices
    std::cout << "Insertando vértices..." << std::endl;
    grafo.insertarVertice('a');
    grafo.insertarVertice('b');
    grafo.insertarVertice('c');
    grafo.insertarVertice('d');
    grafo.insertarVertice('e');
    grafo.insertarVertice('f');

    // Insertar aristas
    std::cout << "Insertando aristas..." << std::endl;
    grafo.insAristaNoDir('a', 'b', 1);
    grafo.insAristaNoDir('a', 'c', 1);
    grafo.insAristaNoDir('a', 'd', 1);
    grafo.insAristaNoDir('b', 'c', 1);
    grafo.insAristaNoDir('b', 'e', 1);
    grafo.insAristaNoDir('d', 'e', 1);
    grafo.insAristaNoDir('d', 'f', 1);

    std::cout << "Recorrido en profundidad:" << std::endl;
    std::vector<char>::const_iterator it = grafo.obtenerVertices().begin();
    for (;it != grafo.obtenerVertices().end(); it++) {
        printf("Recorrido desde %c: \n",*it);
        grafo.DFS(*it);
    }

    std::cout << std::endl << "Recorrido en anchura:" << std::endl;
    std::vector<char>::const_iterator it_B = grafo.obtenerVertices().begin();
    for (;it_B != grafo.obtenerVertices().end(); it_B++) {
        printf("Recorrido desde %c: \n",*it_B);
        grafo.BFS(*it_B);
    }
    std::cout << "Antes de eliminar Arista" << std::endl;
    mostrarMatrizAdyacencia(grafo);

    std::cout << "Despues de eliminar Arista" << std::endl;
    grafo.elimAristaNoDir('a', 'b');
    grafo.elimAristaNoDir('a', 'c');
    mostrarMatrizAdyacencia(grafo);
}

void pruebaDijkstra() {
    Grafo<char> grafo;

    std::cout << "Insertando vértices..." << std::endl;
    grafo.insertarVertice('s');
    grafo.insertarVertice('t');
    grafo.insertarVertice('x');
    grafo.insertarVertice('y');
    grafo.insertarVertice('z');

    std::cout << "Insertando aristas..." << std::endl;
    grafo.insertarArista('s', 't', 10);
    grafo.insertarArista('s', 'y', 5);

    grafo.insertarArista('t', 'x', 1);
    grafo.insertarArista('t', 'y', 2);

    grafo.insertarArista('y', 'z', 2);
    grafo.insertarArista('y', 't', 3);
    grafo.insertarArista('y', 'x', 9);

    grafo.insertarArista('x', 'z', 4);

    grafo.insertarArista('z', 'x', 6);
    grafo.insertarArista('z', 's', 7);

    std::vector<char*> pred = grafo.Djikstra('s');
    for (int i = 0; i < grafo.obtenerVertices().size(); i++) {
        std::cout << pred[i] << " ";
    }
    std::cout << std::endl;
}
