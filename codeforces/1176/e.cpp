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
#define pii pair<int,int>
const ll mod = 1e9+7;
int d[200005];
int c[200005];
vector<int>g[200005];
vector<int>ans;
int fi(int x){
	return d[x]==x?d[x]:d[x]=fi(d[x]);
}
void dfs(int now,int pre){
	if(g[now].size()==1&&g[now][0]==pre)return;
	for(auto i:g[now]){
		if(i!=pre)dfs(i,now);
	}
	for(auto i:g[now]){
		if(i!=pre&&c[i]==0){
			c[now]=1;
			ans.pb(now);
			break;
		}
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		
		f1(n){
			d[i]=i;
			c[i]=0;
			g[i].clear();
			ans.clear();
		}

		f(m){
			int add1,add2;
			cin >> add1 >> add2;
			int x=fi(add1);
			int y=fi(add2);
			if(x==y)continue;
			d[x]=y;
			g[add1].pb(add2);
			g[add2].pb(add1);

		}
		
		dfs(1,0);
		cout<<ans.size()<<'\n';
		for(auto i:ans){
			cout<<i<<' ';
		}
		cout<<'\n';
	}
}