# README Previo #6

La clase de la semana trató de diferentes algoritmos de ordenamiento para arreglos.Se abordarón los siguientes métodos:
- BubleSort
- SelectionSort
- InsertionSort
- QuickSort

| **Algoritmo** 	| **Nombre Archivo** 	| **Complejidad Mejor Caso** 	| **Complejidad Peor Caso** 	| **Complejidad Promedio** 	| **Complejidad en Espacio** 	|
|---	|---	|---	|---	|---	|---	|
| Bubble Sort 	| BubbleSort.cpp 	| O(n) 	| O(n^2) 	| O(n^2) 	| O(1) 	|
| Selection Sort 	| SelectionSort.cpp 	| O(n^2) 	| O(n^2) 	| O(n^2) 	| O(1) 	|
| Insertion Sort 	| InsertionSort.cpp 	| O(n) 	| O(n^2) 	| O(n^2) 	| O(1) 	|
| Quick Sort 	| QuickSort.cpp 	| O(n*log(n)) 	| O(n^2) 	| O(n*log(n)) 	| O(log(n)) 	|

**Nota:** La implementación del quick sort se investigo en : [https://www.programiz.com/dsa/quick-sort](https://www.programiz.com/dsa/quick-sort)


## Compilación

Primero crear un directorio llamado bin en la carpeta `Previo5` una vez se clona el repositorio. Para ello correr el siguiente comando en una terminal de bash:
```bash
mkdir bin
```
Luego ejecutar el _Makefile_ corriendo lo siguiente en la terminal:
```bash
make
```
Por último, correr el script de bash para optener el _output_ de todos los ejecutables en el directorio de bin:
```bash 
./run.sh
```
En caso de presentarse problemas con los permisos para ejecución introducir el siguiente comando:
```bash
chmod +x run.sh
```