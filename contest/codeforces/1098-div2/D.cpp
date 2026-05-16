#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<int> pos;
int get_id(int y) {
    return lower_bound(pos.begin(), pos.end(), y) - pos.begin() + 1;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    pos.clear();
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
        pos.push_back(y);
    }

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    int m = pos.size();
    for (int i = 0; i < n; i++) {
        v[i].second = get_id(v[i].second);
    }
    sort(v.begin(), v.end());

    vector<int> cnt(m + 2, 0);
    for (int i = 0; i < n; i++)
        cnt[v[i].second]++;

    int lmi = m + 1, lmx = 0;
    int rmi = 1, rmx = m;
    while (rmi <= m && cnt[rmi] == 0)
        rmi++;
    while (rmx >= 1 && cnt[rmx] == 0)
        rmx--;

    ll ans = 0;
    int i = 0;
    while (1) {
        int j = i;
        while (j < n && v[j].first == v[i].first) {
            int y = v[j].second;
            lmi = min(lmi, y);
            lmx = max(lmx, y);
            cnt[y]--;
            j++;
        }
        while (rmi <= m && !cnt[rmi]) {
            rmi++;
        }
        while (rmx >= 1 && !cnt[rmx]) {
            rmx--;
        }
        if (j < n) {
            int l = max(lmi, rmi);
            int r = min(lmx, rmx);
            if (r > l)
                ans += r - l;
        }
        i = j;
        if (i >= n)
            break;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
