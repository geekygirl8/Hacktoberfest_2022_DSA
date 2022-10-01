#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int key;
	cin>>key;
	int arr[n][m];
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			
		}
	}
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==key){
				cout<<i<<","<<j;
			}
			
		}
	}
	return 0;
}
