
#include "nodoArbol.hpp"

#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <string>

using namespace std;

class ArbolPalabras {
private:
    NodoArbol* raiz;    
    int nElem;

public:
    ArbolPalabras();
    ~ArbolPalabras();

    void insertar(string palabra);
    void vaciar(void);
    void alargar(string palabra);
    int numElem(void) { return nElem; }
};

#endif 

