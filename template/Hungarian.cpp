int k;
vector<int>g[505];
int match[505];
int check[505];
bool dfs(int x) {
    for (auto i : g[x]) {
        if (check[i])continue;
        check[i] = 1;
        if (!match[i]) {
            match[i] = x;
            return 1;
        }
        else if (dfs(match[i])) {
            match[i] = x;
            return 1;
        }
    }
    return 0;
}
void solve() {
    memset(match, 0 ,sizeof(match));
    int n, m;
    cin >> n >> m;
    f1(n) {
        g[i].clear();
    }
    f(k) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
    }
    int ans = 0;
    f1(n) {
        memset(check, 0, sizeof(check));
        if (dfs(i)) {
            ans++;
        }
    }
    cout << ans << '\n';
}
