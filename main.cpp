#include "interprete.hpp"
#include <iostream>

using namespace std;

void procesar(string comando);

int main (void){
    string comando;

    while (cin>>comando){
        procesar(comando);
    }
}
