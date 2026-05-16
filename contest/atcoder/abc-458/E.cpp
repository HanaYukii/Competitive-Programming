// Contest default template
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MAXN = 3000005;
const long long mod = 998244353;
long long pre[MAXN];
long long inv[MAXN];
long long prei[MAXN];
void build(int n) {
    pre[1] = pre[0] = 1, inv[1] = inv[0] = 1, prei[1] = prei[0] = 1;
    for (int i = 2; i <= n; i++) {
        pre[i] = pre[i - 1] * i % mod;
        inv[i] = (mod - mod / i * inv[mod % i] % mod) % mod;
        prei[i] = prei[i - 1] * inv[i] % mod;
    }
}
long long C(int n, int k) {
    return pre[n] * prei[k] % mod * prei[n - k] % mod;
}
long long P(int n, int k) {
    return pre[n] * prei[n - k] % mod;
}
long long catalan(int x) {
    return C(x * 2, x) * inv[x + 1] % mod;
}
long long pm(int n, int p) {
    long long ret = 1;
    long long now = n;
    while (p) {
        if (p & 1) {
            ret *= now;
            ret %= mod;
        }
        now *= now;
        now %= mod;
        p >>= 1;
    }
    return ret;
}

void solve() {
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    build(x1 + x2 + x3 + 5);
    ll ans = 0;
    int mi = min(x1, x2);
    for (int k = 1; k <= mi; k++) {
        ll add = C(x2 + 1, k) * C(x1 - 1, k - 1) % mod * C(x2 + x3 - k, x3) % mod;
        ans += add;
        ans %= mod;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
