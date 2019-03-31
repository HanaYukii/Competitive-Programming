#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;
vector<int>g[maxn];
int v[maxn];
int dfs(int now,int pre){
	v[now]=1;
	int ret=1;
	for(auto i:g[now]){
		if(i!=pre){
			ret+=dfs(i,now);
		}
	}
	return ret;
}
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	while(cin>>n>>k){
		ll ans=1;
		ms(v);
		f(k){
			ans*=n;
			ans%=mod;
		}
		f(n-1){
			int a,b,c;
			cin>>a>>b>>c;
			if(!c){
				g[a].pb(b);
				g[b].pb(a);
			}
		}

		for(int i=1;i<=n;i++){
			if(!v[i]){
				ll now=dfs(i,0);
				ll num=now;
				f(k-1){
					num*=now;
					num%=mod;
				}
				ans+=mod;
				ans-=num;
				ans%=mod;
			}
		}
		cout<<ans<<endl;
	}
}