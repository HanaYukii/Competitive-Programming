// Biconnected Components (BCC)
int dfn[MAXN];
int low[MAXN];
vector<int>g[MAXN], g2[MAXN];
int b[MAXN];
int bcc;
stack<int>st;
int stamp;

void dfs(int now, int pre = 0) {
    ++stamp;
    dfn[now] = low[now] = stamp;
    st.push(now);
    for (auto &i : g[now]) {
        if (i == pre) continue;
        if (dfn[i]) {
            low[now] = min(low[now], dfn[i]);
        }
        else {
            dfs(i, now);
            low[now] = min(low[now], low[i]);
        }
    }
    if (dfn[now] == low[now]) {
        bcc++;
        while (1) {
            auto x = st.top();
            st.pop();
            b[x] = bcc;
            if (x == now) {
                break;
            }
        }
    }
}
void go() {
    int n, m;
    cin >> n >> m;
    f(m) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    f1(n) {
        for (auto &j : g[i]) {
            if (b[j] != b[i]) {
                g2[b[i]].push_back(b[j]);
            }
        }
    }
}
