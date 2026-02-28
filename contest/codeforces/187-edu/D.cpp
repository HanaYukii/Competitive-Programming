#include <bits/stdc++.h>
using namespace std;

const int MAXV = 2000002;
bool au[MAXV];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> b(m);
    set<int>s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    long long l = 1;
    for (int i : s) {
        l = lcm(l, (long long)i);
        if (l > n + m) { 
            l = -1;
            break;
        }
    }

    vector<int>mul(n + m + 1, 0);
    for (auto &i: s) {
        if (mul[i]) continue;
        for (int j = i; j <= n + m; j += i) {
            mul[j] = 1;
        }
    }

    int A = 0, B = 0, C = 0;
    for (int y : b) {
        if (!mul[y]) {
            B++;
        }   
        else if (l != -1 && y % l == 0) {
            A++;
        } else {
            C++;
        }
    }
    if (A + C % 2 > B) {
        cout << "Alice" << '\n';
    } else {
        cout << "Bob" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
