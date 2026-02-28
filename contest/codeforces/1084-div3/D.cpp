#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n);
    for (auto& i : p) {
        cin >> i;
    }

    vector<int> lr, m;
    for (int i = 0; i < x; i++) {
        lr.push_back(p[i]);
    }
    for (int i = x; i < y; i++) {
        m.push_back(p[i]);
    }
    for (int i = y; i < n; i++) {
        lr.push_back(p[i]);
    }

    if (m.empty()) {
        for (auto &i : p) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    int pos = min_element(m.begin(), m.end()) - m.begin();
    rotate(m.begin(), m.begin() + pos, m.end());
    int k = (int)lr.size();
    for (int i = 0; i < (int)lr.size(); i++) {
        if (lr[i] > m[0]) {
            k = i;
            break;
        }
    }
    for (int i = 0; i < k; i++) {
        cout << lr[i] << ' ';
    }
    for (int i = 0; i < (int)m.size(); i++) {
        cout << m[i] << ' ';
    }
    for (int i = k; i < (int)lr.size(); i++) {
        cout << lr[i] << ' ';
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
