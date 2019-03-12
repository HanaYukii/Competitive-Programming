#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
vector<pair<int,ll> >g[100005];
int dp[100005][20];
int d[100005];
int fw[100005];
int inc[100005];
int decr[100005];

void dfs(int now,int pre,ll w){
	for(auto i:g[now]){
		if(i.first!=pre){
			dp[i.first][0]=now;
			d[i.first]=d[now]+1;
			fw[i.first]=i.second;
			if(i.second<=w)inc[i.first]=inc[now];
			else inc[i.first]=d[now];

			if(i.second>=w)decr[i.first]=decr[now];
			else decr[i.first]=d[now];
			dfs(i.first,now,i.second);
		}
	}
}
int lca(int x,int y){
	int p1=x,p2=y;
	if(d[x]<d[y]){
		swap(x,y);
		swap(p1,p2);
	}
	int need=d[x]-d[y];
	//cout<<need<<endl;
	for(int i=19;i>=0;i--){
		if(need>=(1<<i)){
			need-=(1<<i);
			x=dp[x][i];
		}
	}
	//cout<<x<<' '<<y<<endl;
	if(x==y){
		if(inc[p1]<=d[p2]||decr[p1]<=d[p2]){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		for(int i=19;i>=0;i--){
			if(dp[x][i]!=dp[y][i]){
				x=dp[x][i];
				y=dp[y][i];
			}
		}
		int lc=dp[x][0];
		if(inc[p1]<=d[lc]&&decr[p2]<=d[lc]&&fw[x]<=fw[y]){
			return 1;
		}
		else if(decr[p1]<=d[lc]&&inc[p2]<=d[lc]&&fw[x]>=fw[y]){
			return 1;
		}
		else{
			return 0;
		}
		//cout<<lc<<endl;
	}
}
int main(){
	int n,q;
    while(cin>>n>>q){
    	f(n-1){
    		int add1,add2;
    		ll w;
    		cin>>add1>>add2>>w;
    		g[add1].pb({add2,w});
    		g[add2].pb({add1,w});
    	}
    	dp[1][0]=1;
    	d[1]=1;
    	inc[1]=1;
    	decr[1]=1;
    	dfs(1,0,0);
    	//cout<<endl;
    	for(int i=1;i<20;i++){
    		for(int j=1;j<=n;j++){
    			dp[j][i]=dp[dp[j][i-1]][i-1];
    		}
    	}
    	while(q--){
    		int x,y;
    		cin>>x>>y;
    		if(lca(x,y)){
    			cout<<"YES"<<endl;
    		}
    		else{
    			cout<<"NO"<<endl;
    		}
    	}
    }
}