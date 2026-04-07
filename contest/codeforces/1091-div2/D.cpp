#include <bits/stdc++.h>
using namespace std;
int a[200005], p[200005];
int b[200005];
int cnt[200005];
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> p[i];
    }

    for (int i = 0; i <= k; i++) {
        cnt[i] = 0;
    }
    b[0] = b[n+1] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[p[1]]) {
            b[i] = 1;
        } else {
            b[i] = 0;
        }
    }
    int gp = 0;
    int ptr = 1;
    for (int i = 0; i <= n; i++) {
        while (ptr <= k && p[ptr] <= i) {
            gp++;
            ptr++;
        }
        if (b[i] != b[i + 1]) {
            cnt[gp]++;
        }
    }

    int sum = 0, mx = 0;
    for (int i = 0; i <= k; i++) {
        sum += cnt[i];
        mx = max(mx, cnt[i]);
    }
    cout << max(sum / 2, mx) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
