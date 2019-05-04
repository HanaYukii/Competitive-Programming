#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

typedef pair<long long, long long> pll;
struct CostFlow {
    static const int MAXN = 2700;
    static const long long INF = 1LL<<60;
    struct Edge {
        int to, r;
        long long rest, c;
    };
    int n, pre[MAXN], preL[MAXN]; bool inq[MAXN];
    long long dis[MAXN], fl, cost;
    vector<Edge> G[MAXN];
    void init() {
        for ( int i = 0 ; i < MAXN ; i++) G[i].clear();
    }
    void add_edge(int u, int v, long long rest, long long c) {
        G[u].push_back({v, (int)G[v].size(), rest, c});
        G[v].push_back({u, (int)G[u].size()-1, 0, -c});
    }
    pll flow(int s, int t) {
        fl = cost = 0;
        while (true) {
            fill(dis, dis+MAXN, INF);
            fill(inq, inq+MAXN, 0);
            dis[s] = 0;
            queue<int> que;
            que.push(s);
            while ( !que.empty() ) {
                int u = que.front(); que.pop();
                inq[u] = 0;
                for ( int i = 0 ; i < (int)G[u].size() ; i++) {
                    int v = G[u][i].to;
                    long long w = G[u][i].c;
                    if ( G[u][i].rest > 0 && dis[v] > dis[u] + w) {
                        pre[v] = u; preL[v] = i;
                        dis[v] = dis[u] + w;
                        if (!inq[v]) {
                            inq[v] = 1;
                            que.push(v);
                        }
                    }
                }
            }

            if (dis[t] == INF) break;
            long long tf = INF;
            for (int v = t, u, l ; v != s ; v = u ) {
                u = pre[v]; l = preL[v];
                tf = min(tf, G[u][l].rest);
            }
            for (int v = t, u, l ; v != s ; v = u ) {
                u = pre[v]; l = preL[v];
                G[u][l].rest -= tf;
                G[v][G[u][l].r].rest += tf;
            }
            cost += tf * dis[t];
            fl += tf;
        }
        return {fl, cost};
    }
} flow;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,q;
	while(cin >> n >> q){
		int can[55][55];
		f1(n){
			fr(j,1,n+1){
				can[i][j] = 1;
			}
		}
		f(q){
			int t,l,r,v;
			cin >> t >>l >> r >> v;
			if(t==1){
				for(int j=l;j<=r;j++){
					for(int k=1;k<v;k++){
						can[j][k] = 0;
					}
				}
			}
			else{
				for(int j=l;j<=r;j++){
					for(int k=v+1;k<=n;k++){
						can[j][k] = 0;
					}
				}
			}
		}
		f1(2500){
			flow.add_edge(0,i,0,0);
		}
		f1(n){
			fr(j,1,n+1){
				if(!can[i][j])continue;
				fr(k,1,n+1){
					flow.add_edge((k-1)*50+j,2500+i,1,k*2-1);
				}
			}
		}
		f1(n){
			flow.add_edge(2500+i,2600,1,0);
		}
		pair<int,int>res=flow.flow(0,2600);
		if(res.first!=n){
			cout<<-1<<endl;
		}
		else{
			cout<<res.second<<endl;
		}
		////
	}
	
}