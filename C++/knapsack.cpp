#include <bits/stdc++.h>
using namespace std;
int knapsack(int n,int W,int v[],int w[])
{
    int dp[n+1][W+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            dp[i][j]=-1;
        }
    }

    if(n<=0||W<=0)
    {
        return 0;
    }
    if(w[n-1]>W)
    {
        dp[n][W]= knapsack(n-1,W,v,w);
    }
    else
    dp[n][W]= max(knapsack(n-1,W,v,w),knapsack(n-1,W-w[n-1],v,w)+v[n-1]);
    return dp[n][W];
}
int main()
{
    int n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int w[n];
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    int W;
    cin>>W;
    cout<<knapsack(n,W,v,w);
}
