#include<iostream>
#include<vector>
#include <tuple>
using namespace std;

bool backtracking (vector<vector<int>>&laberinto, vector<vector<int>>& res, tuple<int,int>coordenada){
    //obtener x y y de coordenada
    int x = get<0>(coordenada); 
    int y = get<1>(coordenada);

    res[x][y] = 1; //marcar casilla de camino

    //verificar si ya llegue a la meta
    if (x==laberinto.size()-1 and y==laberinto[0].size()-1){ 
        return true;
    } 

    
    if(y-1>=0 && laberinto[x][y-1]==1 && res[x][y-1]==0){
        if (backtracking(laberinto, res, make_tuple(x,y-1))){
            return true;
        }
    }
    if(x+1<laberinto.size() && laberinto[x+1][y]==1 && res[x+1][y]==0){
        if(backtracking(laberinto, res, make_tuple(x+1,y))){
            return true;
        }
    }
    if(x-1>=0 && laberinto[x-1][y]==1 && res[x-1][y]==0){
        if(backtracking(laberinto, res, make_tuple(x-1,y))){
            return true;
        }
    }
    if(y+1<laberinto[0].size() && laberinto[x][y+1]==1 && res[x][y+1]==0){
        if (backtracking(laberinto, res, make_tuple(x,y+1))){
            return true;
        }
    }

    res[x][y] = 0; //deshacer 
    return false;
}

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

int main() {

    int M, N;

    cin >> M;
    cin >> N;

    // Crear laberinto M x N
    vector<vector<int>> laberinto(M, vector<int>(N));

    // Leer laberinto
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> laberinto[i][j];
        }
    }

    // Matriz resultado inicialmente llena de 0
    vector<vector<int>> res(M, vector<int>(N, 0));

    // Coordenada inicial
    tuple<int,int> inicio = make_tuple(0, 0);

    // Ejecutar backtracking
    backtracking(laberinto, res, inicio);

    cout<<" "<<endl;

    // Imprimir solución
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << res[i][j];

            if (j < N - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}