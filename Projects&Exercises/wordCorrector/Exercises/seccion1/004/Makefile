a.out: diccionario.o interprete.o main.o
	g++ diccionario.o interprete.o main.o

interprete.o: interprete.cpp interprete.hpp diccionario.hpp
	g++ -c interprete.cpp

diccionario.o: diccionario.cpp diccionario.hpp
	g++ -c diccionario.cpp

main.o: main.cpp diccionario.hpp interprete.hpp
	g++ -c main.cpp
