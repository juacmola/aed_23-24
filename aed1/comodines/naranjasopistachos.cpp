#include <iostream>
#include <vector>
using namespace std;
int main (void){
    vector<string> puesto_final;
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        string puesto_inicial;
        int kilometro;

        cin>>puesto_inicial>>kilometro;
        if (kilometro%2==1){
            if (puesto_inicial=="pistachos"){
                puesto_final.push_back("naranjas");
            }else{puesto_final.push_back("pistachos");}
        }
        else{puesto_final.push_back(puesto_inicial);}
    }
    for (int l=0; l<puesto_final.size(); l++){
        cout << puesto_final[l] << endl;
    }
}

