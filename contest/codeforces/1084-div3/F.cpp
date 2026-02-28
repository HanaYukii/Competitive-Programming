#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    vector<int> ya(n), yb(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> ya[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i] >> yb[i];
    }
    vector<vector<long long>> g(n + 1);
    vector<vector<pair<long long,int>>> gb(n + 1);
    for (int i = 0; i < n; i++) {
        g[ya[i]].push_back(a[i]);
    }
    for (int i = 0; i < m; i++) {
        gb[yb[i]].push_back({b[i], i});
    }
    int mx = n + 1;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long ansa = 0, cur = 0;
    int pool = 0;
    vector<long long> ext(mx + 2, -1);
    for (int k = mx; k >= 1; k--) {
        while ((int)pq.size() > k) {
            cur -= pq.top();
            pq.pop();
        }
        for (long long v : g[k - 1]) {
            pool++;
            pq.push(v);
            cur += v;
            if ((int)pq.size() > k) {
                cur -= pq.top();
                pq.pop();
            }
        }
        if ((int)pq.size() == k) {
            ansa = max(ansa, cur);
            ext[k] = cur - pq.top();
        } else if (pool == k - 1) {
            ext[k] = cur;
        }
    }
    vector<long long> ans(m, ansa);
    long long best = -1;
    for (int k = 1; k <= mx; k++) { 
        if (ext[k] >= 0) {
            best = max(best, ext[k]);
        }
        for (auto [val, idx] : gb[k - 1]) {
            if (best >= 0) {
                ans[idx] = max(ans[idx], best + val);
            }
        }
    }
    for (int j = 0; j < m; j++) {
        cout << ans[j] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
