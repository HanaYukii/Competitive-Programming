#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
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
int main(){
	int n,m,k;
    cin >> m >> n >> k;
    dinic.init();
    dinic.n = 5000;
    string s[n];
    f(n){
        cin >> s[i];
    }
    int c[k+5]={};
    f(k){
        cin >> c[i];
    }
    int st = 0;
    f(n){
        fr(j,0,m){
            int pos = i*m+j;
            if(s[i][j]=='B'){
                st = pos;
                dinic.add_edge(pos,pos+1000,INF);
            }
            else if(s[i][j]=='.'){
                dinic.add_edge(pos,pos+1000,INF);
            }
            else{
                int cc = c[s[i][j]-'a'];
                dinic.add_edge(pos,pos+1000,cc);
            }
            int dx[] = {1,-1,0,0};
            int dy[] = {0,0,1,-1};
            fr(z,0,4){
                int nx = i+dx[z];
                int ny = j+dy[z];
                int ppos = nx*m+ny;
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    dinic.add_edge(pos+1000,ppos,INF);
                }
                else{
                    dinic.add_edge(pos+1000,2000,INF);
                }
            }
        }
    }
    ll mx = dinic.maxflow(st,2000);
    if(mx==INF){
        cout<<-1<<endl;
    }
    else{
        cout<<mx<<endl;
    }
}
