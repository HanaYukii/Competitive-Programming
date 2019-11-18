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
const int mod = 1e9 + 7;
ll pre[5000005];
ll c[5000005];
ll inv[5000005];
ll pinv[5000005];
ll pm(ll x, ll p){
    ll ret = 1;
    ll now = x;
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
    int t;
    cin >> t;
    pre[0] = pre[1] = 1;
    inv[0] = inv[1] = 1;
    pinv[0] = pinv[1] = 1;
    c[0] = 1;
    fr(i,2,5000001){
        pre[i] = pre[i-1] * i % mod;
        inv[i] = (mod - (mod/i) * inv[mod % i] % mod ) % mod;
        pinv[i] = pinv[i-1] * inv[i] % mod;
    }
    f1(5000000){
        ll C = pre[5000000] * pinv[i] % mod * pinv[5000000-i] % mod;
        c[i] = c[i-1] + C;
        c[i] %= mod;
    }
    ll b = pm(2,5000000);
    b = pm(b,mod-2);
    while(t--){
        ll n;
        cin >> n;
        cout << c[5000000-n] * b % mod<< '\n';
    }
}
