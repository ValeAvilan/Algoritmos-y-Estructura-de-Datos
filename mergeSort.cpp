#include<iostream>
#include<vector>
using namespace std;

void merge(vector<double>&list, int left, int mid, int right){
    vector<double>temp(right-left+1);

    int i=left;
    int j=mid+1;
    int k=0; //contador para ordenar la lista

    while(i<=mid && j<=right){
        if(list[i]>list[j]){
            temp[k]=list[i];
            i++;
            k++;
        }
        else{
            temp[k]=list[j];
            j++;
            k++;
        }
    }

    while(i<=mid){
        temp[k]=list[i];
        i++;
        k++;
    }

    while(j<=right){
        temp[k]=list[j];
        j++;
        k++;
    }

    for(int x=0; x<temp.size();x++){
        list[x+left]=temp[x];
    }
}

void mergeSort(vector<double>&list, int left, int right){
    if(left>=right){
        return;
    }

    int mid=(right+left)/2;
    mergeSort(list,left,mid);
    mergeSort(list,mid+1,right);
    merge(list,left,mid,right);

}

int main(){
    cout<<"Cantidad de números en el arreglo:"<<endl;
    int n;
    cin>>n;
    vector<double>user(n);

    for(int i=0;i<n;i++){
        cin>>user[i];
    }
    mergeSort(user,0,n-1);
    for(int i=0;i<n;i++){
        cout<<user[i]<<" ";
    }

    return 0;

}