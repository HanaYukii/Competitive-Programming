// 2-SAT (implication graph + SCC)
int dfn[200005];
int low[200005];
int stk[200005];
int pa[200005];
int pick[200005];
int opp[200005];
int in[200005];
int scc;
int idx;
stack<int>st;
vector<int>g[200005];
vector<int>rev[200005];
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
int n;
int tr(int x) {
    if (x <= n) {
        x += n;
    }
    else {
        x -= n;
    }
    return x;
}
bool check() {
    for (int i = 1 ; i <= n ; i++) {
        if (pa[i] == pa[i + n]) {
            return 0;
        }
        opp[pa[i]] = pa[i+n];
        opp[pa[i+n]] = pa[i];
    }
    return 1;
}
void build() {
    for (int i = 1 ; i <= n * 2 ; i++) {
        for (auto j : g[i]) {
            if (pa[j] != pa[i]) {
                in[pa[i]]++;
                rev[pa[j]].pb(pa[i]);
            }
        }
    }
}
void topo() {
    memset(pick, 0, sizeof(pick));
    queue<int>q;
    f1(scc) {
        if (!in[i]) {
            q.push(i);
        }
    }
    while (q.size()) {
        auto now = q.front();
        q.pop();
        if (!pick[now]) {
            pick[now] = 1;
            pick[opp[now]] = 2;
        }
        for (auto &i : rev[now]) {
            in[i]--;
            if (!in[i]) {
                q.push(i);
            }
        }
    }
    f1(n) {
        if (pick[pa[i]] == 1) {
            cout << '-' <<' ';
        }
        else {
            cout << '+' <<' ';
        }
    }
    cout << '\n';
}
