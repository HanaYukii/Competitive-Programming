#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
vector<int>g[10005];
int fa[10005][20];
int d[10005];
void dfs(int now){
	for(int i=0;i<(int)g[now].size();i++){
		d[g[now][i]]=d[now]+1;
		dfs(g[now][i]);
	}
}
int lca(int x,int y){
	int need=d[y]-d[x];
	int p1=x,p2=y;
	for(int i=19;i>=0;i--){
		if(need>=(1<<i)){
			p2=fa[p2][i];
			need-=(1<<i);
		}
	}
	if(p2==p1){
		return p1;
	}
	for(int i=19;i>=0;i--){
		if(fa[p1][i]!=fa[p2][i]){
			p1=fa[p1][i];
			p2=fa[p2][i];
		}
	}
	return fa[p1][0];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		f1(n)g[i].clear();
		ms(d);
		f1(n)fa[i][0]=0;
		f(n-1){
			int add1,add2;
			cin>>add1>>add2;
			fa[add2][0]=add1;
			g[add1].pb(add2);
		}
		int rt=0;
		f1(n){
			if(fa[i][0]==0){
				rt=i;
				fa[i][0]=i;
			}
		}
		d[rt]=1;
		dfs(rt);
		for(int i=1;i<20;i++){
			for(int j=1;j<=n;j++){
				fa[j][i]=fa[fa[j][i-1]][i-1];
			}
		}
		int x,y;
		cin>>x>>y;
		if(d[x]>d[y])swap(x,y);
		cout<<lca(x,y)<<endl;
	}
}