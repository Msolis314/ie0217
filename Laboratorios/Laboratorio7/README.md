# LABORATORIO #7
En el presente laboratorio se hizo una ejemplificación de como utilizar expresiones regulares para la busqueda de patrones en _strings_ y del uso de `Makefiles` para facilitar el proceso de compilación.Esto mediante a un programa sencillo de procesamiento de texto.
## Compilación 
Primero se debe crear la carpeta bin en el directorio donde se clona el repositorio. 

Luego, para compilar en una terminal en Windows ejecutar:
```bash
mingw32-make
```
## Ejecución 
Para ejecutar el programa se utiliza:
```bash
./bin/textprocessor -f data/input.txt -o data/output.txt -search "foo" -replace "bar"
```
Donde se debe tomar en cuenta que se necesitan 4 entradas despues de los siguientes flags:
| **Flag** 	| **Entrada** 	|
|---	|---	|
| -f 	| Archivo de texto para remplazar con el patrón 	|
| -o 	| Nombre del archivo de salida con el patrón remplazado 	|
| -search 	| String con la palabra o patrón para buscar 	|
| -replace 	| String de reemplazo 	|