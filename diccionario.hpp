#ifndef _DICCIONARIO_H_INCLUDED
#define _DICCIONARIO_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <sstream>
#include <list>

using namespace std;



class DicPalabras {
    private:
        list<string> lista;
        int contador;
    public:
        DicPalabras ();
        void inserta (string palabra);
        bool consulta (string palabra);
        void vacia (void);
        int nTotal (void) {return contador;}
};
#endif
