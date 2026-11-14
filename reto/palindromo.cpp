#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

tuple<int,int> palindromo(string contenido){
    string transformado = "#";

    for (char c : contenido){
        transformado += c;
        transformado += '#';
    }

    int n = transformado.size(); //tamaño de contenido
    vector<int>P(n,0); //llenar de ceros

    int C = -1; //centro cuando la derecha ya avanzó
    int R = -1; //derecha mas avanzada
    int best = 0; //mejor largo de palindromo
    int indexBest = -1; //centro del mejor palindromo

    for(int i = 0; i < n; i++){
        if(i < R){ //cuando i si esta en el rango de R
            int mirror = 2*C - i;
            P[i] = min(P[mirror],R - i );
        }
        else{
            P[i] = 0;
        }
        
        while((i - P[i] - 1) >= 0 && (i + P[i] + 1) < n &&  transformado[i - P[i] - 1] == transformado[i + P[i] + 1]){
            P[i] = P[i] + 1;
        }

        if (best < P[i]){
            best = P[i];
            indexBest = i;
        }

        if(R < i + P[i]){
            R = i + P[i];
            C = i;
        }
    }

    int inicioTransformado = indexBest - best;
    if (transformado[inicioTransformado] == '#'){
        inicioTransformado++;
    }

    int finTransformado = indexBest + best;
    if (transformado[finTransformado] == '#'){
        finTransformado--;
    }

    return make_tuple((inicioTransformado + 1) / 2, (finTransformado + 1) / 2);
}

tuple<int,int> LCS(string a1, string a2){
    int filas = a1.size() + 1;
    int columnas = a2.size() + 1;
    int bestL = 0;
    int bestI = 0;

    vector<vector<int>>DP(
        filas, vector<int>(columnas,0)
    );

    DP[0][0] = 0;

    for(int i = 1; i < filas; i++){
        for(int j = 1; j < columnas; j++){
            if (a1[i - 1] == a2[j - 1]){
                DP[i][j] = DP[i-1][j-1] + 1;
                
                if (DP[i][j] > bestL){
                    bestL = DP[i][j];
                    bestI = i;
                }
            }
            else{
                DP[i][j] = 0;
            }
        }
    }
    int inicio = bestI - bestL + 1;
    return make_tuple(inicio, bestI);
}




string leerArchivo(string nombreArchivo) {

    // abrir archivo
    // leer todos sus caracteres
    // guardar caracteres en un string

    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return "";
    }

    string contenido = "";
    char caracter;

    while (archivo.get(caracter)) {
        contenido += caracter;
    }

    return contenido;
}




int main() {


    //cout << transmision << endl;

    return 0;
}