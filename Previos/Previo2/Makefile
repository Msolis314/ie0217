all: Previo2

Previo2: operadores.o variables.o estructuras.o funciones.o holaMundo.o scope.o scope2.o
	g++  operadores.o -o operadores.exe
	g++  variables.o -o variables.exe
	g++  estructuras.o -o estructuras.exe
	g++  funciones.o -o funciones.exe
	g++  holaMundo.o -o holaMundo.exe
	g++  scope.o  scope2.o -o scope.exe
	


operadores.o: operadores.cpp
	g++ -c operadores.cpp

variables.o: variables.cpp
	g++ -c variables.cpp

estructuras.o: estructuras.cpp
	g++ -c estructuras.cpp

funciones.o: funciones.cpp
	g++ -c funciones.cpp

hola.o: holaMundo.cpp
	g++ -c holaMundo.cpp

scope.o: scope.cpp
	g++ -c scope.cpp

scope2.o: scope2.cpp
	g++ -c scope2.cpp
clean:
	rm -f *.o Previo2
	rm -f *.o operadores.exe
	rm -f *.o variables.exe
	rm -f *.o estructuras.exe
	rm -f *.o funciones.exe
	rm -f *.o holaMundo.exe
	rm -f *.o scope.exe
	rm -f *.o scope2.exe













