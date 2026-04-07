#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int pos = 0;
    cin >> pos;
    pos--;
    int cnt1 = 0, cnt2 = 0;
    for (int i = pos; i < n - 1; i++) {
        if (a[i] != a[i + 1]) {
            cnt1++;
        }
    }
    for (int i = pos; i > 0; i--) {
        if (a[i] != a[i - 1]) {
            cnt2++;
        }
    }
    int ans = max(cnt1, cnt2);
    if (ans % 2 == 1) {
        ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
