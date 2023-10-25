#include "diccionario.hpp"

DicPalabras dic;

DicPalabras::DicPalabras () {
    contador= 0;
}

void DicPalabras::vaciar (void) {
    lista.clear();
    contador= 0;
}

void DicPalabras::inserta (string palabra){
    //Insertar palabra en lista de forma ordenada
    //Si no estaba ya, contador++
}

bool DicPalabras::consulta (string palabra){
    //Buscar en la lista la palabra
    //Devolver true/false si está o no, respectivamente
}


