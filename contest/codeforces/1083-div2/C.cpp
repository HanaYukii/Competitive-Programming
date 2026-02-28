#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vector<int> tmp;
        for (int j = 0; j < l; j++) {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        v.push_back(tmp);
    }
    set<int> seen;
    vector<bool> used(n);
    vector<int> ans;
    int cnt = n;
    while (cnt--) {
        int mx = -1;
        vector<int> add;
        for (int i = 0; i < n; i++) {
            if (used[i]) {
                continue;
            }
            vector<int> seq;
            set<int> cur;
            for (int j = (int)v[i].size() - 1; j >= 0; j--) {
                int x = v[i][j];
                if (!seen.count(x) && !cur.count(x)) {
                    seq.push_back(x);
                    cur.insert(x);
                }
            }
            if (mx == -1 || seq < add) {
                mx = i;
                add = seq;
            }
        }
        used[mx] = true;
        for (int i : add) {
            ans.push_back(i);
        }
        for (int i : v[mx]) {
            seen.insert(i);
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
