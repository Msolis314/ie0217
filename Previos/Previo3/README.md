# Previo 3
Para este previo se logro investigar un poco más acerca de como elaborar _makefiles_ y por tanto se logro automatizar el proceso. Además, se añadio un script de bash para la ejecución de archivos en el directorio de bin. 

## Ejecución 

Primero crear un directorio llamado bin en la carpeta `Previo3` una vez se clona el repositorio. Para ello correr el siguiente comando en una terminal de bash:
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
## Referencias
Para crear el makefile se hizo uso del siguiente tutorial:
https://makefiletutorial.com/