#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i){
	int largest=i;
	int leftindex=2*i;
	int rightindex=2*i+1;
	if(leftindex<=n && arr[largest]<arr[leftindex]){
		largest=leftindex;
	}
	if(rightindex<=n && arr[largest]<arr[rightindex]){
		largest=rightindex;
	}
	if(largest!=i){
		swap(arr[largest],arr[i]);
		heapify(arr,n,largest);
	}
}
void heapsort(int arr[],int n){
	int t=n;
	while(t>1){
		swap(arr[t],arr[1]);
		t--;
		heapify(arr,t,0);
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=n/2;i>0;i--){
		heapify(arr,n,i);
	}
	heapsort(arr,n);
	for(int i=1;i<=n;i++){
		cout<<arr[i];
	}
}
