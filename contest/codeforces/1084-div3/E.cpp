#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (is_sorted(a.begin(), a.end())) {
        cout << "Bob\n";
        return;
    }
    vector<int> r;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        r.push_back(x);
        for (int p = 2; (ll)p * p <= x; p++) {
            if (x % p == 0) {
                r.pop_back();
                r.push_back(p);
                while (x % p == 0) {
                    x /= p;
                }
                if (x != 1) {
                    cout << "Alice\n";
                    return;
                }
            }
        }
    }
    if (is_sorted(r.begin(), r.end())) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
