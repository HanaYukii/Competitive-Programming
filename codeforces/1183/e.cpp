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
const ll mod = 1000007;
set<int>g[105];
string s;
ll dp[105][105];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,k;
	while(cin >> n >> k){
		//string s;
		f(105){
			g[i].clear();
		}
		ms(dp);
		cin >> s;
		for(int i=0;i<n;i++){
			int u[26] = {};
			for(int j=i+1;j<n;j++){
				if(!u[s[j]-'a']){
					u[s[j]-'a'] = 1;
					g[i].insert(j);
				}
			}
		}
		int u[26] = {};
		vector<int>pos;
		f(n){
			if(!u[s[i]-'a']){
				pos.pb(i);
				u[s[i]-'a'] = 1;
			}
		}
		dp[pos[0]][0] = 1;
		f(105){
			dp[i][1] = 1;
		}
		for(int i=n-2;i>=0;i--){
			for(int j=i+1;j<n;j++){
				if(g[i].find(j)!=g[i].end()){
					for(int k=n;k>1;k--){
						dp[i][k] += dp[j][k-1];
						if(dp[i][k]>100)dp[i][k]=100;
					}
				}
			}
		}
		ll ans = 0;
		for(ll i=n;i>=0;i--){
			for(auto j:pos){
				ll num = dp[j][i];
				if(k>num){
					k -= num;
					ans += (n-i)*num;
				}
				else{
					ans += (n-i)*k;
					k = 0;
				}
			}
		}
		if(k){
			cout << -1 << endl;
		}
		else{
			cout << ans << endl;
		}
	}
}