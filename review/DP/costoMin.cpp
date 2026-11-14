#include<iostream>
using namespace std;
#include<vector>

int costo(vector<int>escalon){
    vector<int>dp(escalon.size()+1);
    dp[0]=0;
    dp[1]=0;

    for(int i=0;i<escalon.size();i++){
        dp[i]=min(dp[i-1]+escalon[i-1],dp[i-2]+escalon[i-1]);
    }

    return dp[escalon.size()-1];

}



int main(){
    return 0;
}