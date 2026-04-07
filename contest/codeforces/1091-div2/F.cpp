#include <bits/stdc++.h>
using namespace std;

long long digit(int mask, int lim) {
    if (lim < 0) {
        return 0;
    }
    long long res = 0;
    bool flag = 1;
    for (int b = 19; b >= 0; b--) {
        bool m = (mask >> b) & 1;
        bool l = (lim >> b) & 1;
        if (flag && l) {
            int cnt = 0;
            for (int i = b - 1; i >= 0; i--) {
                if (!((mask >> i) & 1)) {
                    cnt++;
                }
            }
            res += 1LL << cnt;
            if (m) {
                flag = 0;
            }
        }
    }
    if (flag) {
        res++;
    }
    return res;
}

void solve() {
    int x1, x2;
    cin >> x1 >> x2;
    if (x1 > x2) {
        cout << x2 + 1 << " " << x1 << "\n";
        return;
    }
    int ans = 0;
    long long mn = 2e18;
    for (int i = 0; i < x1; i++) {
        long long sum = 0;
        if (i < x2) {
            int mx = (x2 - i - 1) / 2;
            sum = digit(i, mx) * (1LL << __builtin_popcount(i));
        }
        if (sum < mn) {
            mn = sum;
            ans = i;
            if (!sum) {
                break;
            }
        }
    }
    cout << ans + 1 << " " << x1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
