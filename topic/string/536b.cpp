#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const ll mod = 1e9 + 7;
const int maxn = 1e6+5;
const int mul = 9997;
ll h[maxn];
ll p[maxn];
string s;
void build() {
    for (int i = 0 ; i < s.size() ; i++) {
        h[i + 1] = (h[i] * mul + s[i]) % mod;
    }
    p[0] = 1;
    f1(s.size()) {
        p[i] = p[i - 1] * mul % mod;
    }
}
ll query(int l,int r) {
    //cout << l <<' '<<r<<endl;
    return ((h[r] - h[l - 1] * p[r - l + 1] % mod) + mod) % mod;
}
void go() {
    int n, k;
    cin >> n >> k;
    cin >> s;
    build();
    int f = 1;
    int cnt = 0;
    f (k) {
        int pos;
        cin >> pos;
        cnt += max(0,pos - f);
        //cout << pos - f << endl;
        if (pos - f < 0 && (query(1,f - pos) != query(s.size() - (f - pos) + 1, s.size()))) {
            cout << 0 << '\n';
            return;
        }
        f = pos + s.size();
        //cout << cnt << endl; 
    }
    cnt += n + 1 - f;
    //cout << cnt << endl;
    ll ans = 1;
    f(cnt) {
        ans *= 26;
        ans %= mod;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
    
}