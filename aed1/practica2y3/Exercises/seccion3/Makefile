a.out: diccionario.o interprete.o arbol.o nodoArbol.o TablaHash.o main.o
	g++ diccionario.o interprete.o arbol.o nodoArbol.o TablaHash.o main.o

diccionario.o: diccionario.cpp diccionario.hpp arbol.hpp TablaHash.hpp
	g++ -g -c diccionario.cpp

interprete.o: interprete.cpp interprete.hpp diccionario.hpp
	g++ -g -c interprete.cpp

arbol.o: arbol.cpp arbol.hpp nodoArbol.hpp
	g++ -g -c arbol.cpp

nodoArbol.o: nodoArbol.cpp nodoArbol.hpp
	g++ -g -c nodoArbol.cpp

TablaHash.o: TablaHash.cpp TablaHash.hpp
	g++ -g -c TablaHash.cpp

main.o: main.cpp diccionario.hpp interprete.hpp arbol.hpp nodoArbol.hpp TablaHash.hpp
	g++ -g -c main.cpp
