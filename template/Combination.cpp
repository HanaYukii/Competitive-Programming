// Combinatorics (nCr with modular inverse)
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
const long long mod = 998244353;
long long pre[MAXN];
long long inv[MAXN];
long long prei[MAXN];
void build(int n){
    pre[1] = pre[0] = 1, inv[1] = inv[0] = 1, prei[1] = prei[0] = 1;
    for(int i = 2 ; i <= n ; i++){
        pre[i] = pre[i-1] * i % mod;
        inv[i] = (mod - mod / i * inv[mod % i] % mod) % mod;
        prei[i] = prei[i-1] * inv[i] % mod;
    }
}
long long C(int n, int k){
   return pre[n] * prei[k] % mod * prei[n-k] % mod;
}
long long P(int n, int k) {
    return pre[n] * prei[n - k] % mod;
}
long long catalan(int x) {
    return C(x * 2, x) * inv[x + 1] % mod;
}
long long pm(int n,int p){
    long long ret = 1;
    long long now = n;
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
