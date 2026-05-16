#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    ll d = abs(x1 - x2);
    d = min(d, n - d);
    if (n <= 3) {
        cout << 1 << "\n";
    } else {
        cout << d + k << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
