
#include <stdlib.h>  // Funcion exit
#include <string.h>  // Funcion memset
#include <iostream>  // Variables cin y cout
#include <vector>    // Para trabajar con vectores.
#include <unordered_map> // Para usar un mapa no ordenado que asocia nombres de ciudades con números de nodo.
#include <algorithm> // Para la función min

using namespace std;

#define MAX_NODOS 200 // Numero máximo de ciudades.

//////////////////////////////////////////////////////////////
////////////        VARIABLES GLOBALES        ////////////////
//////////////////////////////////////////////////////////////

int nciudades;                // Numero de ciudades
const int INF = 1e9;          // Constante infinita

//////////////////////////////////////////////////////////////
////////////     FUNCIONES DEL PROGRAMA       ////////////////
//////////////////////////////////////////////////////////////

void floyd(vector<vector<int>>& dist, int n){ // La funcion del algoritmo Floyd
 for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }   
}

void leeGrafo (void){
    cin >> nciudades;
    cin.ignore();
    
    if (nciudades<0 || nciudades>MAX_NODOS) { //Comprobamos que el numero de ciudades es mayor que 0 y menor que 200
        cerr << "Numero de ciudades (" << nciudades << ") no valido\n";
        exit(0);
	}
    
    unordered_map<string, int> ciudadToNumero;              // Mapa que asocia el nombre de una ciudad a un numero
	vector<string> numeroToCiudad;                          // Vector que asocia numero con nombre de ciudades
	string linea;
	for (int i = 0; i < nciudades; i++) {
	    getline(cin >> ws,linea);
	    ciudadToNumero[linea] = i;
	    numeroToCiudad.push_back(linea);
	}
	
	vector<vector<int>> dist(nciudades, vector<int>(nciudades, INF));   // Matriz de distancias
    for (int i=0;i<nciudades;i++) dist[i][i]=0;             // A 0 la diagonal de la matriz
    
    int A, B, L;
    while (true) {
        cin >> A >> B >> L;
        if (A == 0 && B == 0 && L == 0) break;
        dist[A][B] = dist[B][A] = L;                        // Introducimos las distancias en la matriz
    }

    floyd(dist, nciudades);                                 // Llamamos a la función floyd

    int minExcentricidad = INF;                             // Excentricidad a infinito
    string centro;                                          // Centro ciudad

    // Calcula la excentricidad de cada ciudad y encuentra el centro
    for (int i = 0; i < nciudades; i++) {
        int maxDist = 0;
        for (int j = 0; j < nciudades; j++) maxDist = max(maxDist, dist[i][j]);

        if (maxDist < minExcentricidad || (maxDist == minExcentricidad && numeroToCiudad[i] < centro)) {
            minExcentricidad = maxDist;
            centro = numeroToCiudad[i];
        }
    }
    cout << centro << endl << minExcentricidad << endl;     // Se imprime el resultado
}

//////////////////////////////////////////////////////////////
////////////        PROGRAMA PRINCIPAL        ////////////////
//////////////////////////////////////////////////////////////

int main (void){
  int ncasos;
  cin >> ncasos;
  for (int i= 0; i<ncasos; i++) {
    leeGrafo();
  }
}