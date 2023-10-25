#include "interprete.hpp"
#include <iostream>

using namespace std;

int main (void){
    string comando;

    while (cin>>comando){
        Interprete(comando);
    }
}
