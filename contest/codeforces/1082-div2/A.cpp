// Contest default template
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    long long x, y;
    cin >> x >> y;
    long long del = x - 2 * y;
    if (del >= 0 && del % 3 == 0 && x + y * 4 >= 0) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
