#include<iostream>
using namespace std;
#include<vector>

int robber(vector<int>&coins){
    vector<int>dp(coins.size()+1);
    dp[0]=0;
    dp[1]=coins[0]; //5,1,

    for(int i=2; i<dp.size();i++){
        dp[i]=max(dp[i-2]+coins[i-1],dp[i-1]);
    }
    return dp[dp.size()-1];
}

int main(){
    vector<int>coins={5, 1, 2, 10, 6};
    int r=robber(coins);
    cout<<r<<endl;

    return 0;
}