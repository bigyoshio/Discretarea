#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED

 #include <vector>

 /**
  * @brief Ordenamiento Burbuja (Bubble Sort)
  * @param datos Vector a ordenar (se modifica por referencia)
  * @note Complejidad temporal: O(n²) en caso promedio y peor caso
  * @note Estabilidad: Estable (mantiene orden relativo de elementos iguales)
  */
 void ordenamientoBurbuja(std::vector<int>& datos);

 /**
  * @brief Ordenamiento por Selección (Selection Sort)
  * @param datos Vector a ordenar
  * @note Complejidad: Siempre O(n²) comparaciones
  * @note Características:
  * - In-place (no requiere memoria adicional)
  * - No estable
  */
 void ordenamientoSeleccion(std::vector<int>& datos);

 /**
  * @brief Ordenamiento por Inserción (Insertion Sort)
  * @param datos Vector a ordenar
  * @note Complejidad:
  * - Mejor caso (ya ordenado): O(n)
  * - Caso promedio/peor caso: O(n²)
  * @note Eficiente para conjuntos pequeños o parcialmente ordenados
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
  * @brief Ordenamiento Rápido (Quick Sort)
  * @param datos Vector a ordenar
  * @note Complejidad:
  * - Caso promedio: O(n log n)
  * - Peor caso (pivote mal elegido): O(n²)
  * @note Versión implementada: Partición de Lomuto con pivote en último elemento
  */
 void ordenamientoRapido(std::vector<int>& datos);

 /**
  * @brief Ordenamiento por Montículos (Heap Sort)
  * @param datos Vector a ordenar
  * @note Complejidad: O(n log n) en todos los casos
  * @note Características:
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
