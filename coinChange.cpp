#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void ChangeDP(int cambio, const vector<int>&monedas, vector<int>&resDP){
    int size=cambio+1;
    vector<int>d(size,size); //guarda cantidad min de monedas en cada i del cambio
    vector<int> eleccion(size, -1); //guarda indices de las monedas que se usaron
    d[0]=0;

    for(int i=1; i<=cambio; i++){
        for(int j=0; j<monedas.size(); j++){
            
            if(i >= monedas[j]){
                int falt=i-monedas[j];

                if (d[i]>d[falt]+1){ //cuando j es la mejor moneda
                    d[i]=d[falt]+1;
                    eleccion[i]=j;    
                }
            }
        }  
    }

    int falt=cambio;
    while (falt>0){
        resDP[eleccion[falt]]++;
        falt=falt-monedas[eleccion[falt]];
    }
}

void ChangeAvaro(int cambio, const vector<int>&monedas, vector<int>&resAvaro){
    int n=monedas.size();
    int remaining=cambio;

    for(int i=n-1; i>=0; i--){
        if(monedas[i]<=remaining){
            resAvaro[i]=remaining/monedas[i];
            remaining= remaining % monedas[i];
        }
    }
}

int main(){
    int n; //cantidad de monedad
    cout<<"Introduce la cantidad de monedas o billetes: ";
    cin>>n;

    vector<int>resDP(n,0);
    vector<int>resAvaro(n,0);
    vector<int>monedas(n); //arrglo con las diferentes denominaciones
    for (int i=0; i<n; i++){
        cout<<"Introduce las denominaciones: ";
        cin>>monedas[i];
    }
    sort(monedas.begin(),monedas.end());

    int p; //precio del producto dado
    cout<<"Introduce el precio del producto: ";
    cin>>p;

    int q; //pago del producto
    cout<<"Introduce la moneda o billete con la que pagaste el producto: ";
    cin>>q;

    int cambio= q-p;

    ChangeDP(cambio, monedas, resDP);
    ChangeAvaro(cambio, monedas,resAvaro);

    for(int x = resDP.size() - 1; x >= 0; x--){
        cout << resDP[x] << endl;
    }
    cout<<" "<<endl;

    for(int x = resAvaro.size() - 1; x >= 0; x--){
        cout << resAvaro[x] << endl;
    }


    return 0;
}