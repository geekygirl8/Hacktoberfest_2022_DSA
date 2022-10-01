#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
    int arr[10]={2,4,5,7,9,12},i,x,n;
    cout<<"Enter what yo want to insert:";
    cin>>x;
    cout<<"Enter the index where u want to insert:";
    cin>>n;

    for ( i = 6; i >=n; i--)
        arr[i]=arr[i-1],
    arr[n]=x;
    for(i=0;i<=7;i++)
    cout<<arr[i]<<endl;
    
    return 0;
    

}
