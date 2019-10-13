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
ll w[maxn],t[maxn],v[maxn];
ll dp[maxn];
vector<int>g[maxn];
void dfs(int now,int pre){
	v[now] = 1;
	for(auto i:g[now]){
		if(i==pre)continue;
		if(v[i])t[now] = 1;
		else dfs(i,now),t[now] |= t[i];
	}
	if(!t[now]){
		for(auto i:g[now]){
			if(i!=pre)dp[now] = max(dp[now],dp[i]);
		}
		dp[now] += w[now];
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;	
	cin >> n >> m;
	f1(n)cin >> w[i];
	f(m){
		int add1,add2;
		cin >> add1 >> add2;
		g[add1].pb(add2);
		g[add2].pb(add1);
	}
	int s;
	cin >> s;
	dfs(s,0);	
	ll ans = 0,mx = 0;
	f1(n){
		if(t[i])ans += w[i];
		else mx = max(mx,dp[i]);
	}
	cout << ans + mx << endl;
}