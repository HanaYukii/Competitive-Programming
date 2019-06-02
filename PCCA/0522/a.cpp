#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Edge {
    int v, w;
};
const LL INF = 0x3f3f3f3f;
LL solve(vector<vector<Edge> > &G, vector<bool> &vis, vector<int> &choose, int s) {
    int n = (int)vis.size(); LL ret = 0;
    queue<int> q; q.push(s); vis[s] = true; while (q.size()) {
        int p = q.front(); q.pop();
        for (auto &e : G[p]) {
            if (vis[e.v]) {
                if (choose[e.v] + choose[p] != e.w)
                    return INF;
            } else {
                int cnt = e.w - choose[p];
                if (cnt < 0 || cnt > 1)
                    return INF;
                choose[e.v] = cnt;
                ret += cnt;
                q.push(e.v);
                vis[e.v] = true;
            }
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<Edge> > G(n);
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    vector<bool> vis(n, false);
    vector<int> choose(n, 0);
    LL ans = 0;
    for (int i = 0 ; i < n ; i++) {
        if (vis[i])
            continue;
        LL minV = INF;
        choose[i] = 0;
        vector<bool> t_vis = vis;
        minV = min(minV, solve(G, t_vis, choose, i));
        choose[i] = 1;
        t_vis = vis;
        minV = min(minV, solve(G, t_vis, choose, i) + 1);
        queue<int> q; q.push(i); vis[i] = true; while (q.size()) {
            int p = q.front(); q.pop();
            for (auto &e : G[p])
                if (!vis[e.v])
                    vis[e.v] = true, q.push(e.v);
        }
        if (minV == INF) {
            cout << "impossible\n";
            exit(0);
        }
        ans += minV;
    }
    cout << ans << '\n';
}