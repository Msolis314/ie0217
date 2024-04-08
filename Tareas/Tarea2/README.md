# README

## Ejecucion
Para la compilación se utilizó un Makefile. Todos los archivos fuente se encuentran en src.\
Para compilar ejecutar el siguiente comando en una terminal de bash:
```bash
make
```
Esto generara el ejecutable ahorcado. Para desplegar el programa hacer uso de:
```bash
./mundo.exe
```
## Preguntas Teóricas

1. ¿Qué es la programación orientada a objetos y cuáles son sus principales principios?

    La programación orientada a objetos es un paradigma que se basa en la organización del código alrededor de objetos, los cuales tienen atributos y métodos. La implementación de estos objetos está aislada del resto del código, lo que mejora la seguridad y facilita el mantenimiento del software.

    Algunos de sus principales principios son:

    - Encapsulación: Se refiere a aislar o "esconder" ciertos atributos de la clase y hacer públicos solo ciertos métodos para acceder a ellos. Esto mejora la seguridad del código y su modularidad al esconder los aspectos internos del objeto y exponer solo ciertas funcionalidades a través de métodos establecidos.

    - Abstracción: Permite crear "entidades" dentro del código que representan ciertos conceptos de la vida real o del programa. Los objetos pueden interactuar de cierta manera con el resto del programa sin que este necesite conocer los detalles de su implementación, lo que mejora la mantenibilidad y modularidad del código.

    - Herencia: Permite que las clases hereden atributos y métodos de otras clases, lo cual permite reutilizar el código ya que no es necesario redefinir métodos ya establecidos. Además, permite una organización lógica de jerarquía entre las clases que a la larga mejora la abstracción del código.

    - Polimorfismo: Está relacionado con la herencia en el sentido de que parte de la implementación de la clase padre puede ser reescrita dependiendo de las funcionalidades de las clases hijas, lo que permite llamar a un solo método dependiendo del tipo de objeto que se necesite en el momento.

    Fuente: [https://medium.com/@cancerian0684/what-are-four-basic-principles-of-object-oriented-programming-645af8b43727](https://medium.com/@cancerian0684/what-are-four-basic-principles-of-object-oriented-programming-645af8b43727)

2. Explique el concepto de ocultamiento de datos y cómo se logra en C++.

    La encapsulación es una técnica que consiste en ocultar las características y datos internos de una clase al usuario que utilice el programa. Su objetivo principal es proteger los datos contra accesos no deseados o modificaciones que puedan afectar el funcionamiento del programa. Algunos de los beneficios de la encapsulación son: minimizar los riesgos relacionados con los datos, mejorar la robustez del programa, proteger los datos contra accesos no autorizados o corrupción, y facilitar el mantenimiento del código.

    En C++, este concepto se implementa mediante los especificadores de acceso, que determinan qué atributos y métodos pueden ser utilizados dentro y fuera de la clase. En este lenguaje, existen tres especificadores de acceso principales:

    `private:` Los miembros (atributos y métodos) marcados como private solo pueden ser accedidos dentro de la misma clase. Están ocultos fuera de la clase y no son accesibles desde ninguna otra parte del programa.

    `public:` Los miembros marcados como public pueden ser utilizados desde cualquier parte del programa, ya sea dentro de la misma clase, en otras clases o incluso desde funciones externas a la clase.

    `protected:` Los miembros marcados como protected son similares a los private, pero también pueden ser utilizados por clases derivadas (subclases) de la clase actual. Estos miembros no son accesibles desde fuera de la clase ni desde partes del programa que no sean subclases.

    Fuente: [www.mygreatlearning.com/blog/introduction-to-data-hiding-](www.mygreatlearning.com/blog/introduction-to-data-hiding-)
3. ¿Cuál es la diferencia entre una clase y un objeto en C++?

    Una clase en programación es una plantilla o un modelo que define la estructura y el comportamiento de un tipo de objeto. En otras palabras, una clase especifica qué atributos (datos) y métodos (funciones) tendrán todas las instancias u objetos creados a partir de esa clase.

    Por otro lado, un objeto es una instancia concreta de una clase. Cuando se crea un objeto a partir de una clase, se asignan valores específicos a sus atributos, lo que le da identidad y estado propio a ese objeto dentro del programa.
4. ¿Qué es el polimorfismo y cómo se logra en C++?

    El polimorfismo es la capacidad que tienen los objetos de comportarse de manera diferente según el contexto en el que se utilicen. Una analogía común para entender el polimorfismo es compararlo con una persona que puede desempeñar múltiples roles a lo largo de su vida, como ser madre, esposa y trabajadora.

    En C++, el polimorfismo se puede lograr de dos maneras principales: polimorfismo en tiempo de compilación y polimorfismo en tiempo de ejecución.

    Polimorfismo en tiempo de compilación: Este tipo de polimorfismo se logra mediante la sobrecarga de funciones y la sobrecarga de operadores. La sobrecarga de funciones permite tener múltiples funciones con el mismo nombre pero con diferentes tipos de parámetros, de modo que el compilador selecciona la función adecuada según el tipo de argumentos utilizados en la llamada. La sobrecarga de operadores, por su parte, permite especificar el comportamiento de un operador en clases definidas por el usuario, lo que permite operaciones personalizadas con tipos definidos por el usuario.

    Polimorfismo en tiempo de ejecución: Este tipo de polimorfismo se logra a través de la herencia y el uso de funciones virtuales. La sobrescritura de funciones (métodos) en clases derivadas permite que un objeto se comporte de manera diferente según la clase concreta a la que pertenece durante la ejecución del programa. Las funciones virtuales son funciones declaradas en una clase base que pueden ser sobrescritas en las clases derivadas, y la implementación correcta se elige en tiempo de ejecución según el tipo de objeto al que se hace referencia.

    Fuente: [https://www.geeksforgeeks.org/cpp-polymorphism/](https://www.geeksforgeeks.org/cpp-polymorphism/)
5. ¿Qué significa el terminó encapsulamiento en el contexto de la OOP?

    La encapsulación es el proceso mediante el cual se oculta la implementación interna de una clase al usuario objetivo u otros programadores. Se expone únicamente una interfaz para que los externos puedan interactuar con los objetos, lo cual facilita una mejor abstracción y modularidad en el código.
6. ¿Cuál es el propósito del constructor y el destructor en una clase de C++?

    Tanto el constructor como el destructor se utilizan para administrar recursos en memoria y atributos asociados a las clases.
7. ¿Investigue cómo se define una clase abstracta en C++ y cuál es su función?
    Una clase abstracta se define de la siguiente manera:
    ```C++
    class Abstract{
    //Data
    public:
        //Funcion virtual pura
        virtual void get_D() = 0;
    };
    ```
    Para crear una clase abstracta, se requiere definir al menos una función virtual pura, que se denota en C++ mediante una función virtual igualada a 0. Una función virtual pura es aquella que no tiene una implementación en la clase base y debe ser sobrescrita (implementada) por sus clases derivadas, de lo contrario esas clases también serán abstractas.

    Las clases abstractas no pueden ser instanciadas para crear objetos directamente, su propósito principal es servir como clases base o plantillas generales para otras clases más específicas. Las clases abstractas definen una interfaz común que sus clases derivadas deben implementar.

    El uso de clases abstractas fomenta la reutilización de código y garantiza un diseño coherente y consistente en la jerarquía de clases. Al obligar a las clases derivadas a implementar los métodos definidos como virtuales puros, se asegura que todas las clases concretas cumplan con ciertos requisitos y comportamientos definidos por la clase abstracta.

    Fuente: [https://en.cppreference.com/w/cpp/language/abstract_class](https://en.cppreference.com/w/cpp/language/abstract_class)

8. ¿Investigue qué es un constructor de copia y para qué se utiliza en C++?

    Un constructor de copia se utiliza para crear una copia de un objeto ya existente en C++. Este tipo de constructor es invocado cuando se necesita crear un nuevo objeto que tenga los mismos valores de datos que otro objeto preexistente. Por ejemplo, se utiliza cuando se quiere pasar una copia de un objeto como argumento a una función.

    El constructor de copia se activa cuando se pasa un objeto existente como parámetro a la clase, ya sea al inicializar un nuevo objeto mediante otro objeto o al pasar un objeto como argumento a una función por valor.

    ```C++
    class Molde {
	public:
		int getData(void);
		Molde(const Molde &obj); // Copy constructor
		~Molde();
	private:
		int data;
    }
    ```
    Fuente: [tutorialspoint.com/cplusplus/cpp_copy_constructor.htm](tutorialspoint.com/cplusplus/cpp_copy_constructor.htm)

9. ¿Investigue qué es el polimorfismo estático y dinámico en C++ y cómo se diferencian?

    
    El polimorfismo estático implica que la invocación de una función se resuelve en tiempo de compilación.

    En C++, esto se logra mediante la sobrecarga de funciones y operadores:

    Sobrecarga de funciones: Permite definir múltiples funciones con el mismo nombre pero con diferentes tipos o números de parámetros. Esto evita la necesidad de renombrar una acción común, ya que el compilador selecciona la función correcta en función de los parámetros utilizados en la llamada.

    Sobrecarga de operadores: Permite al usuario definir el significado de una operación para un tipo de dato creado por el mismo. Esto proporciona al programador la capacidad de definir una operación común para objetos de su propia clase.

    Por otro lado, el polimorfismo dinámico implica la resolución en tiempo de ejecución de la definición de una función.

    Esto se logra mediante la sobrescritura de funciones en clases derivadas:

    Sobrescritura de funciones: Permite a una clase derivada proporcionar una implementación específica de una función que ya está definida en una clase base. Cuando se llama a la función a través de un puntero o referencia de la clase base, la versión específica de la función en la clase derivada se ejecuta en tiempo de ejecución.
    En resumen, en el polimorfismo estático, las funciones están estáticamente ligadas a su definición por el número y tipo de parámetros en tiempo de compilación. En cambio, en el polimorfismo dinámico, la decisión de qué función invocar se resuelve en tiempo de ejecución basada en el tipo de objeto al que se refiere el puntero o la referencia.

    Fuentes: [https://www.javatpoint.com/cpp-overloading](https://www.javatpoint.com/cpp-overloading)

    [https://medium.com/swlh/everything-about-dynamic-polymorphism-in-c-b4218976d11e](https://medium.com/swlh/everything-about-dynamic-polymorphism-in-c-b4218976d11e)

    [https://www.geeksforgeeks.org/compile-time-vs-run-time-polymorphism-difference-in-cpp/](https://www.geeksforgeeks.org/compile-time-vs-run-time-polymorphism-difference-in-cpp/)
10. ¿Qué son las clases anidadas y cuál es su utilidad en C++?
    Una clase anidada, también conocida como clase interna, se declara dentro de otra clase encapsuladora en C++. La clase anidada es un miembro de su clase encapsuladora y tiene acceso a todos los miembros (públicos, protegidos y privados) de la clase encapsuladora. Sin embargo, los miembros de la clase encapsuladora no tienen un acceso especial a los miembros de la clase anidada y deben seguir las reglas de acceso establecidas.

    Las clases anidadas se utilizan como parte del encapsulamiento para "ocultar" datos de la implementación interna. Una característica importante es que las clases anidadas pueden acceder a los miembros privados de la clase encapsuladora, lo que permite una relación estrecha y controlada entre la clase encapsuladora y la clase anidada.

    Fuentes: [https://www.geeksforgeeks.org/nested-classes-in-c/](https://www.geeksforgeeks.org/nested-classes-in-c/)
    [stackoverflow.com/questions/4571355/why-would-one-use-nested-](stackoverflow.com/questions/4571355/why-would-one-use-nested-)

11. En el contexto de la programación orientada a objetos en C++, ¿cómo se pueden
utilizar los punteros para trabajar con objetos y clases? Explique también por qué los
punteros a objetos son útiles en la programación orientada a objetos.

    Para crear un puntero a una clase se puede utilizar la misma sintaxis que para cualquier otro tipo de dato:

    ```C++
    Class_name class_name_obj;
    Class_name *class_name_obj_ptr;
    ```
    Para acceder a algún método se utiliza:
    ```C++
    class_name_obj_ptr -> metodo_class();
    ```

    Los punteros a objetos son útiles principalmente porque cuando se utiliza memoria dinámica, siempre se devuelve un puntero al espacio en el heap, y por lo tanto, se necesitan punteros para acceder a estos objetos. Además, los punteros a objetos permiten modificar directamente las variables en memoria y se utilizan para el manejo de archivos.

    Fuente: [https://www.scaler.com/topics/pointer-to-object-in-cpp/](https://www.scaler.com/topics/pointer-to-object-in-cpp/)

12. ¿Qué es una función prototipo?

    Es una declaración de función que describe sus salidas, entradas y argumentos al compilador antes de que se implemente. Normalmente, estos prototipos se colocan en un archivo de encabezado (header file) y permiten al compilador revisar la función a lo largo de su uso en el programa.
13. ¿Explique los diferentes tipos de miembros que existen en la OOP?

    Públicos: Pueden ser accedidos desde cualquier parte del programa cuando se instancia el objeto.

    Privados: Solo se pueden utilizar dentro de la clase donde son definidos, excepto si se declaran funciones o clases amigas que sí pueden utilizarlos.

    Protegidos: Solo se pueden utilizar dentro de la clase donde se definen y por sus herederos.

14. ¿Qué es un memory leak?
    Es cuando no se libera el espacio de memoria asignado dinámicamente en el heap. Cuando esto sucede, se pierde ese pedacito de memoria, lo cual puede ser un problema dado que es un recurso limitado en un sistema

15. ¿Qué es y cuál es la importancia de la Herencia multinivel, múltiple y jerárquica de
C+?

    En la herencia múltiple, una clase puede heredar de dos o más clases padre según sus especificadores de acceso. Es importante porque permite mejorar la abstracción al permitir que una clase hija posea características de múltiples clases previas. Por ejemplo, una persona que hereda características de ambos padres podría representarse en el código utilizando herencia múltiple.

    En la herencia multinivel, una clase puede heredar de otra clase que a su vez es derivada. Los miembros de cada clase hija heredan de sus ancestros según sus especificadores. Esto permite agregar otra capa de abstracción a la herencia, ya que la cadena de clases puede estructurarse de manera lógica para conceptualizar las relaciones entre objetos.

    En la herencia jerárquica, una clase base puede heredar a múltiples clases hijas, pero cada clase derivada solo puede tener un ancestro. Esto crea una estructura tipo árbol que mejora la interpretación y el mantenimiento de las relaciones entre clases.

    Por tanto, estos conceptos contribuyen a la abstracción que busca proporcionar la herencia en la programación orientada a objetos, al permitir crear relaciones complejas entre clases.

    Fuente: [https://www.simplilearn.com/tutorials/cpp-tutorial/types-of-inheritance-in-cpp](https://www.simplilearn.com/tutorials/cpp-tutorial/types-of-inheritance-in-cpp)

16. ¿Qué es la composición y cómo se implementa en C++?

    La composición es una forma de crear objetos más complejos a partir de objetos base que sirven como bloques, lo cual permite dividir los problemas en partes más pequeñas. Es una forma de establecer relaciones entre objetos que va más allá de la herencia, ya que implica incluir un objeto dentro de otro como un miembro funcional.

    La composición representa una relación parte-todo en la que la parte solo puede ser miembro de un único objeto a la vez. Se accede a la parte utilizando una instancia de la clase miembro dentro de la clase contenedora. Es importante destacar que se diferencia de las clases anidadas porque la clase miembro debe ser pasada mediante una instancia a la clase contenedora y no se crea internamente, lo que promueve la modularidad del código.

    Un ejemplo de implementación es el siguiente:
    ```C++
    class Part {
	//Cuerpo de la parte
    };

    class Whole{
        //Cuerpo del todo
        private:
            Part obj; // Instancia de la clase parte
        public:
            Whole(argumentos1) : obj(argumentos2);
    };
    ```
    Fuente:[https://www.geeksforgeeks.org/object-composition-delegation-in-c-with-examples/](https://www.geeksforgeeks.org/object-composition-delegation-in-c-with-examples/)

    [https://www.scaler.com/topics/composition-in-cpp/](https://www.scaler.com/topics/composition-in-cpp/)
17. ¿Qué es la sobreescritura de funciones en C++ y cuando es bueno usarla?

    La sobrescritura es cuando una clase derivada reescribe la definición de una función heredada de su clase base. La función en ambas clases tiene la misma firma, pero cada clase proporciona una implementación diferente, lo que es un ejemplo de polimorfismo dinámico.

    Un caso de uso común es cuando se desea crear una serie de clases basadas en una clase base y cada una necesita implementar un método específico. Al utilizar la sobrescritura, no es necesario cambiar el nombre del método para cada clase derivada; en cambio, se puede llamar al método de la misma manera en todas las clases y cada una ejecutará su propia implementación. Esto mejora la interpretación y el encapsulamiento del código.

    Además, la sobrescritura ofrece la ventaja de poder crear nuevas clases sin modificar el código base, lo que facilita el mantenimiento del programa y promueve una mejor estructura modular.

    Fuente: [https://www.simplilearn.com/tutorials/cpp-tutorial/function-overriding-in-cpp](https://www.simplilearn.com/tutorials/cpp-tutorial/function-overriding-in-cpp)

18. ¿Qué es un método y un atributo y cuál es la diferencia entre ellos?

    Un método es un algoritmo o función de un objeto que puede modificar algún atributo o realizar una acción en el programa. Un atributo es un dato asociado a un objeto. La principal diferencia entre un método y un atributo radica en que un atributo modela las características o propiedades de un objeto, mientras que un método representa las acciones que un objeto puede realizar o las operaciones que puede llevar a cabo.


19. ¿Qué es el constructor y el destructor en una clase?

    El constructor es invocado por el compilador cada vez que se crea un objeto de una clase. Su función principal es reservar memoria para el objeto y luego inicializar sus atributos. El constructor tiene el mismo nombre que la clase.

    En cambio, el destructor se llama automáticamente cuando un objeto sale de su alcance o se elimina explícitamente utilizando la palabra clave delete. El destructor se encarga de liberar los recursos asociados con el objeto, como liberar la memoria asignada dinámicamente o realizar otras tareas de limpieza necesarias. El nombre del destructor es el mismo que el de la clase, precedido por el símbolo ~.


20. ¿Qué es la sobrecarga de operadores en C++ y cómo se utiliza?

    La sobrecarga de operadores es una forma en la que se puede definir el comportamiento de una operación para un objeto definido por el usuario.

    Se utiliza de la siguiente manera:
    ```C++
    class Complex{
    private:
        double real, imaginary;
    public:
        Complex(double real, double imaginary): real(real), imaginary(imaginary){};
        Complex operator+ (const Complex &c){
            Complex sum{
                real + c.real, imaginary + c.imaginary
            };
            return sum
        }
    };
    ```
    En este ejemplo, se define una clase llamada Complejo que tiene dos atributos privados para la parte real e imaginaria del número complejo. Luego, se define e inicializa el constructor de la clase para asignar los parámetros a estos atributos.

    Para sobrecargar el operador +, se utiliza nuevamente la clase Complejo. En esta parte, se pasa un puntero a otro objeto de la misma clase como parámetro. Dentro de la función de sobrecarga del operador +, se crea un nuevo objeto Complejo cuyos atributos corresponden a la suma de los números complejos representados por los objetos involucrados en la operación. Finalmente, este nuevo objeto creado se retorna como resultado de la suma.

    Por lo tanto, cuando se suman dos objetos de tipo Complejo utilizando el operador +, se obtiene como resultado otro objeto de tipo Complejo que representa la suma de los números complejos originales.