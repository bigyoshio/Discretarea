#include "Procesos.h"
#include "sorts.h"
#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

vector<int> generarArregloAleatorio(int tamano) {
    vector<int> datos(tamano);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribucion(1, 10000);

    for (int i = 0; i < tamano; i++) {
        datos[i] = distribucion(gen);
    }
    return datos;
}

void mostrarArreglo(const vector<int>& datos) {
    for (size_t i = 0; i < datos.size(); i++) {
        cout << datos[i];
        if (i != datos.size() - 1) cout << " ";
    }
    cout << endl;
}

void probarAlgoritmoOrdenamiento(void (*algoritmo)(vector<int>&),
                               const string& nombreAlgoritmo,
                               vector<int> datos) {
    auto inicio = high_resolution_clock::now();
    algoritmo(datos);
    auto fin = high_resolution_clock::now();

    duration<double> duracion = fin - inicio;
    cout << nombreAlgoritmo << ": "
         << fixed << setprecision(6)
         << duracion.count() << " segundos\n";

    if (!is_sorted(datos.begin(), datos.end())) {
        cerr << "  [ERROR] El arreglo no está ordenado correctamente\n";
    }
}

void ejecutarPruebasRendimiento(int tamanoMinimo, int tamanoMaximo,
                              int incremento, int repeticiones) {
    // Configuración de algoritmos
    vector<string> nombresAlgoritmos = {
        "Burbuja", "Seleccion", "Insercion",
        "Mezcla", "Rapido", "Monticulo", "Shell"
    };

    vector<void (*)(vector<int>&)> algoritmos = {
        ordenamientoBurbuja, ordenamientoSeleccion, ordenamientoInsercion,
        ordenamientoMezcla, ordenamientoRapido, ordenamientoMonticulo, ordenamientoShell
    };

    // Validación de parámetros
    if (tamanoMinimo < 1 || tamanoMaximo < tamanoMinimo || incremento < 1 || repeticiones < 1) {
        cerr << "Error: Parámetros de prueba inválidos\n";
        return;
    }

    // Generar tamaños a probar
    vector<int> tamanos;
    for (int tamano = tamanoMinimo; tamano <= tamanoMaximo; tamano += incremento) {
        tamanos.push_back(tamano);
    }

    // Matriz de resultados
    vector<vector<double>> resultados(algoritmos.size(), vector<double>(tamanos.size(), 0.0));

    // Configuración de barra de progreso
    const int anchoBarra = 50;
    const int totalPruebas = tamanos.size() * algoritmos.size() * repeticiones;
    int pruebasCompletadas = 0;

    // Ejecución de pruebas
    for (int rep = 0; rep < repeticiones; rep++) {
        cout << "\nRepetici\242n #" << rep + 1 << "/" << repeticiones << "\n";

        for (size_t i = 0; i < tamanos.size(); i++) {
            vector<int> datos = generarArregloAleatorio(tamanos[i]);

            for (size_t algo = 0; algo < algoritmos.size(); algo++) {
                vector<int> copiaDatos = datos;
                auto inicio = high_resolution_clock::now();
                algoritmos[algo](copiaDatos);
                auto fin = high_resolution_clock::now();

                duration<double> duracion = fin - inicio;
                resultados[algo][i] += duracion.count();
                pruebasCompletadas++;

                // Actualizar barra de progreso
                int progreso = anchoBarra * pruebasCompletadas / totalPruebas;
                cout << "\r[";
                for (int p = 0; p < anchoBarra; p++) {
                    cout << (p < progreso ? "=" : (p == progreso ? ">" : " "));
                }
                cout << "] " << int(100.0 * pruebasCompletadas / totalPruebas) << "%";
                cout.flush();

                // Verificar ordenación
                if (!is_sorted(copiaDatos.begin(), copiaDatos.end())) {
                    cerr << "\nError en " << nombresAlgoritmos[algo]
                         << " con tamaño " << tamanos[i] << "\n";
                }
            }
        }
    }

    // Calcular promedios
    for (size_t algo = 0; algo < algoritmos.size(); algo++) {
        for (size_t i = 0; i < tamanos.size(); i++) {
            resultados[algo][i] /= repeticiones;
        }
    }

    // Crear directorio si no existe
    #if defined(_WIN32)
    system("mkdir datos 2> nul");
    #else
    system("mkdir -p datos");
    #endif

    // Guardar resultados en CSV
    ofstream archivo("datos/resultados.csv");
    if (archivo.is_open()) {
        archivo << "Tamaño,Burbuja,Seleccion,Insercion,Mezcla,Rapido,Monticulo,Shell\n";
        for (size_t i = 0; i < tamanos.size(); i++) {
            archivo << tamanos[i];
            for (size_t algo = 0; algo < algoritmos.size(); algo++) {
                archivo << "," << fixed << setprecision(6) << resultados[algo][i];
            }
            archivo << "\n";
        }
        archivo.close();
    }

    cout << "\n\nPruebas completadas. Resultados guardados en datos/resultados.csv\n";
    cout << "Total de pruebas realizadas: " << totalPruebas << "\n";
}
