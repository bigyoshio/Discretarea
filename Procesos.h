#ifndef PROCESOS_H_INCLUDED
#define PROCESOS_H_INCLUDED

#include <vector>
#include <string>

 /**
  * @brief Genera un arreglo de n�meros aleatorios
  * @param tamano Cantidad de elementos a generar
  * @return Vector con valores uniformemente distribuidos entre 1 y 10000
  * @note Usa semilla aleatoria basada en hardware (random_device)
  */
 std::vector<int> generarArregloAleatorio(int tamano);

 /**
  * @brief Muestra el contenido de un arreglo en consola
  * @param datos Vector a mostrar
  * @note Formato de salida: "1 2 3 4 5" (sin corchetes ni coma final)
  * @warning Uso recomendado solo para depuraci�n con conjuntos peque�os (<20 elementos)
  */
 void mostrarArreglo(const std::vector<int>& datos);

 /**
  * @brief Ejecuta y cronometra un algoritmo de ordenamiento
  * @param algoritmo Funci�n de ordenamiento a evaluar
  * @param nombreAlgoritmo Nombre descriptivo para mostrar en resultados
  * @param datos Copia del vector a ordenar (no modifica el original)
  * @note Realiza:
  * - Medici�n de tiempo con chrono::high_resolution_clock
  * - Verificaci�n autom�tica del resultado ordenado
  */
 void probarAlgoritmoOrdenamiento(
     void (*algoritmo)(std::vector<int>&),
     const std::string& nombreAlgoritmo,
     std::vector<int> datos
 );

 /**
  * @brief Ejecuta pruebas de rendimiento exhaustivas
  * @param tamanoMinimo Tama�o inicial de los arreglos (default: 1)
  * @param tamanoMaximo Tama�o m�ximo a evaluar (default: 10000)
  * @param incremento Paso entre tama�os (default: 10)
  * @param repeticiones N�mero de ejecuciones por tama�o (default: 3)
  * @note Genera:
  * - Archivo CSV con resultados (./datos/resultados.csv)
  * - Barra de progreso en tiempo real
  * - Promedio de tiempos entre repeticiones
  */
 void ejecutarPruebasRendimiento(
     int tamanoMinimo = 10,
     int tamanoMaximo = 10000,
     int incremento = 10,
     int repeticiones = 10
 );


#endif // PROCESOS_H_INCLUDED
