// Name: Dhruv Arora
// Github id: lord-benjamin
// Problem Link: https://codeforces.com/contest/1735/problem/A

#include <bits/stdc++.h>
 
#define loop(var,init,limit)   for(ll var{init}; var<limit; ++var)
#define ll long long
#define ld long double
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define mpi map<int,int>
#define mpl map<ll,ll>
#define sti set<int>
#define stl set<ll>
#define all(v) v.begin(),v.end()
#define input(a,n)            \
    for(ll i{0}; i<n; ++i){ \
        ll num;             \
        cin>>num;           \
        a.pb(num);          \
    }
#define output(a)           \
    for(auto val : a) \
        cout<<val<<" ";
#define nl  cout<<"\n"
#define yes  cout<<"Yes"<<endl
#define no  cout<<"No"<<endl
#define print(x)  cout<<x<<endl
 
using namespace std;
 
int main()
{
    ll t{};
    cin >> t;
    while(t--){
        ll n{};
        cin >> n;
        print((n/3)-2);
    }
    return 0;
}
