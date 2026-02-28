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
    for (int i = 0; i < n; i++) {
        if (a[i] == n) {
            swap(a[i], a[0]);
        }
    }
    for (auto &i: a) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
