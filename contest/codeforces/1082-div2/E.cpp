#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    long long sum = 0, p2 = 1;
    long long left = 0, right = 0;
    long long pre = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            pre++;
        } else {
            pre--;
        }
        if (s[i] == '(') {
            sum = (sum + p2) % MOD;
            if (pre < 2) {
                left = 0;
            } else {
                left = (1 + right + 2 * left) % MOD;
            }
        } else {
            right = (1 + left + 2 * right) % MOD;
            if (pre < 2) {
                left = 0;
            }
        }
        p2 <<= 1;
        p2 %= MOD;
    }
    sum += right;
    sum %= MOD;
    cout << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
