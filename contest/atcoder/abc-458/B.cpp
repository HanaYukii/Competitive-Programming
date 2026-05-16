// Contest default template
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << 0 << "\n";
        return;
    } else if (n == 1 || m == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int idx = (n == 1) ? j : i;
                int len = (n == 1) ? m : n;
                int dis = min(idx + 1, len - idx);
                if (dis == 1) {
                    cout << 1;
                } else {
                    cout << 2;
                }
                cout << " ";
            }
            cout << "\n";
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = min(i + 1, n - i);
            int y = min(j + 1, m - j);
            if (x == 1 && y == 1) {
                cout << 2;
            } else if (x == 1 || y == 1) {
                cout << 3;
            } else {
                cout << 4;
            }
            cout << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
