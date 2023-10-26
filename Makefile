a.out: diccionario.o interprete.o main.o
	g++ diccionario.o interprete.o main.o

diccionario.o: diccionario.cpp diccionario.hpp
	g++ -c diccionario.cpp

interprete.o: interprete.cpp interprete.hpp diccionario.hpp
	g++ -c interprete.cpp

main.o: main.cpp diccionario.hpp interprete.hpp
	g++ -c main.cpp
