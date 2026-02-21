// Strongly Connected Components (Tarjan's SCC)
#include<bits/stdc++.h>
using namespace std;

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
    // tarjan scc
    int n, m;
    cin >> n >> m;
    for (int i = 0 ; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1 ; i <= n ; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    cout << scc << '\n'; // scc count
    for (int i = 1 ; i <= n ; i++) {
        cout << pa[i] << ' ';// scc number
    }
    cout << '\n';
}
