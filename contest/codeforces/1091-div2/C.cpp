#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    if (__gcd(a, n) != 1 || __gcd(b, m) != 1) {
        cout << "NO" << '\n';
        return;
    }
    if (__gcd(n, m) > 2) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
