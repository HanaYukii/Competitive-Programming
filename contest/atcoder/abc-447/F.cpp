// Contest default template
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int dp[200005];
vector<int> g[200005];
int deg[200005];
int ans;

void dfs(int now, int pre) {
    int mx1 = 0, mx2 = 0;
    for (int i : g[now]) {
        if (i == pre) {
            continue;
        }
        dfs(i, now);
        int v = dp[i];
        if (v > mx1) {
            mx2 = mx1;
            mx1 = v;
        } else if (v > mx2) {
            mx2 = v;
        }
    }
    if (deg[now] >= 4) {
        dp[now] = 1 + mx1;
    } else if (deg[now] >= 3) {
        dp[now] = 1;
    } else {
        dp[now] = 0;
    }
    if (deg[now] >= 2) {
        ans = max(ans, 1);
    }
    if (deg[now] >= 3) {
        ans = max(ans, 1 + mx1);
    }
    if (deg[now] >= 4 && mx2 > 0) {
        ans = max(ans, mx1 + mx2 + 1);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        deg[i] = 0;
        dp[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    ans = 0;
    dfs(1, 0);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
