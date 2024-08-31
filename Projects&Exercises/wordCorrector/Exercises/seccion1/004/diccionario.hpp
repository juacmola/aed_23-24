#ifndef _DICCIONARIO_H_INCLUDED
#define _DICCIONARIO_H_INCLUDED

#include <list>
#include <string>

using namespace std;

class DicPalabras {
    private:
        list<string> lista;
        int contador;
    public:
        DicPalabras ();
        void vaciar ();
        void insertar (string palabra);
        bool consultar (string palabra);
        int numElem (void) {return contador;}
};
#endif
