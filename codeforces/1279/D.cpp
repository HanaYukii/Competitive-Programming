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
const int mod = 998244353;
ll pm(ll x){
    ll rem = mod - 2;
    ll ret = 1;
    ll now = x;
    while(rem){
        if(rem & 1){
            ret *= now;
            ret %= mod;
        }
        now *= now;
        now %= mod;
        rem >>= 1;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int>v[n];
    unordered_map<int,int>mp;
    f(n){
        int k;
        cin >> k;
        while(k--){
            int add;
            cin >> add;
            mp[add]++;
            v[i].pb(add);
        }
    }
    ll ans = 0;
    f(n){
        ll sum = 0;
        for(auto j:v[i]){
            sum += mp[j];
        }
        sum *= pm(n);
        sum %= mod;
        sum *= pm(v[i].size());
        sum %= mod;
        //cout << sum << '\n';
        ans += sum;
        ans %= mod;
    }
    ans *= pm(n);
    ans %= mod;
    cout << ans << '\n';
}
