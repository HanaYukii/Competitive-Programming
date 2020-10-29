int k;
vector<int>g[505];
int match[505];
int vis[505];
vector<int>v;
bool dfs(int x) {
    for (auto i : g[x]) {
        if (!match[i]) {
            match[i] = x;
            return 1;
        }
        else if (!vis[match[i]]) {
            vis[match[i]] = 1;
            v.pb(match[i]);
            if (dfs(match[i])) {
                match[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
void solve() {
    // Hungarian Matching
    memset(match, 0 ,sizeof(match));
    int n, m;
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (dfs(i)) {
            ans++;
        }
        while (v.size()) {
            vis[v.back()] = 0;
            v.pop_back();
        }
    }
    cout << ans << '\n'; // match number
}
