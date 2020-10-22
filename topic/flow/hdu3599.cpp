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
vector<pair<int,int>>g[1505];
int dis[1505];
int dis2[1505];
void go() {
    int n;
    cin >> n;
    int u, v, w;
    f1(n) {
        g[i].clear();
    }
    while (cin >> u >> v >> w && u) {
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    memset(dis, 0x3f, sizeof(dis));
    memset(dis2, 0x3f, sizeof(dis2));
    dis[1] = 0;
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
       // cout << now.S <<' '<<dis[now.S] << endl;
        if (dis[now.S] != now.F)continue;
        for (auto &i : g[now.S]) {
            if (dis[i.F] > now.F + i.S) {
                dis[i.F] = now.F + i.S;
                pq.push({dis[i.F], i.F});
            }
        }
    }
    dis2[n] = 0;
    pq.push({0,n});
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
        if (dis2[now.S] != now.F)continue;
        for (auto &i : g[now.S]) {
            if (dis2[i.F] > now.F + i.S) {
                dis2[i.F] = now.F + i.S;
                pq.push({dis2[i.F], i.F});
            }
        }
    }
    dinic.init();
    dinic.n = n + 2;
    dinic.add_edge(0,1,INF);
    f1(n) {
        for (auto &j : g[i]) {
            if (dis[i] + j.S + dis2[j.F] == dis[n]) {
                dinic.add_edge(i, j.F, 1);
                //cout << i <<' '<<j.F<<endl;
            }
        }
    }
    cout << dinic.maxflow(0,n) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 1;
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
