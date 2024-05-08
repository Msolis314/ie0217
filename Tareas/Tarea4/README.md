# TAREA 4
## Compilación
Crear un nuevo directorio en la carpeta que se crea el folder llamado bin.
En una terminal de windows ejecutar:
```bash
mingw32-make
```
Ejecutar de la siguiente manera:
```bash
./matrix.exe
```
## Documentación
El link a la documentación es el siguiente:
![https://main--tarea4ie0247.netlify.app/index.html](https://main--tarea4ie0247.netlify.app/index.html)
## Templates

1. Definición de Templates: Explique el concepto de templates en C++ y
proporcione un ejemplo simple
    
    Las templates son una forma en C++ de reutilizar clases y funciones con diferentes tipos y estruturas de datos.El compilador se encarga internamente de resolver el tipo. Esto permite no repetir funcionalidades en el codigo para diferentes tipos de datos.
    
    Por ejemplo, se podría crear una template de función que devuelva la división entre dos números y que funcione para floatantes y enteros. 
    
    ```cpp
    #include <iostream>
    using namespace std;
    
    template <typename T> T divide(T x, Ty) {
    	return x / y;
    }
    
    int main() {
    	//Llamar a la funcion con int
    	divInt = divide<int>(9,3);
    	//Llamer a la funcion con float
    	divFloat = divide<float>(10.5,9.0);
    	return 0;
    }
    ```
    
2. Sobrecarga de Plantillas: ¿Cómo se realiza la sobrecarga de funciones con
plantillas en C++?
    
    Basicamente se escribe la funcion con un dato genérico definido  con la palabra template como se muestra a continuación: 
    
    ```cpp
    template <typename T>
    
    T myfunc( T param 1, T param 2) {
    	std:: cout << param 1 << "and" << param 2;
    	return param 1 + param 2;
    }
    ```
    
    En este caso se denota como con el parametro T permite definir param 1 y param 2 como cualquier tipo de dato, sin embargo si deben concidir en tipo. Si se quiere enviar otro tipo de dato se debe definir otro tipo generico. 
    
3. Plantillas de Clases: Explique cómo se pueden utilizar plantillas en la definición de clases en C++
    
    De forma similar que con la funciones se debe definir un tipo de dato generico usando la palabra class. Por ejemplo, a continuación se muestra como definir una clase anteriormente nombra el parámetro T como genérico. Este puede ser utilizado en el interior de la clase y también para hacer definiciones externas de los métodos de la clase con la sintaxis conocida:
    
    ```cpp
    template <class T>;
    
    class MyClass {
    	private:
    		T atributo;
    	public:
    		T funcionToDefine();
    	
    };
    
    template <class T>
    T MyClass<T>:: functionToDefine() {
    //codigo
    }
    
    ```
    

## Excepciones

4. Manejo de Excepciones: Describa los bloques try, catch y throw y cómo
se utilizan para el manejo de excepciones en C++.
    - **Try**: Le indica al programa que esa porción de código podría generar una excepción durante su ejecución.
    - **throw**: Genera la excepción si se llega a detectar un error, esto permite crear errores personalizados.
    - **catch** : Define un bloque de código que se ejecuta si se detecta un error.Básicamente, es lo que le indica al programa como reaccionar ante la excepción.
    
    En C++ se utilizan estas palabras en conjunto para comprobar si una parte del código genera un potencial error, y si es el caso definir el error y reaccionar de forma que no se caiga el resto de la implementación. Por ejemplo:
    
    ```cpp
    try {
    	 int num = -1;
    	 
    	 // Se define la condición 
    	 // de error
    	 if (num > 0 ) {
    		 cout << "Ok";
    	 } else {
    		 // Levantar la excepcion
    		throw(num);
    	}
    	
    }
    
    // El parametro corresponde a lo indicado por throw
    catch (int expNum) {
    	// Se define como reaccionar
    	cout << "No negatives";
    	cout << expNum;
    }
    ```
    
5. Excepciones Estándar: Nombre al menos tres excepciones estándar proporcionadas por C++ y proporciona ejemplos de situaciones en las que podrían ser
útiles.
    
    En C++ existen varias clases definidas por lenguaje como excepciones estándar. Algunas son:
    
    | Excepción | Sucede | Utilidad |
    | --- | --- | --- |
    | std::invalid_argument | Cuando se pasa un argumento invalido a una función | Permite que el programa no  falle en caso que por error  se le pase a una función un argumento que no corresponde con su definición. |
    | std::range_error | Cuando se intenta almacenar un valor fuera de rango. | Puede ser útil cuando se trabaja con indexación de arreglos o estructuras de datos. En especial cuando se le pide  al usuario el índice donde desea buscar al dato |
    | std::bad_alloc | Esta excepción es levantada por new cuando resulta. Un error en la asignación de memoria. | Puede ser util para prevenir errores cunado se utiliza la memoria dinámica que generen en comportamiento impredecible. |
    
    Fuente: (https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm)[https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm]
    
6. Política de Manejo de Excepciones: ¿Qué es una política de manejo de
excepciones y por qué es importante considerarla al diseñar software?
    
    Una política de manejo de excepciones es una forma de responder a comportamiento impredecible durante la ejecución de un programa. Aunque posiblemente la excepción más común corresponde a las entradas erróneas por parte del usuario pueden suceder otros casos como lo son los errores en el código, problemas de memoria o conflictos de dependencias. 
    
    El manejo de excepciones permite responder de manera que se interrumpe la ejecución del programa de una manera adecuada y controlada.
    
    Fuentes: (https://www.techtarget.com/searchsoftwarequality/definition/error-handling)[https://www.techtarget.com/searchsoftwarequality/definition/error-handling]
    
7. **Noexcept**: Explica el propósito de la palabra clave noexcept y cómo se utiliza
en C++.
    
    Es un operador en tiempo de compilación que funciona para comprobar si una función va a dar una excepción o al menos alguna que se pueda atrapar. Si se atrapa una excepción no se libera el stack. Es útil porque permite optimizar el código ya que el compilador no debe desplegar sus políticas de manejo de excepciones. Se utiliza la siguiente sintaxis: 
    
    ```cpp
    void myFunction() noexcept {
        // Function implementation
    }
    
    ```
    
8. Explique la diferencia entre las excepciones std::logic error y std::runtime error.
    
    El `std::logic` se refiere a un error que ocurre y que podría ser detectada leyendo el código. Esto se refiere a un programa que se ejecuta de manera correcta pero no produce el resultado deseado. En cambio `std::runtime` sucede cuando existe un error que causa que la ejecución fracase por ejemplo asignar un dato tipo char a un float.
    
    Fuente: (https://www.sololearn.com/en/Discuss/546778/what-is-runtime-error-logical-error-and-syntax-error)[https://www.sololearn.com/en/Discuss/546778/what-is-runtime-error-logical-error-and-syntax-error]
    
9.  Explique qué ocurre cuando una excepción no es capturada.
    
    Resulta en la terminación del programa de forma subita. El programa desenrrolla el stack en busca de un bloque de catch para manejar la excepción, sino lo encuentra se termina anormalmente el programa con algún mensaje de error.
    

## STL (Standard Template Library)

10. Contenedores STL: Nombre cinco contenedores diferentes de la STL y
explique brevemente en qu´e situaciones ser´ıa apropiado usar cada uno.
    
    Los contenedores se utilizan para manejar colecciones de objetos de cierto tipo.Pueden ser implementados como arrays, listas enlazadas o pares llave-valor.
    
    | Contenedor | Definición | Uso |
    | --- | --- | --- |
    | Vector | Arreglo dinámico. Puede cambiar de Tamaño conforme se insertan o eliminan  elementos | Cuando se manejan datos ordenados pero no se  conoce el tamaño del  arreglo |
    | Map | Contenedor asociativo que relaciona una llave con un valor. | Cuando se busca acceder a un elemento por medio de una llave en preferencia a un índice. |
    | Set | Contenedor acociativo, donde cada valor debe ser único y se almacena en  orden descendente o ascendente. | Cuando no se quieren valores repetidos en la estructura de datos. |
    | deque | Contenedores de secuencia, que permiten la expansión en ambos extremos. | Son más eficientes que los  vectores en términos de  eliminar al frente o atras elementos.Como no se guarda secuencialmente en memoria también es util si es de interes que el tamaño del bloque en espacio se encoja despues de eliminar un  elemento. |
    | Unordered Set | Es un contenedor asociativo desordenado que se implementa por medio de  una tabla hash para asignar a cada  llave un indice calculado de forma  aleatoria por una función hash. | Cuando se quiere acceder a los elementos por un criterio específico en vez de por  orden. |
    
    Fuentes: (https://www.geeksforgeeks.org/containers-cpp-stl/)[https://www.geeksforgeeks.org/containers-cpp-stl/]
    
    ([https://www.hackerearth.com/practice/notes/c-stls-when-to-use-which-stl/#:~:text=You should also use a,because it uses several blocks](https://www.hackerearth.com/practice/notes/c-stls-when-to-use-which-stl/#:~:text=You%20should%20also%20use%20a,because%20it%20uses%20several%20blocks))[[https://www.hackerearth.com/practice/notes/c-stls-when-to-use-which-stl/#:~:text=You should also use a,because it uses several blocks](https://www.hackerearth.com/practice/notes/c-stls-when-to-use-which-stl/#:~:text=You%20should%20also%20use%20a,because%20it%20uses%20several%20blocks)]
    
11. Iteradores en STL: Explique el concepto de iteradores en la STL y cómo
se utilizan para acceder a elementos en contenedores.
    
    Los iteradores se asemejan a los punteros, pero para los elementos dentro de un contenedor. Básicamente apuntan a cierta posición dentro del [contenedor.](http://contenedor.No) No obstante, a diferencia de los punteros existen diferentes tipos de iteradores con cierta funcionalidad. 
    
    1. Los iteradores de entrada leen valores iterando hacia adelante y solo pueden ser usados en algoritmos que procesan el contenedor secuencialmente. 
    2. Los iteradores de salida escriben valores mientras iteran hacia adelante y igual que los iteradores de entrada solo pueden ser usados en iteraciones secuenciales. 
    3. *forward iterators* pueden leer o escribir mientras iteran unicamente hacia adelante. 
    4. Los iteradores bidireccionales pueden iterar hacia atras y hacia adelante, y conservan las propiedades de sus antecesores. 
    5. Los iteradores de acceso aleatorio pueden acceder a cualquier elemento dentro del contenedor. No dependen del orden secuencial.
    
    Cabe señalar que el iterador comumente depende de la naturaleza del contenedor:
    
    ![https://media.geeksforgeeks.org/wp-content/uploads/C_Iterator_Support.jpg] (https://media.geeksforgeeks.org/wp-content/uploads/C_Iterator_Support.jpg)
    
12. Algoritmos STL: Proporcione ejemplos de al menos tres algoritmos de la
STL y describa sus funciones básicas.
    
    
    | Algoritmo | Función | Sintáxis |
    | --- | --- | --- |
    | Sort | Recibe dos parámetros que delimitan el ambito donde se quiere ordernar y el tercer parámetro es opcional e indica si se quiere organizar los elementos de  forma ascendente o descendente. | std::sort (primerIterador,ultimoIterador); |
    | find if | Recibe dos parámetros que delimitan el ambito de busqueda. Devuelve el índice del primer elemento que coincide con  el valor buscado. | find(primerIterador, ultimoIterador, valorbuscado) |
    | transform | Aplica una operación a los elementos dentro de un rangoy guarda lo resultante en otro rango | transform(primerIteradorentrada, ultimoIteradorentrada, Iterator ultimosalida,unary_operation) |
    
    Fuente: (https://www.geeksforgeeks.org/c-magicians-stl-algorithms/?ref=lbp)[https://www.geeksforgeeks.org/c-magicians-stl-algorithms/?ref=lbp]
    
13. Algoritmos Personalizados: ¿Como podría utilizar un algoritmo personalizado con la STL?
Por ejemplo, como se realizó en el previo se puede utilizar un algoritmo ya predefinido por la librería y se le pasa un parámetro con una función creada personalmente. 
    
    Este es el caso realizado en clase, donde se usa sort con una función propia.
    
    ```cpp
    //using function as comp
        std::sort (myvector.begin() + 4, myvector.end(), myFunction);
    ```
    
    Myfunction es lo siguiente:
    
    ```cpp
    bool myFunction(int i , int j) {return (i < j);}
    ```
    
    En este caso se logra algo similar al funcionamiento de sort, pero esto permite modificar los algoritmos de la stl a conveniencia.