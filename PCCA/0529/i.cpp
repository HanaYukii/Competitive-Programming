#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<pii> edges(m);
    vector<vector<int> > G(n, vector<int>(n, 1));
    for (auto &p : edges) {
        cin >> p.F >> p.S;
        p.F--, p.S--;
        G[p.F][p.S] = G[p.S][p.F] = 0;
    }
    for (int i = 0 ; i < n ; i++)
        G[i][i] = 0;
    vector<int> color(n, -1); int stamp = 0;
    for (int i = 0 ; i < n ; i++) {
        if (color[i] != -1)
            continue;
        stamp++;
        if (stamp > k) {
            cout << -1 << '\n';
            return 0;
        }
        color[i] = stamp;
        queue<int> q; q.push(i); while (q.size()) {
            int p = q.front(); q.pop();
            for (int i = 0 ; i < n ; i++) {
                if (G[p][i] == 0)
                    continue;
                if (color[i] != -1)
                    continue;
                color[i] = stamp;
                q.push(i);
            }
        }
    }
    for (auto &p : edges) {
        if (color[p.F] == color[p.S]) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int i = 0 ; i < n ; i++)
        cout << color[i] << " \n"[i == n - 1];
    

}