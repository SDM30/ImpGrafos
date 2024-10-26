#include <iostream>
#include "Grafo.h" // Asegúrate de que el archivo esté correctamente referenciado

void mostrarMatrizAdyacencia(Grafo<int>& grafo);

int main() {
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

    grafo.DFS(1);
    grafo.BFS(1);

    // // Mostrar las aristas
    // std::cout << "Aristas desde vértice 1:" << std::endl;
    // for (int i = 0; i < grafo.cantVertices(); ++i) {
    //     int peso = grafo.buscarArista(1, grafo.getVertices()[i]);
    //     if (peso != 0) {
    //         std::cout << "  Vértice 1 a Vértice " << grafo.getVertices()[i] << " con peso " << peso << std::endl;
    //     }
    // }

    // // Eliminar un vértice
    // std::cout << "Eliminando vértice 2..." << std::endl;
    // if (grafo.eliminarVertice(2)) {
    //     std::cout << "Vértice 2 eliminado." << std::endl;
    // } else {
    //     std::cout << "Vértice 2 no encontrado." << std::endl;
    // }

    // // Mostrar los vértices después de la eliminación
    // std::cout << "Vértices después de la eliminación: ";
    // grafo.plano();

    // // Mostrar la matriz de adyacencia después de la eliminación
    // mostrarMatrizAdyacencia(grafo);

    // // Insertar nuevas aristas entre los vértices restantes
    // std::cout << "Insertando nuevas aristas entre los vértices restantes..." << std::endl;
    // grafo.insertarArista(1, 4, 30);
    // grafo.insertarArista(3, 1, 5);

    // // Mostrar la nueva matriz de adyacencia
    // mostrarMatrizAdyacencia(grafo);

    // // Eliminar una arista
    // std::cout << "Eliminando la arista entre 1 y 3..." << std::endl;
    // if (grafo.eliminarArista(1, 3)) {
    //     std::cout << "Arista entre 1 y 3 eliminada." << std::endl;
    // } else {
    //     std::cout << "Arista entre 1 y 3 no encontrada." << std::endl;
    // }

    // // Mostrar las aristas desde el vértice 1 después de la eliminación
    // std::cout << "Aristas desde vértice 1 después de la eliminación:" << std::endl;
    // for (int i = 0; i < grafo.cantVertices(); ++i) {
    //     int peso = grafo.buscarArista(1, grafo.getVertices()[i]);
    //     if (peso != 0) {
    //         std::cout << "  Vértice 1 a Vértice " << grafo.getVertices()[i] << " con peso " << peso << std::endl;
    //     }
    // }

    // // Eliminar todos los vértices uno por uno
    // std::cout << "Eliminando todos los vértices uno por uno..." << std::endl;
    // std::vector<int> verticesAEliminar = grafo.getVertices(); // Copiar los vértices actuales
    // for (const auto& vertice : verticesAEliminar) {
    //     std::cout << "Eliminando vértice " << vertice << "..." << std::endl;
    //     grafo.eliminarVertice(vertice);
    //     mostrarMatrizAdyacencia(grafo);
    // }

    return 0;
}

void mostrarMatrizAdyacencia(Grafo<int>& grafo) {
    std::cout << "Matriz de Adyacencia:" << std::endl;
    int numVer = grafo.cantVertices();
    if (numVer == 0) {
        std::cout << "La matriz está vacía." << std::endl;
        return;
    }
    for (int i = 0; i < numVer; ++i) {
        for (int j = 0; j < numVer; ++j) {
            std::cout << grafo.getAristas()[i][j] << " "; // Asegúrate de que 'aristas' sea accesible.
        }
        std::cout << std::endl;
    }
}
