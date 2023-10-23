
#include

#include <iostream>

using namespace std;



int main (void){
    
    Interprete *interprete = new Interprete();
    
    string comando;

    while (cin>>comando){
        (*interprete).procesar(comando);
    }
    
    delete interprete;
}
