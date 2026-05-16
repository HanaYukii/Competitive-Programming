// Contest default template
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'C') {
            int dis = min(i, (int)s.size() - 1 - i);
            ans += dis + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
