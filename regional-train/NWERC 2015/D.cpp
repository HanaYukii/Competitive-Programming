#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
ll n, r, p;
ll dp[1000005];
ll solve(ll x){
    if(~dp[x]){
        return dp[x];
    }
    if(x<=1){
        return dp[x] = 0;
    }
    ll mi = 1e18;
    for(ll i=1;i<x;i++){
        ll sep = i + 1;
        ll base = i * p + r;
        ll left = x/sep + ((x%sep)>0);
        mi = min(mi,solve(left)+base);
    }
    return dp[x] = mi;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r >> p;
    memset(dp,-1,sizeof(dp));
    cout << solve(n) << endl;
}
