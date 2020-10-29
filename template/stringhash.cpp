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
ll mul = 114115;
ll h[maxn];
ll p[maxn];
 
void build(string s){
    ll cur = 0;
    ll now = mul;
    p[0] = 1;
    for (int i = 1 ; i <= s.size() ; i++){
        p[i] = now;
        now *= mul;
        now %= mod;
    }
    for (int i = 1 ; i <= (int)s.size() ; i ++){
        cur *= mul;
        cur += s[i-1];
        cur %= mod;
        h[i] = cur;
    }
}
ll query(int l,int r){
    ll ret = (h[r] - (h[l-1] * p[r - l + 1] % mod) + mod) % mod;
    return ret;
}

int main() {
    // string hash
    string s;
    cin >> s;
    build(s);
    s = " " + s;
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    // string 1-based 
    if (query(l1, r1) == query(l2, r2)) {
        cout << "SAME\n";
    }
    else {
        cout << "DIFFERENT\n";
    }
}