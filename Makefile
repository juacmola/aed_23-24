a.out: diccionario.o interprete.o TablaHash.o main.o
	g++ diccionario.o interprete.o TablaHash.o main.o

diccionario.o: diccionario.cpp diccionario.hpp TablaHash.hpp
	g++ -c diccionario.cpp

interprete.o: interprete.cpp interprete.hpp diccionario.hpp
	g++ -c interprete.cpp

TablaHash.o: TablaHash.cpp TablaHash.hpp interprete.hpp
	g++ -c TablaHash.cpp

main.o: main.cpp diccionario.hpp interprete.hpp TablaHash.hpp
	g++ -c main.cpp
