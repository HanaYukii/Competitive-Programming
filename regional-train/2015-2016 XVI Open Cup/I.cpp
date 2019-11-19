#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
//#define int long long
const int mod = 1048576;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<ll,int>mp;
    f(1<<20){
        ll cur = i;
        ll hash = 0;
        int t = 38;
        while(t--){
            int x = __builtin_popcountll(cur);
            x %= 2;
            hash <<= 1;
            hash |= x;
            cur *= 487237;
            cur += 1011807;
            cur %= mod;
        }
        mp[hash] = i;
    }
    int t = 38;
    int cur = 160;
    ll hash = 0;
    cin >> cur;
    while(t--){
        cout << 1 << endl;
        int x;
        cin >> x;
        hash <<= 1;
        if(x > cur){
            hash|=1;
        }
        cur = x;
        if(cur == -1){
            exit(0);
        }
    }
    ll ori = mp[hash];
    f(38){
        ori *= 487237;
        ori += 1011807;
        ori %= mod;
    }
    while(1){
        int x = __builtin_popcountll(ori);
        x %= 2;
        if(x){
            cout << 200 - cur << endl;
            int a;
            cin >> a;
            exit(0);
        }
        else{
            cout << 1 << endl;
            cin >> cur;
            if(cur==-1)exit(0);
        }
        ori *= 487237;
        ori += 1011807;
        ori %= mod;
    }
}
