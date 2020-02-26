#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define pll pair<ll,ll>
#define pii pair<int,int>
#define F first
#define S second
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
ll mul = 31;
ll h[maxn];
ll p[maxn];
 
void build(string s){
    ll cur = 0;
    ll now = mul;
    p[0] = 1;
    f1((int)s.size()){
        p[i] = now;
        now *= mul;
        now %= mod;
    }
    for(int i = 1 ; i <= (int)s.size() ; i ++){
        cur *= mul;
        cur += (int)s[i-1];
        cur %= mod;
        h[i] = cur;
    }
}
ll get(int l,int r){
    ll ret = (h[r] - (h[l-1] * p[r - l + 1] % mod) + mod) % mod;
    return ret;
}
