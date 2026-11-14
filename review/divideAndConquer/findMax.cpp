#include<iostream>
#include<vector>
using namespace std;

int findMax(vector<int>&nums, int left, int right){
    if(left>=right){
        return nums[left]; //si hay solo un elemento
    }

    int mid=left+(right-left)/2;
    int l=findMax(nums,left,mid);
    int r=findMax(nums,mid+1,right);
    return max(l,r);
}

int main(){
    vector<int>ej={4,6,1,8,9,10,2};
    int m=findMax(ej,0,ej.size()-1);
    cout<<m;


}