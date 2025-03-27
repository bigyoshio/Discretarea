#include "sorts.h"
#include <algorithm>
#include <vector>

using namespace std;


void ordenamientoBurbuja(vector<int>& datos) {
    int n = datos.size();
    for (int i = 0; i < n-1; i++) {
        bool intercambiado = false;
        for (int j = 0; j < n-i-1; j++) {
            if (datos[j] > datos[j+1]) {
                swap(datos[j], datos[j+1]);
                intercambiado = true;
            }
        }
        if (!intercambiado) break; // Optimización para arreglos ya ordenados
    }
}

void ordenamientoSeleccion(vector<int>& datos) {
    int n = datos.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (datos[j] < datos[min_idx]) {
                min_idx = j;
            }
        }
        swap(datos[i], datos[min_idx]);
    }
}

void ordenamientoInsercion(vector<int>& datos) {
    int n = datos.size();
    for (int i = 1; i < n; i++) {
        int clave = datos[i];
        int j = i - 1;

        while (j >= 0 && datos[j] > clave) {
            datos[j+1] = datos[j];
            j--;
        }
        datos[j+1] = clave;
    }
}

// ==============================================
// Implementación de algoritmos avanzados
// ==============================================

namespace {
    // Función auxiliar para Merge Sort
    void merge(vector<int>& datos, int inicio, int centro, int fin) {
        int n1 = centro - inicio + 1;
        int n2 = fin - centro;

        vector<int> izquierda(n1), derecha(n2);

        for (int i = 0; i < n1; i++)
            izquierda[i] = datos[inicio + i];
        for (int j = 0; j < n2; j++)
            derecha[j] = datos[centro + 1 + j];

        int i = 0, j = 0, k = inicio;

        while (i < n1 && j < n2) {
            if (izquierda[i] <= derecha[j]) {
                datos[k] = izquierda[i];
                i++;
            } else {
                datos[k] = derecha[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            datos[k] = izquierda[i];
            i++;
            k++;
        }

        while (j < n2) {
            datos[k] = derecha[j];
            j++;
            k++;
        }
    }

    void mergeSortHelper(vector<int>& datos, int inicio, int fin) {
        if (inicio >= fin) return;
        int centro = inicio + (fin - inicio) / 2;
        mergeSortHelper(datos, inicio, centro);
        mergeSortHelper(datos, centro + 1, fin);
        merge(datos, inicio, centro, fin);
    }
}

void ordenamientoMezcla(vector<int>& datos) {
    mergeSortHelper(datos, 0, datos.size() - 1);
}

namespace {
    // Función auxiliar para Quick Sort
    int particion(vector<int>& datos, int bajo, int alto) {
        int pivote = datos[alto];
        int i = bajo - 1;

        for (int j = bajo; j < alto; j++) {
            if (datos[j] < pivote) {
                i++;
                swap(datos[i], datos[j]);
            }
        }
        swap(datos[i + 1], datos[alto]);
        return i + 1;
    }

    void quickSortHelper(vector<int>& datos, int bajo, int alto) {
        if (bajo < alto) {
            int pi = particion(datos, bajo, alto);
            quickSortHelper(datos, bajo, pi - 1);
            quickSortHelper(datos, pi + 1, alto);
        }
    }
}

void ordenamientoRapido(vector<int>& datos) {
    quickSortHelper(datos, 0, datos.size() - 1);
}

namespace {
    // Función auxiliar para Heap Sort
    void heapify(vector<int>& datos, int n, int i) {
        int mayor = i;
        int izquierda = 2 * i + 1;
        int derecha = 2 * i + 2;

        if (izquierda < n && datos[izquierda] > datos[mayor])
            mayor = izquierda;

        if (derecha < n && datos[derecha] > datos[mayor])
            mayor = derecha;

        if (mayor != i) {
            swap(datos[i], datos[mayor]);
            heapify(datos, n, mayor);
        }
    }
}

void ordenamientoMonticulo(vector<int>& datos) {
    int n = datos.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(datos, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(datos[0], datos[i]);
        heapify(datos, i, 0);
    }
}

void ordenamientoShell(vector<int>& datos) {
    int n = datos.size();

    for (int brecha = n/2; brecha > 0; brecha /= 2) {
        for (int i = brecha; i < n; i++) {
            int temp = datos[i];
            int j;
            for (j = i; j >= brecha && datos[j - brecha] > temp; j -= brecha) {
                datos[j] = datos[j - brecha];
            }
            datos[j] = temp;
        }
    }
}
