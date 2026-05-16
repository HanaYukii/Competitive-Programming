// Contest default template
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MOD = 1e9 + 7;

void solve() {
    int x, q;
    cin >> x >> q;
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
    small.push(x);
    auto add = [&](int v) {
        if (small.empty() || v <= small.top()) {
            small.push(v);
        } else
            big.push(v);
        while (small.size() > big.size() + 1) {
            big.push(small.top());
            small.pop();
        }
        while (big.size() > small.size()) {
            small.push(big.top());
            big.pop();
        }
    };
    while (q--) {
        int a, b;
        cin >> a >> b;
        add(a);
        add(b);
        cout << small.top() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
