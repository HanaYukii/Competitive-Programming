#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
 
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
const int mod = 1e9+7;
const int maxn = 405;
vector<int>g[maxn]; 
stack<int>st;  
int n,m,scc,index;  
int low[maxn],dfn[maxn],instack[maxn],fa[maxn];  
int gp[maxn][3];
vector<int>can[maxn];
void init(){
	scc = index = 0;
	while(!st.empty())st.pop();
	for(int i=0;i<maxn;i++)g[i].clear();
	memset(dfn,0,sizeof(dfn));
	memset(instack,0,sizeof(instack));
	memset(low,0,sizeof(low));
	memset(fa,0,sizeof(fa));
 
}
void tarjan(int now){
	dfn[now] = low[now] = ++index;
	instack[now] = 1;
	st.push(now);
	for(int k=0;k<(int)g[now].size();k++){
		int i = g[now][k];
		if(!dfn[i]){
			tarjan(i);
			low[now] = min(low[now],low[i]);
		}
		else if(instack[i]){
			low[now] = min(low[now],dfn[i]);
		}
	}
	if(dfn[now] == low[now]){
		scc++;
		while(1){
			int cur = st.top();
			st.pop();
			instack[cur] = 0;
			fa[cur] = scc;
			if(cur == now)break;
		}
	}
}
bool check(){
	for(int i=2;i<=2*n+1;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i=2;i<=2*n;i+=2){
		if(fa[i]==fa[i+1])return 0;
	}
	return 1;
}
void add(int x,int y){
	int f1=0,f2=0;
	f(3){
		if(gp[x][i]==0&&gp[y][i]==0){
			int idx1 = x*2+f1;
			int idx2 = y*2+f2;
			g[idx1].pb(idx2^1);
			g[idx2].pb(idx1^1);
		}
		if(!gp[x][i]){
			f1++;
		}
		if(!gp[y][i]){
			f2++;
		}
	}
}
void build(int now){
	f1(n){
		fr(j,now,n-1){
			add(i,can[i][j]);
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n){
		for(int i=1;i<=n;i++){
			int add;
			cin >> add;
			gp[i][add] = 1;
			fr(j,0,n-1){
				cin >> add;
				can[i].pb(add);
			}
			//reverse(can[i].begin(),can[i].end());
		}
		f(n+1){
			init();
			build(i);
			if(check()){
				cout<<i<<endl;
				exit(0);
			}
		}
	}
}