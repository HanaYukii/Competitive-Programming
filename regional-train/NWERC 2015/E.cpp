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
int M;
const long long INF = 1LL<<60;
vector<pair<ll,ll> >v;
int idx = 0;
map<ll,ll>mp,rev;
ll n2i(ll num){
    if(!mp.count(num)){
        mp[num]=++idx;
        rev[idx]=num;
    }
    return mp[num];
}
ll i2n(ll num){
    return rev[num];
}
struct Dinic {  //O(VVE), with minimum cut 
    static const int MAXN = 20003;
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
    void solve(){
        set<ll>st;
        for(int i=0;i<M;i++){
            for(auto j:G[i]){
                if(edges[j].v>i&&!edges[j].rest){
                    int tar = edges[j].v-M;
                    ll num = i2n(tar);
                    
                    
                    if(v[i].F*v[i].S==num){
                        cout<<v[i].F<<' '<<'*'<<' '<<v[i].S<<' '<<'='<<' '<<num<<endl;
                    }
                    else if(v[i].F+v[i].S==num){
                        cout<<v[i].F<<' '<<'+'<<' '<<v[i].S<<' '<<'='<<' '<<num<<endl;
                    }
                    else{
                        cout<<v[i].F<<' '<<'-'<<' '<<v[i].S<<' '<<'='<<' '<<num<<endl;
                    }

                }
            }
        }
    }
} dinic;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
    M = n;
    f(n){
        ll x,y;
        cin >> x >> y;
        v.pb({x,y});
        n2i(x+y);
        n2i(x-y);
        n2i(x*y);
    }
    dinic.n=20001;
    f(n){
        ll x = v[i].F,y=v[i].S;
        dinic.add_edge(15000,i,1);
        dinic.add_edge(i,n+n2i(x+y),1);
        dinic.add_edge(i,n+n2i(x-y),1);
        dinic.add_edge(i,n+n2i(x*y),1);
    }
    f1(idx){
        dinic.add_edge(n+i,20000,1);
    }
    int flow = dinic.maxflow(15000,20000);
    if(flow<n){
        cout<<"impossible"<<endl;
    }
    else{
        dinic.solve();
    }
}
