# README Tarea #3

## Compilacion 
Para la compilación se utilizó un Makefile. Todos los archivos fuente se encuentran en src.\

Para compilar ejecutar el siguiente comando en una terminal de bash:
```bash
make
```
Esto generara el ejecutable agenda. Para desplegar el programa hacer uso de:
```bash
./agenda.exe
```


## Parte Teórica


1. **¿Qué es un algoritmo y cuáles son sus características principales?**

    Un algoritmo es un conjunto de pasos definidos que toman una entrada y producen una salida con el objetivo de resolver un problema específico. Sus características principales incluyen:

    - Definición clara de la entrada y la salida.
    - Pasos bien establecidos y no ambiguos.
    - Eficiencia superior en comparación con otras formas de resolver el mismo problema.
    - Independencia de la implementación en código.

2. **Explica la diferencia entre un algoritmo eficiente y uno ineficiente.**

    La eficiencia hace referencia a la demanda que requiere cierto algoritmo en términos de tiempo y recursos. Un algoritmo eficiente logra mantener un bajo nivel de uso de memoria y ejecutar rápidamente con entradas de diversos tamaños. Básicamente, el tiempo de ejecución no aumenta de manera desproporcionada a medida que crece la entrada. En cambio, un algoritmo ineficiente tiene un tiempo de ejecución aproximadamente exponencial, cuadrático o similar cuando la entrada aumenta. Además, un algoritmo eficiente tiene un diseño que permite un uso adecuado de la memoria y los recursos. En contraste, un algoritmo ineficiente enfrenta problemas evitables, como la computación redundante (realización de cálculos innecesarios múltiples veces) o la falta de terminación oportuna una vez que se logra el objetivo.

    Fuente: [https://medium.com/tech-tajawal/efficiency-of-algorithms-103251b405b5](https://medium.com/tech-tajawal/efficiency-of-algorithms-103251b405b5)



3. **¿Qué es una estructura de datos y por qué son importantes?**

    Son formatos para organizar, almacenar y procesar los datos que se diseñan con un objetivo de uso específico. Son importantes porque facilitan al usuario el acceso a los datos para su uso de la forma más conveniente, tanto para las personas como para las máquinas.

    Las estructuras de datos reúnen sus elementos de forma lógica que permite su uso efectivo y sirven como una representación a nivel computacional de cómo se deben organizar los datos. Además de almacenar datos, son fundamentales en tareas como el manejo de recursos y servicios por parte de los sistemas operativos, el ordenamiento de los datos mediante algoritmos y la búsqueda de índices específicos.
    
    Fuente: [https://www.techtarget.com/searchdatamanagement/definition/data-structure#:~:text=Data%20structures%20make%20it%20easy,humans%20can%20better%20understand%20it](https://www.techtarget.com/searchdatamanagement/definition/data-structure#:~:text=Data%20structures%20make%20it%20easy,humans%20can%20better%20understand%20it)

4. **Describe las diferencias entre una estructura de datos estática y una dinámica.**

    Una estructura estática tiene un tamaño fijo y su memoria se asigna durante la compilación. En cambio, una estructura dinámica tiene un tamaño variable que puede cambiar durante la ejecución del programa, y su memoria se asigna y libera dinámicamente según sea necesario.

    Fuente: [https://www.techtarget.com/searchdatamanagement/definition/data-structure#:~:text=Data%20structures%20make%20it%20easy,humans%20can%20better%20understand%20it](https://www.techtarget.com/searchdatamanagement/definition/data-structure#:~:text=Data%20structures%20make%20it%20easy,humans%20can%20better%20understand%20it)

5. **¿Qué es la memoria dinámica y cómo se gestiona en lenguajes de programación como C++?**

    La memoria dinámica es una forma de asignar memoria durante la ejecución de un programa. Esto flexibiliza el uso de memoria, ya que no es necesario saber cuánta memoria se necesita antes de ejecutar un programa y también evita el uso innecesario de recursos. Dentro de la memoria designada para un programa existen 5 espacios a los que tiene acceso el programador:

    - El segmento de texto donde se almacenan las instrucciones del código.
    - Las constantes.
    - Las variables globales y estáticas.
    - El stack, donde se maneja la memoria estática que debe ser definida antes de la compilación.
    - El heap, donde se posiciona la memoria asignada dinámicamente.

    En este aspecto, es importante señalar que en el heap es el usuario quien debe encargarse de administrar la inserción y el borrado de la memoria, ya que el compilador no lo hace automáticamente como en el stack, donde se maneja por el alcance de las variables. En C++, se utilizan las siguientes funciones para asignar y liberar memoria dinámica:

    - `malloc`: Asigna un bloque de memoria sin inicializar en el heap. Devuelve un puntero `void` que debe ser convertido al tipo deseado.
    - `calloc`: Asigna un bloque de memoria inicializado en 0. Devuelve un puntero `void` que debe ser convertido al tipo deseado.
    - `realloc`: Se utiliza para reasignar el tamaño de un bloque de memoria previamente asignado con alguna de las funciones anteriores. Devuelve un puntero al nuevo bloque de memoria en el heap.
    - `free`: Se utiliza para liberar la memoria asignada dinámicamente.

    **Nota**: `new` es otra forma de asignar memoria en el heap que es específica de C++. Es similar a `malloc`, pero cuando se crea un objeto utilizando `new`, se llama al constructor de la clase y debe ser liberado utilizando `delete`.

    Fuente: [https://www.geeksforgeeks.org/what-is-dynamic-memory-allocation/](https://www.geeksforgeeks.org/what-is-dynamic-memory-allocation/)




6. **¿Cuáles son las ventajas y desventajas de la memoria dinámica en comparación con la memoria estática?**

    Algunas de las ventajas son:

    - En contraste con la memoria estática, permite asignar memoria durante la compilación, lo que ofrece mayor flexibilidad, ya que la memoria puede cambiar en diferentes ejecuciones.
    - Gracias al punto anterior, también puede mejorar el uso eficiente de los recursos, ya que la memoria puede utilizarse según la necesidad momentánea del programa y luego liberarse según conveniencia. En la memoria estática, todos los recursos utilizados deben ser predefinidos en la compilación.
    - También permite crear las mencionadas estructuras de datos dinámicas que pueden crecer durante la ejecución. Esto es imposible utilizando solo el stack.

    No obstante, sus desventajas están relacionadas con el cambio de responsabilidad sobre la memoria del compilador al programador. Algunas de estas desventajas son:

    - Fugas de memoria debido a la falta de liberación correcta de la memoria durante la ejecución, lo que puede llevar a un uso excesivo de la misma por parte del programa.
    - Un uso inadecuado puede provocar fragmentación de la memoria, lo que puede hacer imposible ubicar bloques continuos.
    - Finalmente, al asignar tanta responsabilidad al usuario, incrementa la complejidad y dificultad para mantener el código. Con la memoria estática, este aspecto no es una preocupación, ya que el manejo de la memoria no recae en el programador.

    Fuente: [Quora - What are some advantages and disadvantages of using dynamically allocated memory in C++?](https://www.quora.com/What-are-some-advantages-and-disadvantages-of-using-dynamically-allocated-memory-in-C#:~:text=Advantages%20of%20dynamically%20allocated%20memory,potential%20for%20memory%20leaks)


7. **Explique qué es un árbol binario y cuáles son sus principales características.**

    Es una estructura de tipo árbol donde cada nodo puede tener como máximo dos nodos hijos. Cada nodo contiene datos, una referencia al nodo izquierdo y una referencia al nodo derecho. Existen diferentes tipos de árboles binarios, por ejemplo:

    - Árbol binario lleno: Cada nodo interno tiene exactamente dos nodos hijos.
    - Árbol binario perfecto: Cada nodo interno tiene exactamente dos nodos hijos y todas las hojas están en el mismo nivel.
    - Árbol binario completo: Similar al árbol binario lleno, pero con la condición de que cada nivel debe estar completamente lleno, todos sus nodos deben ir a la izquierda, y no todos los nodos internos necesariamente tienen dos hijos.


8. **¿Qué es una cola (queue) y en qué situaciones se utiliza comúnmente?**

    Es una estructura de datos lineal que funciona bajo la premisa de que el primer elemento en entrar debe ser el primero en salir. Se utiliza en aplicaciones como el manejo de tareas en sistemas operativos, la transferencia de datos, la priorización de colas para eventos, la simulación de estructuras similares a la realidad como una fila de personas y en servidores web para manejar las solicitudes de los clientes (donde se agregan a la cola mientras se reciben y las más antiguas se procesan primero).

    Fuente: [GeeksforGeeks - Applications of Queue Data Structure](https://www.geeksforgeeks.org/applications-of-queue-data-structure/)


9. **¿Cuál es la diferencia entre una cola (queue) y una pila (stack)?**

    El orden en que se pueden remover los datos.Una pila sigue el principio LIFO (último en entrar, primero en salir), mientras que una cola sigue el principio FIFO (primer en entrar, primero en salir).

10. **Describe cómo funciona el algoritmo de inserción (insert) en una tabla hash.**

    Para insertar un nuevo elemento, primero se pasa la clave por el algoritmo de hash que produce el índice que indica en qué lista se va a colocar el elemento y este se inserta al inicio de la lista. Para buscarlo luego, se pasa de nuevo la clave por el algoritmo de hash y se busca en la lista.

    Fuente: [University of Michigan - Hashing](https://www.eecs.umich.edu/courses/eecs380/ALG/niemann/s_has.htm#:~:text=To%20insert%20a%20new%20item,starting%20at%20HashTable%5B3%5D)
    s.

11. **¿Qué es la función de dispersión (hash function) y por qué es importante en las tablas hash?**

    Es la función que se encarga de mapear una clave a un índice específico. Su objetivo ideal es evitar colisiones mapeando cada índice a una clave particular. Por ejemplo, en un arreglo con N pares de clave-elemento se necesita una función que pueda convertir cada clave en el índice del arreglo (de 0 a N-1). El propósito de las tablas hash es utilizar estas funciones de dispersión para mejorar la eficiencia de la indexación de datos, ya que es una forma de calcular el índice exacto de un dato sin tener que atravesar todo el arreglo. Si se implementa correctamente, evita las colisiones de índices (cuando dos claves distintas tienen el mismo valor hash) distribuyendo los valores de forma uniforme para reducir la probabilidad de que esto ocurra.

    Fuente: [Princeton University - Hashing](https://algs4.cs.princeton.edu/34hash/)


12. **¿Cuál es la complejidad temporal promedio de búsqueda en una tabla hash bien implementada?**

    La complejidad temporal promedio de búsqueda en una tabla hash bien implementada es O(1), lo que significa un tiempo constante independiente del tamaño de la entrada.

    Fuente: [https://www.linkedin.com/advice/0/why-choose-hash-table-your-algorithm-skills-algorithms-kemoc?lang=es&originalSubdomain=es](https://www.linkedin.com/advice/0/why-choose-hash-table-your-algorithm-skills-algorithms-kemoc?lang=es&originalSubdomain=es)

13. **Explique cómo se realiza la operación de inserción (push) en una pila (stack).**

    Primero se comprueba si el stack está lleno; si este es el caso, no se realiza la inserción. De lo contrario, se incrementa el índice mayor en uno y se agrega el elemento

14. **¿Cuál es la complejidad temporal de las operaciones de apilar (push) y

 desapilar (pop) en una pila?**

Ambas operaciones (`push` y `pop`) en una pila tienen una complejidad temporal de O(1), ya que solo involucran operaciones en la parte superior de la estructura.

15. **Describe cómo funciona una lista enlazada y cuáles son sus ventajas y desventajas.**

    Una lista enlazada es una estructura que consiste en nodos que apuntan hacia otros nodos. El último nodo apunta a NULL para indicar la terminación de la lista. La memoria para cada nodo debe ubicarse dinámicamente en el heap y su principal diferencia con otros tipos de estructuras es que la memoria de cada elemento no se encuentra ubicada de forma consecutiva.

    ![Lista Enlazada](https://media.geeksforgeeks.org/wp-content/uploads/20220901153812/LLdrawio.png)

    Fuentes:
    - [GeeksforGeeks - Advantages and Disadvantages of Linked List](https://www.geeksforgeeks.org/advantages-and-disadvantages-of-linked-list/)
    - [Simplilearn - Linked List in Data Structure](https://www.simplilearn.com/tutorials/data-structure-tutorial/linked-list-in-data-structure#:~:text=A%20linked%20list%20is%20the,reference%20to%20the)

    | **Ventajas** 	| **Desventajas** 	|
    |---	|---	|
    | Como se guarda dinámicamente no se debe inicializar su tamaño previo a la compilación 	| No obstante, necesita más memoria que un arreglo sencillo. Debe guardar el dato y el puntero al siguiente nodo. 	|
    | Posee los beneficios ya mencionados en el manejo de recursos de la memoria dinámica, ya que se crece conforme se añaden los nodos necesarios en la ejecución 	| El recorrido es más complejo que para un arreglo ya que sus elementos no se encuentran consecutivos en memoria no se pueden acceder por índice y  se debe ir por toda la lista para llegar a un nodo. 	|
    | La inserción de elementos es muy simple en el sentido que solo se necesita cambiar los punteros de los nodos. 	| Sim embargo, su implementación es más compleja que la de un arreglo. Presentando una dificultad para la legibilidad del código. 	|
    | Se pueden añadir o eliminar elementos en todos los índices. 	| Pero por la asignación dinámica es difícil acceder directamente a un elemento en la lista. 	|


16. **¿Qué es un nodo en una lista enlazada y qué contiene?**

    Un nodo en una lista enlazada contiene datos y un puntero al siguiente nodo (y a veces al nodo anterior en el caso de una lista doblemente enlazada).

17. **¿Cuál es la diferencia entre una lista enlazada simple y una lista enlazada doblemente enlazada?**

    La lista enlazada simple contiene solo un puntero al siguiente nodo y, por lo tanto, solo se puede recorrer en un sentido. En cambio, en la lista doblemente enlazada, cada nodo tiene un puntero al siguiente nodo y otro al nodo anterior, lo que permite recorrer la lista en ambas direcciones.

    Esto se detalla en la siguiente imagen:

    ![Lista Doblemente Enlazada](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/03/DLL1.png)

    Fuente: [GeeksforGeeks - Advantages and Disadvantages of Linked List](https://www.geeksforgeeks.org/advantages-and-disadvantages-of-linked-list/)


18. **¿Cómo se realiza la eliminación (delete) de un nodo en una lista enlazada?**

    En una lista enlazada, existen tres casos para la eliminación de un nodo:

    1. **Eliminar al inicio:** En este caso, la cabeza de la lista ahora apunta a la dirección del segundo nodo. Luego, se elimina el nodo que anteriormente era la cabeza.

    2. **Eliminar al final:** Se comienza desde el nodo cabeza y se avanza de puntero a puntero hasta llegar al nodo que apunta a `NULL`, guardando los punteros del nodo previo. Una vez se alcanza el nodo que apunta a `NULL`, se ajusta el puntero del nodo previo para que apunte a `NULL`, indicando que es ahora el nuevo nodo final. Luego se elimina el nodo final y se libera la memoria.

    3. **Eliminar en el medio:** Se empieza desde la cabeza y se itera hasta llegar al número de nodo deseado. Se utilizan dos punteros para llevar la dirección del puntero anterior y del actual. Cuando se alcanza el índice deseado, se apunta el puntero del nodo anterior al siguiente nodo del actual a eliminar, y luego se elimina este último.

    A continuación, se muestra un ejemplo de implementación de la función `delete` en una lista enlazada simple:

    ```C++
    void Borrar(Node** head, int index) {
    Node* temp;
    Node* prev;
    temp = *head;//Ambos inician apuntando a head
    prev = *head;//Necesito el **ptr xq debo cambiar la direcion de head
    for (int i = 0; i < index; i++) {
		    //Si el nodo esta al inicio
        if (i == 0 && index == 1) {
            *head = (*head)->next; // Cambio la direccion de head
            free(temp);
        }
        //Si el nodo esta en el medio
        else {
            if (i == position - 1 && temp) {
            // El previo ahora apunta al que apuntaba el que se elimino
                prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;
 
  
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
    }
    ```
    Fuente: [https://www.geeksforgeeks.org/deletion-in-linked-list/](https://www.geeksforgeeks.org/deletion-in-linked-list/)


19. **Explica cómo funciona el algoritmo de recorrido (traversal) en un árbol binario.**

    Es un proceso para visitar todos los nodos del árbol. Debido a que es una estructura no lineal, existen diversas formas de realizar esto. En el caso de un árbol binario, donde cada nodo tiene como máximo dos nodos hijos, existen tres maneras de llevar a cabo este proceso:

    - **Recorrido de pre-orden:** Comienza visitando el nodo raíz, luego todos los nodos del subárbol izquierdo y finalmente los nodos del subárbol derecho.
    
    - **Recorrido en orden:** Primero se visita todo el subárbol izquierdo, luego la raíz y finalmente el subárbol derecho.

    - **Recorrido post-orden:** Primero se visita el subárbol izquierdo, luego el subárbol derecho y finalmente la raíz.

    Fuente: [GeeksforGeeks - Tree Traversals (Inorder, Preorder, and Postorder)](https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/)


20. **¿Cuál es la complejidad temporal del recorrido en preorden, inorden y postorden en un árbol binario balanceado?**

    Todas estas formas de recorrido de árboles binarios tienen una complejidad temporal de O(n), donde n representa la cantidad de nodos en el árbol. Esto se debe a que en cada uno de estos recorridos se debe visitar cada nodo exactamente una vez, independientemente de la cantidad total de nodos en el árbol.

    Fuente: [Baeldung - Tree Traversal Time Complexity](https://www.baeldung.com/cs/tree-traversal-time-complexity)


21. **Explique la diferencia entre la notación Big O (O) y la notación Omega (Ω) en el análisis de la complejidad temporal de los algoritmos. Proporciona un ejemplo.**

    La notación Big O hace referencia a la cota superior de un algoritmo, es decir, el peor caso en términos de tiempo. En contraposición, omega hace referencia a la cota inferior o al mejor caso.

    Tomemos como ejemplo un algoritmo de búsqueda simple que itera sobre un arreglo:

    1. Comparar el elemento en la posición i con el elemento buscado.
    2. Si no es el elemento buscado, incrementar i en 1.
    3. Continuar hasta encontrar el elemento buscado o llegar al final del arreglo.

    En el peor caso (Big O), el algoritmo podría tener que buscar hasta el final de la lista sin encontrar el elemento deseado, lo que llevaría a realizar n comparaciones, donde n es la longitud del arreglo. Por lo tanto, la complejidad en el peor caso sería O(n).

    En el mejor caso (omega), el elemento buscado se encuentra en la primera comparación, lo que significa que la búsqueda solo requeriría una comparación. Por lo tanto, la notación omega para el mejor caso sería Ω(1).



