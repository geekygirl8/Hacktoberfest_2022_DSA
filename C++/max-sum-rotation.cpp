#include<bits/stdc++.h>
#include<limits>
#include<String>
using namespace std;
int maxsum(int arr[],int count){
    int result=0;
    for (int i = 0; i < count; i++)
    {
        int curr_sum=0;
        for (int j = 0; j < count; j++)
        {
            int  index = (i+j)%count;
            curr_sum += j*arr[index];
        }
        result = max(result,curr_sum);
    }
    return result;
    
}
int main(){
    int count;
    cin>>count;
    int arr[count];
    for (int i = 0; i < count; i++)
    {
        cin>>arr[i];
    }
    cout<<maxsum(arr,count);


    return 0;
}