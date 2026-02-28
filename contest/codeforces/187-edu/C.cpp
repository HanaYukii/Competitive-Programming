#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long s, m;
    cin >> s >> m;

    vector<int> b;
    for (int i = 0; i < 60; i++) {
        if (m & (1LL << i)) {
            b.push_back(i);
        }
    }

    int k = b.size();
    long long low = (1LL << b[0]);
    if (s % low) {
        cout << -1 << '\n';
        return;
    }


    long long l = 0, r = (s / (1LL << b[0])) + 1;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        vector<long long>d(64, 0);
        bool ok = true;
        for (int i = 0; i < k; i++) {
            d[b[i]] = mid;
        }
        for (int i = 0; i < 62; i++) {
            int u = 0;
            if ((1LL << i) & s) {
                u = 1;
                if (!d[i]) {
                    ok = false;
                    break;
                }
            }
            long long extra = (d[i] - u) / 2;
            d[i + 1] += extra;
        }
        if (ok) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
