#include<bits/stdc++.h>
using namespace std;
 
using pll = pair<long long,long long>;
using pii = pair<int,int>;
const int MAXN = 1e6 + 50000;
const int mod = 1e9 + 7;
vector<int>g[205];
set<pair<int,int>>st;
int v[205];
int n;
void dfs(int now) {
    v[now] = 1;
    while (g[now].size()) {
        int x = g[now].back();
        g[now].pop_back();
        if (!st.count({x,now})) {
            st.insert({now,x});
            st.insert({x,now});
            dfs(x);
            if (max(now,x) != n + 1) {
                cout << now <<' '<<x<<'\n';
            }
        }
    }
}

void solve() {
    st.clear();
    int  m;
    cin >> n >> m;
    for (int i = 1; i <= n + 1; i++) {
        g[i].clear();
        v[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() % 2) {
            g[n+1].push_back(i);
            g[i].push_back(n+1);
        }
        else {
            ans++;
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            dfs(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
