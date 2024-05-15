# TAREA #5
## Compilación
Crear un nuevo directorio en la carpeta que se crea el folder llamado bin.
En una terminal de windows ejecutar:
```bash
mingw32-make
```
Esto corre el ejecutable `tarea5.x` de forma automática.
## Parte Teórica

1. **¿Qué es una expresión regular y cuál es su propósito en programación?**

   Una expresión regular es una secuencia de caracteres que define un patrón de búsqueda o manipulación de texto. Su propósito en programación es permitir la búsqueda, validación y manipulación eficiente de cadenas de texto de manera flexible y poderosa.

2. **¿Qué significan los caracteres especiales `.` y `*` en una expresión regular?**
   
   - `.`: Representa cualquier carácter, excepto el salto de línea. Por ejemplo, `chip.` coincidiría con `chipiranga`.
   - `*`: Indica que el elemento anterior puede aparecer cero o más veces. Por ejemplo, `UC*R` coincidiría con `UR` o `UCCCR`.

3. **¿Cómo se pueden agrupar subexpresiones en una expresión regular?**
   
   Se utilizan paréntesis `()` para agrupar subexpresiones y aplicar operadores a dichos grupos. Por ejemplo, `^(d+)\.txt` coincidiría con cualquier archivo `.txt` que no contenga dígitos en el nombre.

4. **¿Qué función cumple la barra invertida `\` en una expresión regular?**
   
   La barra invertida `\` se utiliza para escapar caracteres especiales en una expresión regular. Por ejemplo, en la pregunta anterior, `\.` se utiliza para coincidir con un punto literal en lugar de su significado especial.

5. **Explique cómo se pueden capturar coincidencias usando paréntesis en una expresión regular.**
   
   Al utilizar paréntesis `()` alrededor de una parte de la expresión regular, se crea un grupo de captura. Esto permite extraer o trabajar con las coincidencias encontradas dentro de ese grupo específico.

6. **¿Cuál es la diferencia entre `\d` y `\D` en una expresión regular?**
   
   - `\d`: Coincide con cualquier dígito (0-9).
   - `\D`: Coincide con cualquier carácter que no sea un dígito.

7. **¿Cómo se representa una clase de caracteres en una expresión regular?**
   
   Se representa utilizando corchetes `[]` para definir un conjunto de caracteres posibles que pueden coincidir en esa posición de la expresión regular. Por ejemplo, `[aeiou]` representa cualquier vocal.

8. **¿Cuál es el propósito del modificador `$` en una expresión regular?**
   
   El modificador `$` especifica que la coincidencia debe encontrarse al final de la cadena. Por ejemplo, `solis$` coincidiría con `Marianasolis`.

9. **Describa cómo validar una dirección de correo electrónico usando expresiones regulares en C++.**
   
   -  Primero se debe comprobar que los elementos antes del arroba solo contengan letras, números y otros caracteres permitidos. Lo cual se realiza de la siguiente manera:
    ```regex
    ([\D\d_.+-]+)
    ```
    - Luego, la expresión debe garantizar que se contenga el símbolo '@' y la extensión se comprueba igual que en el caso anterior. Por último, se debe asegurar que exista un punto seguido de '.com'. La expresión final se muestra a continuación:
    ```regex
    ([\D\d_.+-]+)@([\D\d_.+-]+)\.([\D\d_.+-]+)
    ```
10. **Discuta las implicaciones de rendimiento de utilizar expresiones regulares en aplicaciones de software. ¿Qué técnica se pueden aplicar para optimizar una expresión regular compleja, especialmente en contextos donde el tiempo de ejecución es crítico?**
En general, dado que las expresiones regulares esencialmente buscan ciertos elementos en una cadena, la mayoría de las fuentes indican que tienen una complejidad de O(n). No obstante, se debe tener precaución al formatear la expresión regular, ya que en algunos casos podría resultar en expresiones que requieren mucho trabajo computacional.
Para mejorar el tiempo de ejecución, en general, se recomienda mantener las expresiones simples para evitar búsquedas iterativas extensas en la cadena. Por ejemplo, se debe evitar el uso de .\*, que fuerza una búsqueda hasta el final del mensaje para encontrar un carácter. También es aconsejable evitar expresiones con repeticiones indexadas repetitivas como ([\d]+)*, que implica buscar todos los dígitos una o más veces antes de continuar con la expresión.

    Fuentes: (https://www.ibm.com/docs/en/app-connect/11.0.0?topic=msurepde-message-sets-performance-considerations-when-using-regular-expressions)[https://www.ibm.com/docs/en/app-connect/11.0.0?topic=msurepde-message-sets-performance-considerations-when-using-regular-expressions]

    (https://stackoverflow.com/questions/5892115/whats-the-time-complexity-of-average-regex-algorithms)[https://stackoverflow.com/questions/5892115/whats-the-time-complexity-of-average-regex-algorithms]

11. **¿Qué es un Makefile y cuál es su función en un proyecto de C++?**
El comando make es una forma de manejar la compilación de programas con muchas dependencias. Este comando lee las instrucciones almacenadas en un archivo llamado Makefile, que contiene una serie de reglas para determinar qué partes del programa deben ser recompiladas.
El papel del comando make es fundamental en C++ porque proporciona una manera eficiente de automatizar la construcción de programas y optimizar el proceso de compilación. Cuando se ejecuta make, este analiza las dependencias entre los archivos fuente y los archivos objeto y  solo se recompilan los archivos que han sido modificados desde la última compilación, lo que ahorra tiempo y recursos.

12. **¿Cuál es la diferencia entre una regla implícita y una regla explícita en un Makefile?**

    
    Las reglas implícitas son instrucciones generales para archivos sin reglas explícitas. Las reglas explícitas con instrucciones para archivos específicos. Las reglas explícitas se encargan de darle a make las instrucciones que debe seguir para construir un TARGET. Se especifican de la siguiente forma:
    
    ```bash
    target : [:] dependencias
        comandos
    ```
    
    El numero : indica cuantas reglas están escritas para el TARGET.
    
    En cambio las reglas implícitas se usan de forma automática por make a partir de patrones en nombres de archivos para crear archivos target a partir de archivos fuente. Empieza con un path o un punto, la primera entrada son los targets genéricos y la segunda sus [dependencias.](http://dependencias.Si) Si las dependencias implícitas están desactualizadas MAKE ejecuta el comando para compilar esa [regla.](http://regla.Se) Se especifican de la siguiente forma:
    
    ```bash
    target... : dependecias ..
    	comandos
    ```
    
    Fuente: ([https://docwiki.embarcadero.com/RADStudio/Alexandria/en/MAKE_Rules_(Explicit_and_Implicit)_and_Commands#:~:text=You write explicit and implicit,for files without explicit rules](https://docwiki.embarcadero.com/RADStudio/Alexandria/en/MAKE_Rules_(Explicit_and_Implicit)_and_Commands#:~:text=You%20write%20explicit%20and%20implicit,for%20files%20without%20explicit%20rules).)[[https://docwiki.embarcadero.com/RADStudio/Alexandria/en/MAKE_Rules_(Explicit_and_Implicit)_and_Commands#:~:text=You write explicit and implicit,for files without explicit rules](https://docwiki.embarcadero.com/RADStudio/Alexandria/en/MAKE_Rules_(Explicit_and_Implicit)_and_Commands#:~:text=You%20write%20explicit%20and%20implicit,for%20files%20without%20explicit%20rules).]
13. **Explique el propósito de las macros (variables) en un Makefile** 
    
    Son una forma de crear variables que pueden utilizarse a lo largo del Makefile. Esto permite parametrizarlo, ya que si se necesita cambiar el valor del macro, no es necesario modificar todo el archivo.
14.  **¿Qué es un objetivo (target) en un Makefile y cómo se define?**
    Son lo que se busca obtener cuando se compila el programa. Pueden ser archivos ejecutables o acciones como la  limpieza. Se define de la siguiente manera:

        ```bash
        target: dependecias
        ```
15. **¿Por qué es util dividir un proyecto de C++ en múltiples archivos fuente y cómo ayuda
el uso de Makefiles en este enfoque?**
    
    
    Primero, por motivos de organización, dividir un proyecto extenso en múltiples archivos permite tener una estructuración más modular para saber para qué sirve cada uno. Esto facilita el mantenimiento y la búsqueda de errores. Además, dado que los archivos están separados, se pueden utilizar en múltiples partes del proyecto, lo que evita la repetición de código. Por último, al separar los archivos en archivos de encabezado (header files) y archivos fuente, se mejora la encapsulación del programa, ya que diferentes archivos solo deben interactuar con las definiciones sin necesidad o posibilidad de acceder a la implementación.
    
    Los Makefiles automatizan la tarea de compilar los diferentes archivos que componen el proyecto. Esto no solo permite ahorrar tiempo en comparación con hacerlo manualmente, sino que también, si se realiza una modificación en alguna parte, no es necesario recompilar todo el proyecto. Esto mejora la eficiencia en el tiempo y contribuye a que el mantenimiento del código sea más manejable.
16. **¿Cómo se pueden definir dependencias entre los archivos fuente en un Makefile?**
    
    Cuando se especifican los target de cuales archivos fuente dependen y como crearlos a partir de ellos. Por ejemplo:
    
    ```bash
    $(EXEC): $(OBJS)
    	$(CXX) $(CXXFLAGS) $^ -o $@
    
    $(OUTDIR)/%.o: $(SRCDIR)/%.cpp | $(OUTDIR)
    	$(CXX) $(CXXFLAGS) -c $< -o $@
    ```
    
    Aquí el ejecutable, depende de los archivos objeto que se compilan por separado en archivos objeto.
    
17. **Explique cómo se puede compilar un proyecto en diferentes sistemas operativos usando
un solo Makefile.**
    
    Se pueden usar defines para identificar en cuál sistema operativo se encuentra y de esa manera modificar los Macros necesarios para adaptarse. Por ejemplo:
    
    ```bash
    ifeq ($(shell uname) , Linux)
    	CC := gcc
    	FLAG := -Wall
    endif
    
    ifeq ($(shell uname) , Darwin)
    	CC := clang
    	FLAG := -Wall
    endif
    ```
    
    Aquí se utiliza el comando `shell uname` para identificar el sistema operativo en en base a ello se cambia el compilador.
    
    Fuente: (https://www.oreilly.com/library/view/managing-projects-with/0596006101/ch03.html)[https://www.oreilly.com/library/view/managing-projects-with/0596006101/ch03.html]
    
18. **¿Cuál es el propósito de los comandos clean y all en un Makefile?**
    
    `clean` : es usado para eliminar los archivos generados.
    
    `all` : Se utiliza para especificar un target default a make.
    
19. **Describa cómo se pueden pasar argumentos desde la lınea de comandos a un Makefile.**
    
    Si no se específica que son variables make interpreta los argumentos como sus propios targets. No obstante se puede pasar argumentos definiendolos como variables de la siguiente manera:
    
    ```bash
    make chipi=2 target
    ```
    
20. **Proporcione un ejemplo de una regla en un Makefile que compile un archivo fuente
.cpp a un archivo objeto .o.**

```bash
main.o: main.cpp
	g++ -c main.cpp -o main.o
```

## Parte Automatización- Makefile

1. **¿Qué suelen contener las variables CC, CFLAGS, CXXFLAGS y LDFLAGS en un
makefile?**
    
    
    | Variable | Contenido |
    | --- | --- |
    | CFLAGS | Opciones para el compilador de C |
    | CXXFLAGS | Opciones para el compilador de C++ |
    | LDFLAGS | Pasar flags al linker usualmente directorios de librerías |
    | CC | Compilador |
    
    Fuente: (https://earthly.dev/blog/make-flags/)[https://earthly.dev/blog/make-flags/]
    
2. **¿De qué se compone una regla en un Makefile?**
    
    Una regla que da las instrucciones de como crear un target se compone de:
    
    1. **Target**: El resultado que se busca tener de salida con la regla 
    2. **Dependencias**: Archivos que necesita el target para construirse
    3. **Comandos**: Instrucciones para que make pueda construir el target a partir de las dependencias.
3. **Defina qué es un target y cómo se relaciona con sus prerrequisitos.**
    
    Un target es lo que se busca obtener con una regla, puede ser un archivo o una acción. Necesita de sus dependencias para poder construirse
    
4. **Para qué se utiliza la bandera -I, -c y -o del compilador gcc?**
    
    
    | Bandera | Uso |
    | --- | --- |
    | -o | Pasa el output a un archivo con cierto nombre |
    | -c | Compilar archivos fuente a archivos objeto sin linker |
    | -l | Pasar librerías al linker |
    
    Fuente: (https://www.rapidtables.com/code/linux/gcc.html#options)[https://www.rapidtables.com/code/linux/gcc.html#options]
    
5. **¿Cómo se definen y se utilizan las variables en un Makefile? ¿Qué utilidad tienen?**
    
    Las variables se definen de la siguiente manera:
    
    ```bash
    VAR = gcc
    ```
    
    Se utilizan:
    
    ```bash
    $(VAR)
    ```
    
    Ayudan a parametrizar las opciones de compilación para que pueden ser modificadas de manera eficiente. 
    
6. **¿Qué utilidad tiene un @ en un Makefile?**
    
    Se utiliza para que un comando no se imprima en la terminal cuando se ejecuta.
    
7. **¿Para qué se utiliza .PHONY en un Makefile?**
Para indicar que un target no crea un archivo , sino alguna acción.