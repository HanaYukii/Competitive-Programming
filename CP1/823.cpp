#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int b[maxn+5];
int dp[maxn];
vector<int>pre[maxn];
void update(int x,int now){
	if(!x)return;
	while(x<=maxn){
		b[x]=now;
		x+=(x&(-x));
	}
}
int find(int x){
	int ret=0;
	while(x){
		ret=max(ret,b[x]);
		x-=(x&(-x));
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		f(n+1){
			dp[i]=0;
			b[i]=0;
			pre[i].clear();
		}
		//int ans=0;
		vector<int>cont;
		f1(n){
			int add;
			cin>>add;
			cont.pb(n+1-add);
			//dp[i]=dp[find(add)]+1;
			//ans=max(ans,dp[i]);
			//update(add,i);
			//update(add-1,0);
		}
		reverse(cont.begin(),cont.end());
		f1(n){
			pre[find(cont[i-1])].pb(i);
			update(cont[i-1],i);
		}
		int ans=1;
		for(int i=n;i>=1;i--){
			if(!pre[i].size()){
				dp[i]=1;
			}
			else{
				int mx=0;
				for(auto j:pre[i]){
					mx=max(mx,dp[j]);
				}
				dp[i]=mx+1;
				ans=max(ans,dp[i]);
			}
		}
		cout<<ans<<'\n';
	}
}