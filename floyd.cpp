#include<iostream>
#include<vector>
using namespace std;

void Floyd(int nodos, vector<vector<int>> matrix){
    vector<vector<int>>dist(nodos, vector<int>(nodos)); //matriz de distancias
    const int INF = 2147483647; //numero más grande que acepta un int

    //crear matriz cambiando -1 por infinitos
    for(int i = 0; i < nodos; i++){
        for(int j = 0; j < nodos; j ++){
            if (matrix[i][j] == -1){
                dist[i][j] = INF;
            }
            else{
                dist[i][j] = matrix[i][j];
            }
        }
    }

    //recalcular pasos para llegar nodo final, pasando por k como intermedio
    for(int k = 0; k < nodos; k ++){
        for(int i = 0; i < nodos; i ++){
            for(int j = 0; j < nodos; j ++){
                if (dist[i][k] != INF && dist[k][j] != INF) { //evitar error por suma de infinitos
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    //imprimir matriz
    for(int i = 0; i < nodos; i++){
        for(int j = 0; j < nodos; j ++){
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    int nodos;
    cin >> nodos;

    vector<vector<int>> matrix(nodos, vector<int>(nodos));

    // Leer matriz de adyacencia
    for (int i = 0; i < nodos; i++) {
        for (int j = 0; j < nodos; j++) {
            cin >> matrix[i][j];
        }
    }

    Floyd(nodos, matrix);

    return 0;
}