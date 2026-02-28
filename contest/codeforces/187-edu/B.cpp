#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m, d;
    cin >> n >> m >> d;
    long long x = d / m + 1;
    cout << (n + x - 1) / x << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
