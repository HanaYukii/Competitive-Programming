#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 300005;
const int mod = 998244353;
vector<int>g[200005];
int u[200005];
ll ans[200005];
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
        ans[i.F] += (ll)i.S * (i.S + 1) / 2 * d;
        for (auto j:mp) {
            if (j.F > i.F) {
                ans[__gcd(i.F,j.F)] += (ll)i.S * j.S * d;
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
    f1 (n) {
        cin >> v[i];
    }
    f (n - 1) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    solve(1);
    f1 (200000) {
        if (ans[i]) {
            cout << i << ' ' << ans[i] << '\n';
        }
    }
}
