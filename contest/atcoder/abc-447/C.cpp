// Contest default template
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;
    int ans = 0;
    string nas, nat;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            continue;
        } else {
            nas += s[i];
        }
    }
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == 'A') {
            continue;
        } else {
            nat += t[i];
        }
    }
    if (nas != nat) {
        cout << -1 << '\n';
        return;
    }

    vector<int> ps = {-1}, pt = {-1};
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != 'A') {
            ps.push_back(i);
        }
    }
    for (int i = 0; i < (int)t.size(); i++) {
        if (t[i] != 'A') {
            pt.push_back(i);
        }
    }
    ps.push_back(s.size());
    pt.push_back(t.size());

    for (int i = 0; i + 1 < (int)ps.size(); i++) {
        ans += abs((ps[i + 1] - ps[i] - 1) - (pt[i + 1] - pt[i] - 1));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
