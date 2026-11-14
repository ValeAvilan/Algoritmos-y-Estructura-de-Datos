#include<iostream>
#include<string>
using namespace std;

void backBinario(string &res, int n){
    if(res.size()==n){
        cout<<res<<" ";
        return;
    }

    res.push_back('0'); //agrergar 0
    backBinario(res,n); //llamada a funcion recursiva
    res.pop_back(); //eliminar 0

    res.push_back('1');
    backBinario(res,n);
    res.pop_back();

    return;
}


int main(){
    int n;
    string res="";
    cout<<"ingresa n"<<endl;
    cin>>n;

    backBinario(res,n);
    return 0;
}
