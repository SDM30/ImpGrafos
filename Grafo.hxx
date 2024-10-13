#include "Grafo.h"

template <class T>
Grafo<T>::Grafo() {
    this->aristas = NULL;
}

template <class T>
void Grafo<T>::setVertices(std::vector<T> vertices) {
    this->vertices = vertices;
}

template <class T>
void Grafo<T>::setAristas (int** aristas) {
    this->aristas = aristas;
}

template <class T>
std::vector<T> Grafo<T>::getVertices() {
    return this->vertices;
}

template <class T>
int** Grafo<T>::getAristas() {
    return this->aristas;
}

template <class T>
int Grafo<T>::cantVertices() {
    return vertices.size();
}

template <class T>
int Grafo<T>::cantAristas() {
    int suma = 0;
    for (int i = 0; i < cantVertices(); i++) {
        for (int j = 0; j < cantVertices(); j++) {
            if (*(*(aristas+i)+j) != 0)  suma++;
        }
    }
    return suma;
}

template <class T>
int Grafo<T>::buscarVertice(T ver) {
    int ind = -1;
    for (int i = 0; i < cantVertices(); i++) {
        if (vertices[i] == ver)  ind = i;
    }
    return ind;
}

template <class T>
bool Grafo<T>::insertarVertice(T ver) {
    bool res = false;
    if (buscarVertice(ver) == -1) {
        vertices.push_back(ver);
        int** nmatriz = new int*[cantVertices()];
        for (int i = 0; i < cantVertices(); i++) {
            *(nmatriz+i) = new int[cantVertices()];
        }
        for (int i = 0; i < cantVertices()-1; i++) {
            for (int j = 0; j < cantVertices()-1; j++) {
                *(*(nmatriz+i)+j) = *(*(aristas+i)+j);
            }
        }

        // Inicializar la nueva fila (para el nuevo vértice)
        for (int j = 0; j < cantVertices(); j++) {
            nmatriz[cantVertices() - 1][j] = 0; // Inicializa todos los elementos de la nueva fila
        }
        // Inicializar la nueva columna (para el nuevo vértice)
        for (int i = 0; i < cantVertices(); i++) {
            nmatriz[i][cantVertices() - 1] = 0; // Inicializa todos los elementos de la nueva columna
        }

        for (int i = 0; i < cantVertices()-1; i++) {
            delete[] *(aristas+i);
        }
        delete[] aristas;
        aristas = nmatriz;
    }
    return res;
}

template <class T>
bool Grafo<T>::insertarArista(T ori, T des, int cos) {
    bool res = false;
    int i_ori = buscarVertice(ori);
    int i_des = buscarVertice(des);
    if ( i_ori != -1 && i_des != -1 ) {
        if (*(*(aristas+i_ori)+i_des) == 0) {
            *(*(aristas+i_ori)+i_des) = cos;
            res = true;
        }
    }
    return res;
}

template <class T>
int Grafo<T>::buscarArista(T origen, T destino) {
		int res = -1;
		int i_ori = buscarVertice(origen);
		int i_des = buscarVertice(destino);
		if ( i_ori != -1 && i_des != -1 ) {
			res = *(*(aristas+i_ori)+i_des);
		}
		return res;
}

template <class T>
bool Grafo<T>::eliminarVertice(T ver) {
    int i_ori = buscarVertice(ver);
    int numVer = cantVertices();

    bool eliminado = false;

    if (i_ori != -1) {
        eliminado = true;

        // Eliminar el vértice del vector de vértices
        vertices.erase(vertices.begin() + i_ori);

        // Eliminar fila de la matriz de adyacencia
        delete [] this->aristas[i_ori];

        // Mover las filas restantes para sobreescribir la fila eliminada
        for (int i = i_ori; i < numVer - 1; ++i) {
            aristas[i] = aristas[i + 1];
        }

        // Eliminar la columna en la matriz de adyacencia
        for (int i = 0; i < numVer - 1; i++) {
            for (int j = i_ori; j < numVer - 1; j++) {
                aristas[i][j] = aristas[i][j + 1];
            }
        }

        // Redimensionar las filas restantes
        for (int i = 0; i < numVer - 1; i++) {
            int *nuevafila = new int[numVer - 1];
            for (int j = 0; j < numVer - 1; j++) {
                nuevafila[j] = aristas[i][j];
            }

            // Liberar mem de fila antigua
            delete[] aristas[i];
            aristas[i] = nuevafila;
        }

        // Actualizar el número de vértices
        numVer--;
    }

    return eliminado;
}


template <class T>
bool Grafo<T>::eliminarArista (T origen, T destino) {
		bool res = false;
		int i_ori = buscarVertice(origen);
		int i_des = buscarVertice(destino);
		if ( i_ori != -1 && i_des != -1 ) {
			*(*(aristas+i_ori)+i_des) = 0;
			res = true;
		}
		return res;
}   