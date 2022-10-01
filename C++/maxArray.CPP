#include<bits/stdc++.h>
#include<stdio.h>
#include<limits>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int max1=INT_MIN;

	for(int i=0;i<n;i++){
		max1=max(max1,arr[i]);
		cout<<max1<<" ";
	}
  return 0;

}
