// Contest default template
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = a[0], r = a[0];
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] <= r + 1 && a[i] >= l + 1 && a[i] <= a[i-1] + 1) {
            r = max(r, a[i]);
        }
        else {
            l = r = a[i];
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}