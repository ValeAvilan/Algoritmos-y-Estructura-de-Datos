#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&nums, int inicio, int mid, int fin){
    vector<int>temp(fin-inicio+1);
    int i=inicio;
    int j=mid+1;
    int cont=0;

    while(i<mid+1 && j<=fin){
        if(nums[i]<nums[j]){
            temp[cont]=nums[i];
            i++;
        }
        else{
            temp[cont]=nums[j];
            j++;
        }
        cont++;
    }

    while(i<mid+1){
        temp[cont]=nums[i];
        i++;
        cont++;
    }
    while(j<=fin){
        temp[cont]=nums[j];
        j++;
        cont++;
    }

    for(int x=0; x<temp.size();x++){
        nums[inicio+x]=temp[x];
    }
}

void mergeSort(vector<int>&nums, int inicio, int fin){
    if(inicio>=fin){
        return;
    }

    int mid=inicio+(fin-inicio)/2;
    mergeSort(nums, inicio, mid);
    mergeSort(nums, mid+1, fin);
    merge(nums,inicio, mid, fin);
    
}

int main(){
    vector<int>ej={4,6,1,8,9,10,2};
    mergeSort(ej,0,ej.size()-1);
    for(int i=0; i<ej.size();i++){
        cout<<ej[i]<<" ";
    }

    return 0;
}