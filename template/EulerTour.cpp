// Euler Path/Circuit on undirected graph (Hierholzer, multiset version)
// Handles both Euler circuit (all even degree) and Euler path (exactly 2 odd degree)
int n;
multiset<int>g[505];
vector<int>ans;
void dfs(int now) {
    while (g[now].size()) {
        int x = *g[now].begin();
        g[now].erase(g[now].lower_bound(x));
        g[x].erase(g[x].lower_bound(now));
        dfs(x);
    }
    ans.push_back(now);
}
void solve() {
    ans.clear();
    f1(500) {
        g[i].clear();
    }
    f(n) {
        int x, y;
        cin >> x >> y;
        g[x].insert(y);
        g[y].insert(x);
    }
    int x = 0, y = 0;
    f1(500) {
        if (g[i].size() % 2 == 1) {
            if (x == 0) {
                x = i;
            }
            else {
                y = i;
            }
        } 
    }
    if (!x) {
        dfs(1);
    }
    else {
        dfs(min(x, y));
    }
    reverse(all(ans));
    for (auto &i : ans) {
        cout << i << '\n';
    }
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n && n) {
        solve();
    }
}
