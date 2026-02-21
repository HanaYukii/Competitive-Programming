#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int MAXN = 1e6+5;
const int mul = 9997;
long long h[MAXN];
long long p[MAXN];
string s;
void build() {
    for (int i = 0 ; i < s.size() ; i++) {
        h[i + 1] = (h[i] * mul + s[i]) % mod;
    }
    p[0] = 1;
    for (int i = 1; i <= s.size(); i++) {
        p[i] = p[i - 1] * mul % mod;
    }
}
long long query(int l,int r) {
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
    for (int i = 0; i < k; i++) {
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
    long long ans = 1;
    for (int i = 0; i < cnt; i++) {
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