#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>

void change(vector<int>coins, int cambio, vector<int>&res){
    sort(coins.begin(),coins.end()); //menor a mayor
    int restante=cambio;
    int index=coins.size()-1; //ultimo index de coins 

    while (index>=0 && restante>0){
        if(coins[index]<=restante){
            res.push_back(coins[index]);
            restante-=coins[index];
        }
        else{
            index--;
        }
    }
    return;
}

int main(){
    int c=119;
    vector<int>deno={1,50,4,100,20,5,10};
    vector<int>res={};
    change(deno, c, res);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

    return 0;
}