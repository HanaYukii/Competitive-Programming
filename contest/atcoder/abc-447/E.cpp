// Contest default template
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int d[200005];

int fi(int x) {
    if (d[x] == x) return x;
    return d[x] = fi(d[x]);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> p2(m+5);
    vector<long long> a(m+5), b(m+5);
    p2[0] = 1;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        d[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }
    long long ans = 0;
    int cc = n; 
    for (int i = m; i >= 1; i--) {
        int A = fi(a[i]), B = fi(b[i]);
        if (A == B) continue;
        if (cc == 2) {
            ans = (ans + p2[i]) % MOD;
        } else {
            d[A] = B;
            cc--;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
