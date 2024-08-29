#ifndef NODOARBOL_H_INCLUDED
#define NODOARBOL_H_INCLUDED

#include <string>

using namespace std;

class NodoArbol {
	private:
		char caracter;
		NodoArbol *ptr, *sig;

	public:
		NodoArbol();
		NodoArbol(char car, NodoArbol* sig, NodoArbol* ptr);
		~NodoArbol();

        NodoArbol* consulta(char caracter);
		void inserta(char caracter);
		void PonMarca();
		void QuitaMarca();
		bool HayMarca();
        void alargarpal(string &palActual, string &mejorPalabra);
};


#endif
