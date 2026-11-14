#include<iostream>
using namespace std;
#include<vector>

int nEsc(int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 2;
    }
    vector<int>dp(n+1);
    dp[0]=1; //opcion de quedarse en ese escalón
    dp[1]=1; //la opcion de quedarse, la opcion de subir 1

    for(int i=2; i<dp.size();i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[dp.size()-1];
}

int main(){
    int n=5;
    int res=nEsc(n);
    cout<<res;
}
