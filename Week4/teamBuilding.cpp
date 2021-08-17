#include <bits/stdc++.h>
#include<iostream>
 
#define pb push_back
#define ll long long int
#define mod 998244353
#define rep(i, n) for(i=0;i<n;i++)
#define repr(i, n) for(i=n;i>=0;i--)
#define repi(i, x, n) for(i=x;i<=n;i++)
using namespace std;
 
ll power(ll x, ll n){
    ll res=1;
    while(n){
        if(n & 1){
            res = (1LL * res*x)%mod;
        }
        x = (x*x*1LL)%mod;
        n = n >> 1;
    }
    return res%mod;
}
 
ll fact(ll n){
    if(n==1||n==0){
        return 1;
    }
    return (1LL * n * fact(n-1)%mod);
}
 
ll C(ll n, ll r){
 
    return ( 1LL * fact(n)%mod *  power( (fact(r) * fact(n-r)), mod -2 )%mod )% mod;
}
 
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
 
vector<int> v;
vector<vector<int>> graph(100001, v);
bool visited[100001] = {0};
int res[100001];
 
bool dfs(int i, bool b){
    visited[i]=1;
    if(b) res[i]=2;
    else res[i]=1;
    bool ans=1;
    //cout<<i<<" ";
    for(int j : graph[i]){
        if(!visited[j]){
            ans = ans && dfs(j, !b);
        }
    else if(res[i] == res[j] ){
        ans=false;
    }
    }
    return ans;
}
 
void solve()
{
    int n, m, i, x, y;
    cin>>n>>m;
    rep(i, m){
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    bool ans = 1;
    repi(i, 1, n){
        if(!visited[i]) {
            ans = ans && dfs(i, 0);
        }
    }
    if(ans) repi(i, 1, n) cout<<res[i]<<" ";
    else cout<<"IMPOSSIBLE"<<endl;
}
int main()
{
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
