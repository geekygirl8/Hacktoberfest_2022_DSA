#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r){
    int i=l,j=m+1,k=0;
    int temp[r-l+1];
    while(i<=m && j<=r){
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }
    while(i<=m) temp[k++]=arr[i++];
    while(j<=r) temp[k++]=arr[j++];
    for(int i=0;i<k;i++) arr[i+l]=temp[i];
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}


int main(){
    int arr[]={2,5,6,-1,0,2,4,5,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}