// Combinatorics (nCr with modular inverse)
#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define F first
#define S second
const ll mod = 998244353;
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
ll P(int n, int k) {
    return pre[n] * prei[n - k] % mod;
}
ll catalan(int x) {
    return C(x * 2, x) * inv[x + 1] % mod;
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    build(n); // needed n!
    int x, y;
    cin >> x >> y;
    cout << C(x, y) << '\n'; // C
    cout << P(x, y) << '\n'; // P
    cout << catalan(x) << '\n'; // catalan
    cout << pm(x, y) << '\n'; // x^y % mod
}
