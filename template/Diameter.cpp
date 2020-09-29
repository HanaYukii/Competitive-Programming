vector<int>g[100005];
int dep[100005];
int mx;
void dfs(int now, int pre) {
    vector<int>ch{0,0};
    for (auto &i : g[now]) {
        if (i ^ pre) {
            dfs(i, now);
            ch.pb(dep[i]);
        }
    }
    sort(all(ch));
    dep[now] = ch.back() + 1;
    mx = max(mx, ch.back() + ch[ch.size()-2]);
}
