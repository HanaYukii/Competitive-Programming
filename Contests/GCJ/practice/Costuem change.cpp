#include<bits/stdc++.h>
using namespace std;


using namespace std;
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
      //cout<<n<<endl;
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
        n=207;
        s = _s, t = _t;
        long long flow = 0, mf;
        while ( bfs() ){
            fill(cur,cur+n,0);
            while ( (mf = dfs(s, INF)) ) flow += mf;
        }
        return flow;
    }
} dinic;
int main()
{
	int t;
	cin >> t;
    for (int c = 1 ;c <= t;c++)
    {
       	int n;
       	cin >> n;
       	vector<pair<int,int> >v[205];
       	for(int i=1;i<=n;i++){
       		for(int j=1;j<=n;j++){
       			int add;
       			cin >> add;
       			v[add+100].push_back({i,j});
       		}
       	}
       	int sum=0;
       	//cout<<"gg"<<endl;
       	for(int j=0;j<=201;j++){
       		if(!v[j].size())continue;
       		dinic.init();
       		for(int i=1;i<=n;i++){
       			dinic.add_edge(0,i,1);
       			dinic.add_edge(100+i,205,1);
       		}
       		for(auto i:v[j]){
       			dinic.add_edge(i.first,100+i.second,1);
       			//cout<<100+i.first<<' '<<200+i.second<<endl;
       			//cout<<i.first+1<<' '<<n+i.second+1<<endl;
       			
       		}
       		//cout<<"gg"<<endl;
       		sum += dinic.maxflow(0,205);
       		//cout<<"gg"<<endl;
       		//cout<<"gg"<<endl;
       	}
       	int ans=n*n-sum;
       	printf("Case #%d: %d\n",c,ans);
    }
    return 0;
}
