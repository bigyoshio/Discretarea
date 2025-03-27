# Análisis Comparativo de Algoritmos de Ordenamiento

![Ejemplo de gráfica de resultados](https://github.com/bigyoshio/Discretarea/blob/main/Gráfica.png)

Proyecto que mide el rendimiento de 7 algoritmos clásicos de ordenamiento, generando reportes en CSV y análisis visuales.

## 📋 Características

- Implementa 7 algoritmos:
  - Burbuja (Bubble Sort)
  - Selección (Selection Sort)
  - Inserción (Insertion Sort)
  - Mezcla (Merge Sort)
  - Rápido (Quick Sort)
  - Montículos (Heap Sort)
  - Shell (Shell Sort)

- Genera reportes en CSV con:
  - Tiempos de ejecución
  - Validación de resultados
  - Promedios de múltiples ejecuciones

- Rango configurable de pruebas (desde 10 hasta 10,000 elementos)

## 🛠️ Requisitos

- Compilador C++11 (g++ o clang)
- CMake (opcional)

## 🚀 Compilación y Ejecución

```bash
# Compilar
g++ -std=c++11 main.cpp sorts.cpp Procesos.cpp -o ordenamiento

# Ejecutar (pruebas de 1 a 1000 elementos)
./ordenamiento
