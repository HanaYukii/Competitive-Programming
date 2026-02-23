// Contest default template
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k < n || k > 2 * n - 1) {
        cout << "NO\n";
        return;
    }
    vector<int> ans;
    cout << "YES\n";
    int d = k - n;
    if (d == 0) {
        for (int i = 1; i <= n; i++) {
            ans.push_back(i);
            ans.push_back(i);
        }
    } else {
        ans.push_back(1);
        ans.push_back(2);
        for (int i = 1; i <= d - 1; i++) {
            ans.push_back(i + 2);
            ans.push_back(i);
        }
        ans.push_back(d);
        ans.push_back(d + 1);
        for (int i = d + 2; i <= n; i++) {
            ans.push_back(i);
            ans.push_back(i);
        }
    }
    for (auto &i: ans) {
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
