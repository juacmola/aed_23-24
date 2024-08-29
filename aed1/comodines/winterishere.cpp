#include <iostream>
#include <vector>
using namespace std;
int main (void){
    vector<int> dias_hasta_invierno;
    while(true){
        string mes;
        int dia;
        cin >> dia;

        if(dia==0){break;}

        cin >> mes;

        if(mes=="Dec"){
            dias_hasta_invierno.push_back(21-dia);
        }else if(mes=="Nov"){dias_hasta_invierno.push_back(51-dia);}
        else if(mes=="Oct"){dias_hasta_invierno.push_back(82-dia);}
        else if(mes=="Sep"){dias_hasta_invierno.push_back(112-dia);}
        else if(mes=="Aug"){dias_hasta_invierno.push_back(143-dia);}
        //else if(mes=="May"){dias_hasta_invierno = 173-dia;}
        //else if(mes=="Apr"){dias_hasta_invierno = 21-dia;}
        //else if(mes=="Mar"){dias_hasta_invierno = 21-dia;}
        //else if(mes=="Nov"){dias_hasta_invierno = 21-dia;}
        //else if(mes=="Nov"){dias_hasta_invierno = 21-dia;}
    }
    for (int l=0; l<dias_hasta_invierno.size(); l++){
            if(dias_hasta_invierno[l]>0){
                cout << dias_hasta_invierno[l] << " days to winter" << endl;
            }
            else{cout <<"Winter is here"<< endl;}
        }
}

