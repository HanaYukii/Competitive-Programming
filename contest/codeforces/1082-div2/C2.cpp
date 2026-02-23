#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto is_root_at = [&](int l, int i) -> bool {
        if (l == i) return true;
        int lo = a[l], hi2 = a[l];
        for (int j = l + 1; j <= i; j++) {
            if (a[j] <= hi2 + 1 && a[j] >= lo + 1 && a[j] <= a[j-1] + 1) {
                hi2 = max(hi2, a[j]);
            } else {
                lo = hi2 = a[j];
                if (j == i) return true;
            }
        }
        return false;
    };

    long long total = 0;
    for (int i = 0; i < n; i++) {
        int th = i;
        for (int l = i - 1; l >= 0; l--) {
            if (is_root_at(l, i))
                th = l;
            else
                break;
        }
        total += (long long)(i - th + 1) * (n - i);
    }
    cout << total << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
