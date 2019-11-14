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
const int mod = 1e9+7;
int n;
ll pre[5000];
ll pm(int x,int p){
    ll ret = 1;
    ll cur = x;
    while(p){
        if(p&1){
            ret *= cur;
            ret %= mod;
        }
        cur *= cur;
        cur %= mod;
        p >>= 1;
    }
    return ret;
}
ll C(int n,int k){
    ll ret = 1;
    ret *= pre[n];
    ret *= pm(pre[k],mod-2);
    ret %= mod;
    ret *= pm(pre[n-k],mod-2);
    ret %= mod;
    return ret;
}
ll cal(int x){
    ll ret = x;
    f(n-1){
        ret *= x - 1;
        ret %= mod;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n >> m;
    pre[0] = 1;
    f1(m){
        pre[i] = pre[i-1] * i % mod;
    }
    f(n-1){
        int tr;
        cin >> tr;
    }
    int pl = 1;
    ll ans = 0;
    for(int i=m;i>=1;i--){
        ll cur = cal(i);
        cur *= C(m,i);
        cur %= mod;
        ans += cur * pl;
        ans += mod;
        ans %= mod;
        pl *= -1;
    }
    cout << ans << endl;
}
