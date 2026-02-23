// Contest default template
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
char rev(char c) {
    if (c == 'a') return 'b';
    return 'a';
}
void solve() {
    int n;
    string x;
    cin >> n >> x;

    vector<vector<int>> ok(2, vector<int>(2, 0));
    ok[0][0] = 1;
    char l = 'a';
    char r = 'b';
    if (n % 2 == 1) {
        r = 'a';
    }
    for (int i = 0; i < n; i++ ) {
        vector<vector<int>> nok(2, vector<int>(2, 0));
        for (int lp = 0; lp < 2; lp++) {
            for (int rp = 0; rp < 2; rp++) {
                if (ok[lp][rp] == 0) continue;
                char nl, nr;
                if (lp == 0) {
                    nl = l;
                } else {
                    nl = rev(l);
                }
                if (rp == 0) {
                    nr = r;
                } else {
                    nr = rev(r);
                }
                if (x[i] == '?' || x[i] == nl) {
                    nok[1 - lp][rp] = 1;
                }
                if (x[i] == '?' || x[i] == nr) {
                    nok[lp][1 - rp] = 1;
                }
            }
        }
        ok = nok;
    }

    cout << (ok[0][0] || ok[0][1] || ok[1][0] || ok[1][1] ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
