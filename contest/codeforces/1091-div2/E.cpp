#include <bits/stdc++.h>
using namespace std;

int p[5005], d[5005], pos[5005];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = i + 1; j < n; j++) {
            if (p[j] > p[i]) {
                c++;
            }
        }
        if (d[i] > c) {
            cout << -1 << '\n';
            return;
        }
    }
    vector<int> res;
    for (int i = n; i >= 1; i--) {
        int idx = pos[i];
        int cnt = 0, tar = -1;
        for (int j = res.size(); j >= 0; j--) {
            if (cnt == d[idx]) {
                tar = j;
                break;
            }
            if (j > 0 && res[j - 1] > idx) {
                cnt++;
            }
        }
        if (tar < 0) {
            cout << -1 << '\n';
            return;
        }
        res.insert(res.begin() + tar, idx);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[res[i]] = i + 1;
    }
    for (auto &i: ans) {
        cout << i << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
