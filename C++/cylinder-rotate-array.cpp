#include<bits/stdc++.h>
#include<limits>
#include<String>
using namespace std;

int main(){
    int count;
    cin>>count;
    int arr[count];
    for (int i = 0; i < count; i++)
    {
        cin>>arr[i];
    }
    int temp=arr[count-1];
    for (int i = count-1;i>0; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
    for (int i = 0; i < count; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    


    return 0;
}