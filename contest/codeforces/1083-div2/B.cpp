#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long ans = 1;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            ans *= p;
            while (n % p == 0) {
                n /= p;
            }
        }
    }
    if (n > 1) {
        ans *= n;
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
