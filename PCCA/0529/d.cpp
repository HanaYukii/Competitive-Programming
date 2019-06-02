#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> data(n);
    map<int, int> cnt;
    for (auto &v : data) {
        cin >> v;
        cnt[v]++;
    }
    for (auto &p : cnt) {
        if (p.second == n) {
            cout << 0 << '\n';
            return 0;
        }
    }
    int q; cin >> q; for (int i = 0 ; i < q ; i++) {
        int x, v; cin >> x >> v; x--;
        cnt[v]++, cnt[data[x]]--;
        data[x] = v;
        if (cnt[v] == n) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    
}