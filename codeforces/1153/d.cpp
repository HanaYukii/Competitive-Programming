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
#define bg begin()
#define ed end()
int c[maxn],dp[maxn];
vector<int>g[maxn];
int dfs(int now){
	if(!g[now].size())return dp[now]=1;
	int mi=1e9,sum=0;
	for(auto i:g[now]){
		int ret=dfs(i);
		mi=min(mi,ret);
		sum+=ret;
	}
	if(c[now]){
		return dp[now]=mi;
	}
	else{
		return dp[now]=sum;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n){
		int l=0;
		f1(n)g[i].clear();
		f1(n)cin >>c[i];
		fr(i,2,n+1){
			int add;
			cin >> add;
			g[add].pb(i);
		}
		f1(n){
			if(!g[i].size())l++;
		}
		dfs(1);
		cout<<l-dp[1]+1<<endl;
	}

}