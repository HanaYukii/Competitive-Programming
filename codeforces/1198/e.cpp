#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const ll mod = 1e9+7;
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while(cin >> n >> m){
		//cin >> n >> m;
		if(!m){
			cout<<"0"<<endl;
			exit(0);
		}
		map<int,int>x,y;
		vector<pair<pair<int,int>,pair<int,int> > >v;
		f(m){
			int x1,x2,y1,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			x[x1];x[x2+1];y[y1];y[y2+1];
			v.pb({{x1,x2+1},{y1,y2+1}});
		}
		int xc[105],yc[105];
		int last = 0,idxx = 0;
		for(auto &it:x){
			xc[idxx] = it.F - last;
			idxx++;
			it.S = idxx;
			last = it.F;
		}
		int idxy = 0;
		last = 0;
		for(auto &it:y){
			yc[idxy] = it.F - last;
			idxy++;
			it.S = idxy;
			last = it.F;
		}
		dinic.init();
		dinic.n = idxx+idxy+5;
		for(int i = 1 ; i < idxx ; i++){
			dinic.add_edge(0,i,xc[i]);
		}
		for(int i = 1 ; i < idxy ; i++){
			dinic.add_edge(idxx+i,idxx+idxy,yc[i]);
		}
		f(m){
			int l1 = x[v[i].F.F],r1 = x[v[i].F.S];
			int l2 = y[v[i].S.F],r2 = y[v[i].S.S];
			for(int j = l1 ;j < r1 ; j++){
				for(int k = l2 ; k < r2 ; k++){
					dinic.add_edge(j,idxx+k,1e9);
				}
			}
		}
		cout<<dinic.maxflow(0,idxx+idxy)<<endl;
	}
}