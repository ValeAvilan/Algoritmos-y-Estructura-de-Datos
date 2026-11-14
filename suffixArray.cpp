#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void suffix(string cadena, vector<string>&res){
    if(cadena.size() == 0){
        return;
    }

    string seen = "";
    for(int i = cadena.size() - 1; i >= 0; i--){
        seen = cadena[i] + seen;
        res.push_back(seen);
    }

    sort(res.begin(), res.end());
}

int main(){
    vector<string>res;
    string cadena;
    cout<<"Introduce una cadena: ";
    cin>>cadena;

    suffix(cadena, res);

    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<endl;
    } 


    return 0;
}