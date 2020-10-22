#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 1e6+5;
const long long INF = 1LL<<60;
struct Dinic {  //O(VVE), with minimum cut 
    static const int MAXN = 5003;
    struct Edge{
        int u, v;
        long long cap, rest;
    };

    int n, m, s, t, d[MAXN], cur[MAXN];
    vector<Edge> edges;
    vector<int> G[MAXN];

    void init(){
        edges.clear();
        for ( int i = 0 ; i < n ; i++ ) G[i].clear();
        n = 0;
    }

    // min cut start
    bool side[MAXN];
    void cut(int u) {
        side[u] = 1;
        for ( int i : G[u] ) {
            if ( !side[ edges[i].v ] && edges[i].rest ) cut(edges[i].v);
        } 
    }
    // min cut end

    int add_node(){
        return n++;
    }

    void add_edge(int u, int v, long long cap){
        edges.push_back( {u, v, cap, cap} );
        edges.push_back( {v, u, 0, 0LL} );
        m = edges.size();
        G[u].push_back(m-2);
        G[v].push_back(m-1);
    }
    
    bool bfs(){
        fill(d,d+n,-1);
        queue<int> que;
        que.push(s); d[s]=0;
        while (!que.empty()){
            int u = que.front(); que.pop();
            for (int ei : G[u]){
                Edge &e = edges[ei];
                if (d[e.v] < 0 && e.rest > 0){
                    d[e.v] = d[u] + 1;
                    que.push(e.v);
                }
            }
        }
        return d[t] >= 0;
    }

    long long dfs(int u, long long a){
        if ( u == t || a == 0 ) return a;
        long long flow = 0, f;
        for ( int &i=cur[u]; i < (int)G[u].size() ; i++ ) {
            Edge &e = edges[ G[u][i] ];
            if ( d[u] + 1 != d[e.v] ) continue;
            f = dfs(e.v, min(a, e.rest) );
            if ( f > 0 ) {
                e.rest -= f;
                edges[ G[u][i]^1 ].rest += f;
                flow += f;
                a -= f;
                if ( a == 0 )break;
            }
        }
        return flow;
    }

    long long maxflow(int _s, int _t){
        s = _s, t = _t;
        long long flow = 0, mf;
        while ( bfs() ){
            fill(cur,cur+n,0);
            while ( (mf = dfs(s, INF)) ) flow += mf;
        }
        return flow;
    }
} dinic;

void go() {
    int n, m;
    while (cin >> n >> m) {
        dinic.init();
        dinic.n = (1<<m) + m + 50;
        int st = dinic.n - 1;
        int ed = dinic.n - 2;
        int cnt[1<<m] = {};
        for (int i = 0 ; i < n ; i++) {
            int mask = 0;
            for (int j = 0 ; j < m ; j++) {
                int x;
                cin >> x;
                if (x) {
                    mask |= (1<<j);
                }
            }
            cnt[mask]++;
        }
        f(1<<m) {
            if (!cnt[i])continue;
            dinic.add_edge(st,i,cnt[i]);
            for (int j = 0 ; j < m ; j++) {
                if (i & (1<<j)) {
                    dinic.add_edge(i,(1<<m) + j,INF);
                }
            }
        }
        for (int j = 0 ; j < m ; j++) {
            int x;
            cin >> x;
            dinic.add_edge((1<<m)+j,ed,x);
        }
        if (dinic.maxflow(st,ed) == n) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
}
