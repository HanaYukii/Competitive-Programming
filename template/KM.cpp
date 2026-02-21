// Kuhn-Munkres (weighted bipartite matching)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
long long g[505][505];
long long lx[505], ly[505], slack[505];
int visx[505], visy[505], match[505];
int n;
long long sh = 1e11;
bool dfs(int now, bool upd) {
    if (visx[now]) {
        return 0;
    }
    visx[now] = 1;
    for (int i = 0 ; i < n ; i++) {
        if (visy[i]) continue;
        if (lx[now] + ly[i] == g[now][i]) {
            visy[i] = 1;
            if (match[i] == -1 || dfs(match[i], upd)) {
                if (upd)
                    match[i] = now;
                return 1;
            }
        }
        else {
            slack[i] = min(slack[i], lx[now] + ly[i] - g[now][i]);
        }
    }
    return 0;
}
bool augument() {
    for (int j = 0 ; j < n ; j++) {
        if (!visy[j] && slack[j] == 0) {
            visy[j] = 1;
            if (match[j] == -1 || dfs(match[j], 0)) {
                return 1;
            }
        }
    }
    return 0;
}
void relabel() {
    long long d = 1e15;
    for (int i = 0 ; i < n ; i++) {
        if (!visy[i]) {
            d = min(d, slack[i]);
        }
    }
    for (int i = 0 ; i < n ;i++) {
        if (visx[i]) {
            lx[i] -= d;
        }
    }
    for (int j = 0 ; j < n ;j++) {
        if (visy[j]) {
            ly[j] += d;
        }
        else {
            slack[j] -= d;
        }
    }
}
void go() {
    int m;
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        x--, y--;
        g[x][y] = v + sh;
    }
    long long ans = 0;
    for (int i = 0 ; i < n ; i++) {
        lx[i] = ly[i] = 0;
        for (int j = 0 ; j < n ; j++) {
            lx[i] = max(lx[i], g[i][j]);
        }
    }
    memset(match, -1, sizeof(match));
    for (int i = 0 ; i < n ; i++) {
        memset(slack, 0x3f, sizeof(slack));
        memset(visx, 0, sizeof(visx));
        memset(visy, 0, sizeof(visy));
        if (dfs(i, 1)) continue;
        while (!augument()) {
            relabel();
        }
        memset(visx, 0, sizeof(visx));
        memset(visy, 0, sizeof(visy));
        dfs(i, 1);
    }
    for (int i = 0 ; i < n ;i++) {
        ans += g[match[i]][i] - sh;
    }
    cout << ans << '\n';
    for (int i = 0 ; i < n ;i++) {
        cout << match[i] + 1 <<' ';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
    
}
