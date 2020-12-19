#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<60;
struct Dinic {  
    static const int MAXN = 5003;
    struct Edge{
        int u, v;
        long long cap, rest;
    };

    int n, m, s, t;
    vector<int> d, cur;
    vector<Edge> edges;
    vector<vector<int>> g;

    void init(int sz){
        edges.clear();
        d.resize(sz);
        cur.resize(sz);
        g.clear();
        g.resize(sz);
        n = sz;
    }
    void add_edge(int u, int v, long long cap){
        edges.push_back( {u, v, cap, cap} );
        edges.push_back( {v, u, 0, 0LL} );
        m = edges.size();
        g[u].push_back(m-2);
        g[v].push_back(m-1);
    }
    
    bool bfs(){
        fill(d.begin(), d.end(), -1);
        queue<int> q;
        q.push(s); 
        d[s]=0;
        while (q.size()){
            int now = q.front(); 
            q.pop();
            for (int ei : g[now]){
                Edge &e = edges[ei];
                if (d[e.v] < 0 && e.rest > 0){
                    d[e.v] = d[now] + 1;
                    q.push(e.v);
                }
            }
        }
        return d[t] >= 0;
    }

    long long dfs(int u, long long a){
        if ( u == t || a == 0 ) return a;
        long long flow = 0, f;
        for ( int &i=cur[u]; i < (int)g[u].size() ; i++ ) {
            Edge &e = edges[ g[u][i] ];
            if ( d[u] + 1 != d[e.v] ) continue;
            f = dfs(e.v, min(a, e.rest) );
            if ( f > 0 ) {
                e.rest -= f;
                edges[ g[u][i]^1 ].rest += f;
                flow += f;
                a -= f;
                if ( a == 0 )break;
            }
        }
        return flow;
    }

    long long maxflow(int source, int target){
        s = source, t = target;
        long long flow = 0, cur_flow;
        while ( bfs() ){
            fill(cur.begin(),cur.end(),0);
            while ( (cur_flow = dfs(s, INF)) ) flow += cur_flow;
        }
        return flow;
    }
} dinic;
int main(){
    
}
