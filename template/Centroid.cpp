// Centroid Decomposition
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
const int mod = 998244353;
vector<int>g[200005];
int u[200005];
long long ans[200005];
int v[200005];
int sz[200005];
map<int,int>mp;
void mark(int now, int pre) {
    sz[now] = 1;
    for (auto i:g[now]) {
        if (i == pre) continue;
        if (!u[i]) {
            mark(i, now);
            sz[now] += sz[i];
        }
    }
}
void clear(int now) {
    for (auto i:g[now]) {
        if (!u[i]&&sz[i]) {
            sz[i] = 0;
            clear(i);
        }
    }
}
void dfs(int now, int pre, int val) {
    mp[val]++;
    for (auto i:g[now]) {
        if (!u[i] && i != pre) {
            dfs(i, now, __gcd(val, v[i]));
        }
    }
}
void upd(int d) {
    for (auto i:mp) {
        ans[i.first] += (long long)i.second * (i.second + 1) / 2 * d;
        for (auto j:mp) {
            if (j.first > i.first) {
                ans[__gcd(i.first,j.first)] += (long long)i.second * j.second * d;
            }
        }
    }
}
int find_root(int now, int tar) {
    while (1) {
        int nx = 0;
        for (auto i:g[now]) {
            if (u[i] || sz[i] > sz[now]) {
                continue;
            }
            if (2 * sz[i] > tar) {
                nx = i;
                break;
            }
        }  
        if (nx) {
            now = nx;
        }
        else {
            return now;
        }
    }
}
void solve(int now) {
    mark(now, 0);
    now = find_root(now, sz[now]);
    u[now] = 1;
    clear(now);
    mp.clear();
    dfs(now, 0, v[now]);
    upd(1);
    for (auto i:g[now]) {
        if (!u[i]) {
            mp.clear();
            dfs(i, now, __gcd(v[now], v[i]));
            upd(-1);
        }
    }
    for (auto i:g[now]) {
        if (!u[i])
            solve(i);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    solve(1);
    for (int i = 1; i <= 200000; i++) {
        if (ans[i]) {
            cout << i << ' ' << ans[i] << '\n';
        }
    }
}
