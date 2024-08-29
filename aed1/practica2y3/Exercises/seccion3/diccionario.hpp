#include "arbol.hpp"
#include "TablaHash.hpp"

#ifndef _DICCIONARIO_H_INCLUDED
#define _DICCIONARIO_H_INCLUDED

using namespace std;

class DicPalabras {
    private:
        TablaHash tabla;
        ArbolPalabras arbol;
    public:
        DicPalabras ();
        void vaciar (void) { tabla.vaciar(); arbol.vaciar(); }
        void insertar (string palabra) { tabla.insertar(palabra); arbol.insertar(palabra); }
        bool consultar (string palabra) { return tabla.consultar(palabra); }
        void alarga (string palabra) { arbol.alargar(palabra); } 
        int numElem (void) { return arbol.numElem(); }
};
#endif
