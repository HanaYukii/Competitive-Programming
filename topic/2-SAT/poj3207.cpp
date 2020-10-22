#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
const int mod = 1e9+7;
const int N = 2000;
struct edge
{
    int to, next;
}g[N*100];
int cnt, head[N];
int dfn[N], low[N], st[N], scc[N], top, idx, num;
bool vis[N];
int a[N], b[N];
int n, m;
void add_edge(int v,int u){
	g[cnt].to = u;
	g[cnt].next = head[v];
	head[v] = cnt++;
}
void init(){
	memset(head,-1,sizeof(head));
	memset(dfn,-1,sizeof(dfn));
	memset(vis,0,sizeof(vis));
	cnt = num = idx = top = 0;
}
void tarjan(int v){
	dfn[v] = low[v] = ++idx;
	vis[v] = 1;
	st[top++] =v;
	int u;
	for(int i=head[v];i!=-1;i=g[i].next){
		u = g[i].to;
		if(dfn[u] == -1){
			tarjan(u);
			low[v] = min(low[v],low[u]);
		}
		else if(vis[u]) low[v] = min(low[v],dfn[u]);
	}
	if(dfn[v] == low[v]){
		++num;
		do
		{
			u = st[--top],vis[u]=false,scc[u]=num;
		}while(u!=v);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n >> m){
		init();
		f1(m){
			cin >> a[i] >> b[i];
			if(a[i]>b[i]){
				swap(a[i],b[i]);
			}
		}
		f1(m){
			fr(j,i+1,m+1){
				if((a[i]<a[j]&&b[i]<b[j]&&a[j]<b[i])||(a[j]<a[i]&&b[j]<b[i]&&a[i]<b[j])){
					add_edge(i,j+m);
					add_edge(j+m,i);
					add_edge(i+m,j);
					add_edge(j,i+m);
				}
			}
		}
		f1(2*m){
			if(dfn[i]==-1)tarjan(i);
		}
		int f = 0;
		f1(m){
			if(scc[i]==scc[i+m]){
				f = 1;
			}
		}
		if(f){
			cout<<"the evil panda is lying again" << '\n';
		}
		else{
			cout<<"panda is telling the truth..."<<'\n';
		}
	}
}