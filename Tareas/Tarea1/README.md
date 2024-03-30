# README

## Compilación
Para la compilación se utilizó un Makefile. Todos los archivos fuente se encuentran en src.\
Para compilar ejecutar el siguiente comando en una terminal de bash:
```bash
make
```
Esto generara el ejecutable ahorcado. Para desplegar el programa hacer uso de:
```bash
./ahorcado
```
## Documentación 
El link al sitio de la documentación es:
[https://tarea1ie0217.netlify.app/](https://tarea1ie0217.netlify.app/)
## Preguntas teóricas
1. ¿Cual es la principal diferencia entre C y C++?
	La diferencia principal radica en que C++ incorpora el paradigma de la programación orientada a objetos, además de mantener el paradigma procedimental de C. Algunas de las ventajas de la POO incluyen la seguridad del código, la abstracción, el mantenimiento y la reutilización del mismo.

	Otras diferencias se mencionan en la siguiente tabla:
	
    |Aspecto|C|C++|
    |---|---|---|
    |Creador|Dennis Ritchie en 1972|Bjarne Stroustup en 1979|
    |Paradigma de programación|C es un lenguaje procedimental.|Multiparadigma: programación orientada a objetos y procedimental|
    |Palabras clave|32|63|
    |Tipos de datos|Propios del lenguaje|Propios del lenguaje y creados por el usuario.|
    |Biblioteca estándar|<stdio.h>|<iostream>|
    |Variables por referencia (&)|No|Si|
    |Sobrecarga de funciones|No|Si|
    |Input y Output|printf() y scanf()|cin y cout|

    Información extraída de:

    [https://www.mygreatlearning.com/blog/difference-between-c-and-c/](https://www.mygreatlearning.com/blog/difference-between-c-and-c/)

    [https://www.geeksforgeeks.org/introduction-of-programming-paradigms/](https://www.geeksforgeeks.org/introduction-of-programming-paradigms/)

2. Explique el propósito y el uso de los siguientes comandos de Git: git init, git add, git commit, git push, git pull, git clone, git branch, git merge.

* git init: Se utiliza para crear un nuevo repositorio de Git o un nuevo entorno de trabajo. Antes de ejecutar este comando, Git no realiza seguimiento de los archivos.

* git add: Agrega un archivo al área de preparación de Git. Esto significa que el archivo está marcado para ser incluido en el próximo commit.

* git commit: Guarda de forma permanente una versión en el historial de versiones local.

* git push: Envía los cambios de los commits al repositorio remoto.

* git clone: Clona un repositorio remoto utilizando su URL.

* git branch: Muestra un listado de las ramas locales en el repositorio.

* git merge: Une la historia de una rama con la rama actual.

    Información extraída de:

    [https://dzone.com/articles/top-20-git-commands-with-examples](https://dzone.com/articles/top-20-git-commands-with-examples)

3. ¿Que es Git y cuál es su propósito en el desarrollo de software?

	Es un sistema de control de versiones, lo que básicamente significa que funciona para guardar diferentes "instantáneas" o "versiones" de un proyecto mientras se desarrolla. Esto es crucial ya que permite llevar un registro de los cambios realizados y, en caso necesario, identificar cuáles ocasionaron un problema. Además, facilita que varias personas contribuyan a un programa, ya que al clonar el repositorio se obtiene acceso a toda la historia del proyecto desde la instancia local. También, mantiene un registro de quién realizó cada cambio, y una vez que se realiza un commit y se sube al repositorio remoto, es muy poco probable que un cambio realizado sea permanente o que se pierdan versiones. Esto es sumamente útil para llevar un control de las contribuciones de los colaboradores y para poder trabajar simultáneamente en diferentes partes del proyecto en diferentes ramas.

    Información extraída de:

    [https://git-scm.com/book/en/v2/Getting-Started-What-is-Git%3F](https://git-scm.com/book/en/v2/Getting-Started-What-is-Git%3F)

    [https://www.simplilearn.com/tutorials/git-tutorial/what-is-git](https://www.simplilearn.com/tutorials/git-tutorial/what-is-git)

4. ¿Qué es un conflicto de fusion (merge conflict) en Git y cómo se resuelve?\
    Según la documentación de Git, un conflicto de fusión ocurre cuando hay commits que compiten al intentar fusionar dos ramas. Git puede resolver las diferencias entre archivos o directorios cuando ocurren en líneas de código diferentes, pero a veces surgen cambios que deben gestionarse manualmente, especialmente cuando dos personas modifican la misma parte del código. Para realizar la fusión, es necesario resolver todos los conflictos. Para ello, se debe acceder a la línea de comandos. Una vez que ocurre el error, se puede utilizar git status para visualizar los archivos con conflictos. Normalmente, Git señala los cambios de esta manera

    ```cpp
    <<<<< HEAD
    //Contenido de la rama a la que se quiere fusionar
    =========
    //Contenido en la rama a fusionar
    >>>>>> Nombre_rama
    ```

    Lo presentado debajo de Head corresponde a la línea en la rama a la que se quiere fusionar y luego del igual es la línea en la rama hija. Para resolver el conflicto se borran `<<<` `>>>` `===` y se decide que cambios se quieren dejar o borrar. Luego se vuelve a hacer `git add` y `git commit.` También pueden existir conflictos por archivos borrados en una rama, pero modificados en otra. Para solucionarlos se debe decir si se quiere mantener o borrar el archivo en la fusión final.

    En caso de borrarlo se debe digitar en la línea de comandos `git rm archivo` y en caso de querer preservarlo `git add archivo` .

    Información extraída de:

    [https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/addressing-merge-conflicts/resolving-a-merge-conflict-using-the-command-line](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/addressing-merge-conflicts/resolving-a-merge-conflict-using-the-command-line)

5. ¿Qué es un archivo .gitignore y para qué se utiliza?

	El archivo .gitignore contiene los nombres de archivos y directorios que no se desea que Git monitoree. Se especifican mediante patrones de nombres para indicar qué archivos ignorar. Esto resulta útil para evitar la subida por error de archivos binarios u otros que no se desean en el repositorio remoto.

6. ¿Qué es una solicitud de extracción (pull request) en GitHub y cómo se utiliza?

	Un 'Pull Request' es, por así decirlo, una solicitud para fusionar los cambios de una rama en otra, dirigida a los demás colaboradores del proyecto. Se utilizan para que otros usuarios revisen los cambios y para mantener los 'merge' bien documentados. Normalmente se emplean cuando se desea que otros revisen algún cambio o solución a un error. Este proceso se puede llevar a cabo en el repositorio remoto presionando el botón de 'Pull Requests'. Una vez se completan todas las opciones requeridas, se presiona 'Create pull request'..

    Información extraída de:

    [https://www.gitkraken.com/learn/git/tutorials/what-is-a-pull-request-in-git](https://www.gitkraken.com/learn/git/tutorials/what-is-a-pull-request-in-git)

7. ¿Cuáles son las diferencias fundamentales entre un lenguaje de programación compilado y uno interpretado? Proporcione ejemplos de situaciones en las que sería mas ´optimo utilizar un lenguaje compilado y otras en las que sería mas adecuado un lenguaje interpretado.

	Un compilador se encarga de traducir el código de un lenguaje de programación al lenguaje ensamblador que la máquina puede ejecutar directamente. Por otro lado, un intérprete traduce el código a un lenguaje intermedio o semi-ejecutable, y luego lo ejecuta línea por línea. En general, los programas compilados tienden a ser más rápidos que los interpretados, ya que el compilador produce código máquina optimizado. Además, los lenguajes interpretados suelen incluir código pre-compilado y otras adiciones para facilitar la ejecución del programa.
	
	Para resumir las diferencias ver la siguiente tabla:

    |Compilado|Interpretado|
    |---|---|
    |Pasos de programación: 1. Analiza el código y muestras solamente errores de syntaxis o de semántica. 2. Convierte el código fuente a lenguage máquina 3. El linker hace a unión de varios archivos de código a un programa ejecutable 4. Se crea el ejecutable|1. No necesita hacer el link con otros archivos o generar código máquina. 2. Ejecuta cada líneas una por una.|
    |El compilador crea un archivo con el código maquina y por tanto utiliza espacio de memoria.|No se guarda el código máquina.|
    |Los errores se desplegan una vez compilados. Compila todo el código de una vez lo cual optimiza el proceso|Los errores se desplegan por línea. Como va línea por línea es un poco más lento|
    |No maneja la memoria de forma automática|Maneja la memoria de forma automática|

    Los lenguajes compilados se utilizan en entornos de producción para tareas que pueden requerir un uso intensivo de recursos computacionales. Por otro lado, las tareas menos demandantes pueden ser realizadas por lenguajes interpretados. Además, los lenguajes interpretados pueden ser útiles en las etapas iniciales del desarrollo, ya que ofrecen más flexibilidad para las pruebas y la experimentación.

    Información extraída de:

    [https://www.ibm.com/docs/en/zos-basic-skills?topic=zos-compiled-versus-interpreted-languages](https://www.ibm.com/docs/en/zos-basic-skills?topic=zos-compiled-versus-interpreted-languages)

    [https://www.geeksforgeeks.org/difference-between-compiler-and-interpreter/](https://www.geeksforgeeks.org/difference-between-compiler-and-interpreter/)

8. Explique qué es un linker en el contexto de un lenguaje de programación compilado. ¿Cuál es su función principal y por qué es esencial en el proceso de compilación?
    
    Un linker es responsable de tomar todos los archivos y módulos de un programa para generar un único archivo ejecutable. Su función principal es permitir el uso de bibliotecas y la separación del código en diferentes archivos. El linker es esencial porque resuelve los símbolos de distintos archivos de entrada, como funciones y nombres de variables. Además, se encarga de reubicar las direcciones de memoria de los símbolos a las finales del programa. También es capaz de generar archivos ejecutables que sean compatibles con diferentes sistemas operativos.
    
    Información extraída de:
    
    [https://www.geeksforgeeks.org/linker/](https://www.geeksforgeeks.org/linker/)
    
9. Describa el flujo de trabajo básico en Git para agregar cambios a un repositorio.
    
    Primero se clona localmente un repositorio remoto, luego asumiendo que se sigue un _feature branch workflow_ se crea una nueva rama desde el main para agregar cualquier cambio específico al repositorio de la siguiente manera:
    
    ```bash
    git checkout -b nuevo_cambio
    ```
    
    Antes de eso se puede mantener actualizado el repositorio local usando `git pull` .
    
    En la rama se realizan los cambios y se hace `git add` , `git commit` y `git push` para agregarlos a la historia del repositorio remoto.
    
    Ya cuando se termina lo que se buscaba en la rama se realiza un pull request para que otros contribuidores revisen y aprueben la adicción. Luego desde la linea de comandos se regresa al `main` , se hace `git pull` para tenerlo actualizado y se realiza el merge.
    
    ![](https://res.cloudinary.com/practicaldev/image/fetch/s--M_fHUEqA--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://thepracticaldev.s3.amazonaws.com/i/128hsgntnsu9bww0y8sz.png)
    
    Información extraída de:
    
    [https://www.atlassian.com/git/tutorials/comparing-workflows/feature-branch-workflow](https://www.atlassian.com/git/tutorials/comparing-workflows/feature-branch-workflow)
    
10. Defina qué significa inicializar y declarar una variable.
    
    Declarar una variable significa crearla y asignarle un tipo. Inicializarle significa darle un valor.
    
11. ¿Qué es la sobrecarga de funciones en C++ y cuáles son sus beneficios?
    
    La sobrecarga de funciones ocurre cuando dos o más funciones tienen el mismo nombre pero diferentes parámetros. Uno de sus beneficios radica en el polimorfismo, especialmente en clases. Tener el mismo nombre para una función que realiza una operación específica, pero que debe comportarse de manera diferente en diferentes clases, mejora la interpretación y la abstracción del programa.
    
12. ¿Qué es un puntero y cómo se utiliza? Explique con un ejemplo de la vida real.
    
    Un puntero es una variable que guarda la dirección en memoria de otra variable. Se puede utilizar como el siguiente caso para modificar el valor de guardado en esa dirección:
    
    ```cpp
    int x = 5;
    cout << x << endl; //Output 5
    int *x = &x;
    *x = 8;
    cout << x << endl; //Output 8
    
    ```
    
13. ¿Qué es un branch (rama) en Git y cómo se utiliza?
    
    Una rama en Git es un puntero a una nueva línea de desarrollo que contiene sus propios cambios y commits. Se crea una rama cuando se necesita hacer modificaciones al código base, ya que proporciona una forma de solicitar al repositorio un nuevo conjunto de cambios con su propia historia. La nueva rama contiene el contenido de la rama padre hasta el momento de su creación. Para ver las ramas en el repositorio, se utiliza el comando `git branch`. Para cambiar de la rama actual a una nueva rama y crearla al mismo tiempo, se utiliza el comando `git checkout -b nueva_rama`.
    
14. ¿Cuál es la principal diferencia entre un bucle do-while y un bucle while?
    
    En un bucle do-while se ejecuta al menos una vez el código dentro del bucle independientemente de la condición. En cambio, en un while se revisa la condición y dependiendo de eso se ejecuta el código o no.
    
15. Explique por que es util y común dividir el código en archivos .hpp, .cpp y main.cpp en C++. Describa el propósito específico de cada tipo de archivo.
    
    Dividir el código en archivos permite mejorar la modularidad y organizar la implementación de manera más eficiente. Los archivos .hpp tienen como propósito contener las declaraciones, lo que permite que las definiciones se encuentren en otros archivos sin que el compilador genere errores. Por otro lado, los archivos .cpp contienen las definiciones propiamente dichas. En el archivo main.cpp se llaman todas las funcionalidades y es donde el programa se ejecuta. Es importante destacar que durante el proceso de compilación, el compilador primero se dirige al archivo main y necesita las declaraciones previas, ya que C++ permite que las funciones, variables y clases se declaren sin definir, asumiendo que las definiciones se encontrarán posteriormente.
    
16. ¿Dónde y cómo se guardan las variables que se crean en C++? Explique la diferencia entre el almacenamiento de variables locales y globales.
    
    Las variables se almacenan en la memoria dependiendo de su tipo, y cada una tiene una dirección asignada dentro de la memoria del programa. Por ejemplo, las variables estáticas y globales se guardan en un segmento de la memoria que les permite existir a lo largo de toda la duración del programa. En cambio, las variables locales se guardan en el stack y solo existen dentro del ámbito (scope) donde están definidas.
    
17. ¿Cuál es la diferencia entre pasar parámetros por valor, por referencia y por puntero?
    
    Pasar un parámetro por valor a una función implica enviar una copia de su valor para ser utilizada dentro de la función. Esto significa que no se puede modificar la variable original desde dentro de la función. Por otro lado, pasar una variable por referencia permite modificar la variable original desde dentro de la función. Y finalmente, pasar un parámetro por puntero implica tener acceso a la dirección de memoria de la variable, lo que permite modificarla o acceder a su valor desde dentro de la función.
    
18. Cuando se usa un puntero para apuntar a un arreglo en C++, ¿a qué valor o dirección apunta inicialmente? Describa cómo sería la forma de acceder a todos los datos de ese arreglo mediante el puntero.
    
    Apunta inicialmente a la dirección del primer valor del arreglo. Para acceder a todos los datos se podría crea un for-loop donde se itere por el arreglo incrementando en 1 el valor del puntero inicial.
    
    ```cpp
    float arr[3] = {1,2,3};
    float *ptr = &arr; // &arr[0]
    
    for(int i = 0; i <3 ; ++i){
    	cout << *(ptr + i) << endl; 
    }
    //Output 1 2 3
    ```
    
19. Explique para qué son empleados los punteros dobles en C++. Proporcione ejemplos de situaciones en las que los punteros dobles son necesarios o beneficiosos.
    
    Los punteros dobles almacenan la dirección de memoria de una variable que es de tipo puntero. Son útiles para modificar el valor de una variable indirectamente o para acceder a matrices de dos dimensiones. Además, se utilizan en estructuras de datos para manipular la dirección de los nodos sin necesidad de copiar los datos.
    
    Información extraída de:
    
    [https://www.geeksforgeeks.org/c-pointer-to-pointer-double-pointer/](https://www.geeksforgeeks.org/c-pointer-to-pointer-double-pointer/)
    
20. ¿Para que se utiliza la directiva #ifndef? \
Para evitar que se presenten conflictos de inclusiones múltiples cuando se tiene que utilizar un header file en varios archivos del programa. Si se encuentra la declaración de una función o variable dos veces el compilador va a entrar en conflicto, por ello se comprueba primero si algo está definido. #ifndef seguido de #define significa si no esta definido defínalo de lo contrario no.
    
21. ¿Qué es el puntero this en C++? \
Es un puntero incluido en las clases para poder acceder a los miembros de un objeto en específico desde dentro de la clase. Por ejemplo, si se crea un objeto con ciertos atributos para una clase, la clase debe ser capaz de acceder a los atributos de esa instancia. Para lograr esto, se utiliza la desreferencia del puntero this.
    
    Información extraída de:
    
    [https://learn.microsoft.com/en-us/cpp/cpp/this-pointer?view=msvc-170](https://learn.microsoft.com/en-us/cpp/cpp/this-pointer?view=msvc-170)
    
22. ¿Cuál es la diferencia entre un arreglo y una lista en C++?
    
    Un arreglo es un pedazo continuo de memoria con un tamaño y tipo de dato definido que no se puede modificar. Una lista es como una serie de pedacitos individuales de memoria ligados por punteros.
    
    Información extraída de:
    
    [https://cplusplus.com/forum/beginner/139277/#google_vignette](https://cplusplus.com/forum/beginner/139277/#google_vignette)
    
23. ¿Investigue qué es un memory leak?
    
    Es cuando se ocupa una porción de memoria del _heap_ y no se libera una vez se termina el programa. Esto puede provocar un aumento en el uso de memoria del programa con el tiempo, lo que puede llevar a problemas de rendimiento o a que el programa consuma más recursos de los necesarios.
    
    Información extraída de:
    
    [https://www.geeksforgeeks.org/memory-leak-in-c-and-how-to-avoid-it/](https://www.geeksforgeeks.org/memory-leak-in-c-and-how-to-avoid-it/)