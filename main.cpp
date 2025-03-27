 #include "Procesos.h"
 #include "Sorts.h"
 #include <iostream>

 using namespace std;

 int main() {
     cout << "=== An\240lisis Comparativo de Algoritmos de Ordenamiento ===\n";

     vector<int> datosMuestra = {10, 7, 8, 9, 1, 5};
     cout << "\nArreglo de prueba (6 elementos): ";
     mostrarArreglo(datosMuestra);

     cout << "\nTiempos para arreglo peque\244o:\n";
     probarAlgoritmoOrdenamiento(ordenamientoBurbuja, "Burbuja", datosMuestra);
     probarAlgoritmoOrdenamiento(ordenamientoSeleccion, "Seleccion", datosMuestra);
     probarAlgoritmoOrdenamiento(ordenamientoInsercion, "Insercion", datosMuestra);
     probarAlgoritmoOrdenamiento(ordenamientoMezcla, "Mezcla", datosMuestra);
     probarAlgoritmoOrdenamiento(ordenamientoRapido, "Rapido", datosMuestra);
     probarAlgoritmoOrdenamiento(ordenamientoMonticulo, "Monticulo", datosMuestra);
     probarAlgoritmoOrdenamiento(ordenamientoShell, "Shell", datosMuestra);

     // Pruebas de rendimiento completas
     cout << "\nIniciando pruebas de rendimiento (1-10000, incremento 10)...\n";
     ejecutarPruebasRendimiento(10, 1000, 10, 10);

     cout << "\nEjecuci\242n completada. Revise datos/resultados.csv\n";
     return 0;
 }
