#include<iostream>
using namespace std;

//definir funciones fuera del main
int suma(int a, int b) {
        return a + b;
}

bool palindrom(string s){
    if (s.size()==0){
        return true;
    }

    int i=0;
    int j=s.size()-1;

    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    //tipos de datos
    int x=5;
    string name="Valeria";
    string palin="oso";
    double price=8.19;
    bool found=true;
    char letter='a';

    cout<<"El número es: "<<x<<endl;

    //condicional if
    if(x<10){
        cout<<"Número menor que 10"<<endl;
    }
    else if(x==10){
        cout<<"Número igual a 10"<<endl;
    }
    else{
        cout<<"Número mayor que 10"<<endl;
    }

    //ciclo for (incio, fin, paso)
    for(int i=0; i<10; i++){
        cout<<"El índice es: "<<i<<endl;
    }
    cout<<" "<<endl;

    cout<<"Imprimir un arreglo"<<endl;
    vector<int> nums={1,2,4,6,2};
    for(int x=0; x<nums.size() ;x++){
        cout<<nums[x]<<endl;
    }
    cout<<" "<<endl;
    cout<<"Imprimir un arreglo 2"<<endl;
    for(int num:nums){
        cout<<num<<endl;
    }
    cout<<" "<<endl;

    for(char c:name){
        cout<<c<<endl;
    }
    cout<<" "<<endl;

    //ciclo while + two pointers
    vector<int>twoPointers={1,2,3,4,5,6};
    int i=0;
    int j=twoPointers.size()-1;

    while(j>i){
        cout<<twoPointers[i]<<endl;
        cout<<twoPointers[j]<<endl;
        i++;
        j--;
    }

    //llamar a función
    cout<<"La suma de "<<5<<"y "<<3<<" es: "<<suma(5,3)<<endl;
    cout<<"La palabra "<<palin<<" es palindromo?: "<<palindrom(palin)<<endl;
    cout<<"La palabra "<<name<<" es palindromo?: "<<palindrom(name)<<endl;

    vector<int>n={4,7,2,9};
    n.push_back(10); //agregar
    for(int i=0; i<n.size();i++){
        if(n[i]>5){
            cout<<n[i]<<endl;
        }
    }
    cout<<"El primer elemento del arreglo es: "<<n.front()<<endl;
    cout<<"El último elemento del arreglo es: "<<n.back()<<endl;
    n.pop_back(); //eliminar
    cout<<"El último elemento del arreglo es: "<<n.back()<<endl;

    string palabra = "algorithm";
    int cont=0;
    for (char c: palabra){
        if(c=='a'){
            cont++;
        }
    }
    cout<<"la letra a aparece"<<cont<<"veces"<<endl;
    return 0;
}