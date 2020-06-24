int dfn[200005];
int low[200005];
int stk[200005];
int pa[200005];
int scc;
int idx;
stack<int>st;
vector<int>g[200005];
void tarjan(int now) {
    dfn[now] = low[now] = ++idx;
    stk[now] = 1;
    st.push(now);
    for (auto &i : g[now]) {
        if (!dfn[i]) {
            tarjan(i);
            low[now] = min(low[now], low[i]);
        }
        else if (stk[i]) {
            low[now] = min(low[now], dfn[i]);
        }
    }
    if (dfn[now] == low[now]) {
        scc++;
        int nxt =-1;
        while (nxt != now) {
            nxt = st.top();
            st.pop();
            stk[nxt] = 0;
            pa[nxt] = scc;
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    f(m) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
    }
    f1(n) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
}
