#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int MAXN = 1e6+5;
const int mul = 9997;
long long h[MAXN];
long long p[MAXN];
string s;
vector<int>Z() {
    int L = 0, R = 0;
    vector<int>z(s.size());
    z[0] = s.size();
    for (int i = 1 ; i < s.size() ; i++) {
        if (i <= R) {
            z[i] = z[i - L];
        }
        else {
            L = i;
            if (i > R) {
                R = i;
            }
            while (R < z[0] && s[R - L] == s[R]) R++;
            z[i] = (R--) - L;
        }
    }
    return z;
}
void go() {
    int n, k;
    cin >> n >> k;
    cin >> s;
    auto z = Z();
    int f = 1;
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        int pos;
        cin >> pos;
        cnt += max(0,pos - f);
        //cout << pos - f << endl;
        if (pos - f < 0 && z[z.size()-f+pos] < f - pos) {
            //cout << pos <<' '<<f<<' '<<z.size()-f+pos<<endl;
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