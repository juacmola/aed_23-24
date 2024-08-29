#include "diccionario.hpp"

#include <iostream>
#include <sstream>


using namespace std;

DicPalabras::DicPalabras() : tabla(){}

/*string DicPalabras::encontrarJuanagrama (string palabra){
    vector<string> posiblesJuanagramas;
    
    for (auto& palabraDic : tabla.getTabla()){
        if (palabraDic.length() == palabra.length() && palabraDic != palabra){
            sort(palabraDic.begin(), palabraDic.end());
            sort(palabra.begin(), palabra.end());
            if (palabraDic == palabra){
                posiblesJuanagramas.push_back(palabraDic);
            }
        }
    }
    
    if (!posiblesJuanagramas.empty()){
        sort(posiblesJuanagramas.begin(), posiblesJuanagramas.end());
        return posiblesJuanagramas[0];
    } else { return " "; }
}*/
