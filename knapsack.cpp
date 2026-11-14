#include<iostream>
using namespace std;
#include<vector>

//retorna el max valor entre tomar o no tomar el item
int findMaxVal(vector<int> &pesos, vector<int> &valor, int index, int espacioRestante, vector<vector<int>> &matrix){
    // caso base
    if (index == pesos.size()){
        return 0;
    }

    //si ya estaba calcualdo en la matrix -> evitar recalcular
    if (matrix[index][espacioRestante] != -1){
        return matrix[index][espacioRestante];
    } 

    //calcular cuando no se toma
    int noTomar = findMaxVal(pesos, valor, index + 1, espacioRestante, matrix);

    //si tomar el item no cabe, retornar noTomar y guardar en la matriz
    if (espacioRestante - pesos[index] < 0){
        matrix[index][espacioRestante] = noTomar;
        return noTomar; //salir de la función
    }

    //calcular tomar
    int tomar = valor[index] + findMaxVal(pesos, valor, index + 1, espacioRestante - pesos[index], matrix);
    
    //guardar el max entre tomar y no tomar
    matrix[index][espacioRestante] = max(noTomar, tomar);
    return matrix[index][espacioRestante];
}

int dp(vector<int> &pesos, vector<int> &valor, int espacioRestante){
    //crear matrix
    int N = pesos.size();
    vector<vector<int>> matrix(N, vector<int>(espacioRestante + 1, -1));

    return findMaxVal(pesos, valor, 0, espacioRestante, matrix);
}


int main() {
    int N;
    cin >> N;

    vector<int> valor(N);
    vector<int> pesos(N);

    // Leer valores de los objetos
    for (int i = 0; i < N; i++) {
        cin >> valor[i];
    }

    // Leer pesos de los objetos
    for (int i = 0; i < N; i++) {
        cin >> pesos[i];
    }

    // Leer capacidad máxima de la mochila
    int W;
    cin >> W;
    cout<<'\n'<<"Resultado:"<<endl;
    // Obtener e imprimir el beneficio máximo
    cout << dp(pesos, valor, W) << endl;

    return 0;
}