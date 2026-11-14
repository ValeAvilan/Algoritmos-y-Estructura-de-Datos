#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

void branchBound(vector<vector<int>>&laberinto,vector<vector<int>>&camino ,vector<vector<int>>&res, int curr, int &best, tuple<int,int>coordenadas){
    //podar
    if(curr>=best){ 
        return;
    }

    //obtener coordenadas x,y
    int x=get<0>(coordenadas);
    int y= get<1>(coordenadas);

    //marcar camino
    camino[x][y]=1;

    //verificar si ya llegué a la salida -> como ya paso por la verificación de menor
    if(x==laberinto.size()-1 && y==laberinto[0].size()-1){
        best=curr; //guardar nuevo mejor y el mejor camino
        res=camino;
        camino[x][y]=0;
        return;
    }

    //backtracking
    if(x+1<laberinto.size() && laberinto[x+1][y]==1 && camino[x+1][y]==0){ //derecha
        branchBound(laberinto,camino,res,curr+1,best,make_tuple(x+1,y));
    }

    if(y+1<laberinto[0].size() && laberinto[x][y+1]==1 && camino[x][y+1]==0){ //arriba
        branchBound(laberinto,camino,res,curr+1,best,make_tuple(x,y+1));
    }

    if(x-1>=0 && laberinto[x-1][y]==1 && camino[x-1][y]==0){ //izq
        branchBound(laberinto,camino,res,curr+1,best,make_tuple(x-1,y));
    }

    if(y-1>=0 && laberinto[x][y-1]==1 && camino[x][y-1]==0){
        branchBound(laberinto,camino,res,curr+1,best,make_tuple(x,y-1));
    }

    camino[x][y]=0; //deshacer
    return;
}


int main(){

    int M, N;

    cin >> M;
    cin >> N;

    // leer laberinto
    vector<vector<int>> laberinto(M, vector<int>(N));

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> laberinto[i][j];
        }
    }

    // camino que estoy explorando
    vector<vector<int>> camino(M, vector<int>(N, 0));

    // mejor camino encontrado
    vector<vector<int>> res(M, vector<int>(N, 0));

    // empezamos sin haber hecho movimientos
    int curr = 0;

    // todavía no existe una mejor solución
    int best = INT_MAX;

    // coordenada inicial
    tuple<int,int> inicio = make_tuple(0,0);

    // ejecutar Branch and Bound
    branchBound(laberinto, camino, res, curr, best, inicio);


    // imprimir resultado
    cout << "\nMejor camino:" << endl;

    for(int i = 0; i < M; i++){

        for(int j = 0; j < N; j++){

            cout << res[i][j];

            if(j < N-1){
                cout << " ";
            }
        }

        cout << endl;
    }

    // imprimir costo
    if(best == INT_MAX){
        cout << "No existe camino" << endl;
    }
    else{
        cout << "Costo: " << best << endl;
    }

    return 0;
}