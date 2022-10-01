#include<bits/stdc++.h>
#include<limits>
using namespace std;

int main(){
    int arr[] = {10,20,30,40};
    int *ptr = arr;
    for(int i=0;i<4;i++){
        cout<<*ptr<<endl;
        ptr++;
        // over here by default array contain array 0th element in it and after ptr ++
        // it moves to the next element of the array. 
    }


    return 0;
}