#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED

 #include <vector>

 /**
  * @brief Ordenamiento Burbuja (Bubble Sort)
  * @param datos Vector a ordenar (se modifica por referencia)
  * @note Complejidad temporal: O(n�) en caso promedio y peor caso
  * @note Estabilidad: Estable (mantiene orden relativo de elementos iguales)
  */
 void ordenamientoBurbuja(std::vector<int>& datos);

 /**
  * @brief Ordenamiento por Selecci�n (Selection Sort)
  * @param datos Vector a ordenar
  * @note Complejidad: Siempre O(n�) comparaciones
  * @note Caracter�sticas:
  * - In-place (no requiere memoria adicional)
  * - No estable
  */
 void ordenamientoSeleccion(std::vector<int>& datos);

 /**
  * @brief Ordenamiento por Inserci�n (Insertion Sort)
  * @param datos Vector a ordenar
  * @note Complejidad:
  * - Mejor caso (ya ordenado): O(n)
  * - Caso promedio/peor caso: O(n�)
  * @note Eficiente para conjuntos peque�os o parcialmente ordenados
  */
 void ordenamientoInsercion(std::vector<int>& datos);

 /**
  * @brief Ordenamiento por Mezcla (Merge Sort)
  * @param datos Vector a ordenar
  * @note Complejidad: O(n log n) en todos los casos
  * @note Requisitos:
  * - Memoria adicional: O(n)
  * - Estable
  */
 void ordenamientoMezcla(std::vector<int>& datos);

 /**
  * @brief Ordenamiento R�pido (Quick Sort)
  * @param datos Vector a ordenar
  * @note Complejidad:
  * - Caso promedio: O(n log n)
  * - Peor caso (pivote mal elegido): O(n�)
  * @note Versi�n implementada: Partici�n de Lomuto con pivote en �ltimo elemento
  */
 void ordenamientoRapido(std::vector<int>& datos);

 /**
  * @brief Ordenamiento por Mont�culos (Heap Sort)
  * @param datos Vector a ordenar
  * @note Complejidad: O(n log n) en todos los casos
  * @note Caracter�sticas:
  * - In-place
  * - No estable
  */
 void ordenamientoMonticulo(std::vector<int>& datos);

 /**
  * @brief Ordenamiento Shell (Shell Sort)
  * @param datos Vector a ordenar
  * @note Complejidad: Depende de la secuencia de brechas (n/2, n/4, ...)
  * @note Ventajas:
  * - Mejor rendimiento que Insertion Sort en casos promedio
  * - In-place
  */
 void ordenamientoShell(std::vector<int>& datos);

#endif // SORTS_H_INCLUDED
