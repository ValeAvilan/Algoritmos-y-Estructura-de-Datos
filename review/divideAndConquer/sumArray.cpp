#include<iostream>
#include<vector>
using namespace std;

int sumArr(vector<int>&a, int left, int right){
    if(left==right){
        return a[left];
    }
    int mid=left+(right-left)/2;
    int l=sumArr(a,left,mid);
    int r=sumArr(a,mid+1, right);
    return l+r;
}
int main(){
    vector<int>ej={3, 7, 2, 8, 4};
    int s=sumArr(ej,0,ej.size()-1);
    cout<<s;
    
    return 0;
}