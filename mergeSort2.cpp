#include<iostream>
using namespace std;

vector<int> merge(vector<int>left,vector<int>right){
    vector<int>res={}; //arreglo para guardar nums
    int i=0;
    int j=0;
    while(left.size()>i && right.size()>j){
        if(left[i]>right[j]){
            res.push_back(left[i]);
            i++;
        }
        else{
            res.push_back(right[j]);
            j++;
        }
    }
    while(i<left.size()){
        res.push_back(left[i]);
        i++;
    }
    while(j<right.size()){
        res.push_back(right [j]);
        j++;
    }
    return res;
}

vector<int> mergeSort(vector<int>nums){
    int size=nums.size();
    if(size==0){
        return nums;
    }
    if(size==1){
        return nums;
    }

    int mid=size/2;
    vector<int>left(mid);
    vector<int>right(size-mid);

    for(int i = 0; i < mid; i++){
        left[i] = nums[i];
    }

    for(int i = mid; i < size; i++){
        right[i-mid] = nums[i];
    }
    vector<int>l=mergeSort(left);
    vector<int>r=mergeSort(right);
    vector<int>result=merge(l,r);
    return result;
}

int main(){

    vector<int>p={5,2,6,10,59,10,35};
    vector<int> result = mergeSort(p);
    for(int n:result){
        cout<<n<<endl;
    }
    return 0;
}