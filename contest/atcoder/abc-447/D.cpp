// Contest default template
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int a = 0, ab = 0, abc = 0;
    for (char c : s) {
        if (c == 'A') {
            a++;
        } else if (c == 'B') {
            if (a > 0) {
                ab++;
                a--;
            }
        } else if (c == 'C') {
            if (ab > 0) {
                abc++;
                ab--;
            }
        }
    }
    cout << abc << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
