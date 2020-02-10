#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 2000015
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define F first
#define S second
const ll mod = 1e9+7;
ll pre[maxn];
ll inv[maxn];
ll prei[maxn];
void build(int n){
    pre[1] = pre[0] = 1, inv[1] = inv[0] = 1, prei[1] = prei[0] = 1;
    for(int i = 2 ; i <= n ; i++){
        pre[i] = pre[i-1] * i % mod;
        inv[i] = (mod - mod / i * inv[mod % i] % mod) % mod;
        prei[i] = prei[i-1] * inv[i] % mod;
    }
}
ll C(int n, int k){
   return pre[n] * prei[k] % mod * prei[n-k] % mod;
}
ll pm(int n,int p){
    ll ret = 1;
    ll now = n;
    while(p){
        if(p & 1){
            ret *= now;
            ret %= mod;
        }
        now *= now;
        now %= mod;
        p >>= 1;
    }
    return ret;
}
ll solve(ll x,ll y){
    if(x==0||y==0)return 0;
    ll ret = 0;
    for(int i = 1 ; i <= y ; i++){
        ret += C(x+i+1,x);
        ret += mod - 1;
        ret %= mod;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    build(2000005);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << ((solve(x2,y2)-solve(x1-1,y2)-solve(x2,y1-1) + solve(x1-1,y1-1))%mod + mod) % mod;
}
