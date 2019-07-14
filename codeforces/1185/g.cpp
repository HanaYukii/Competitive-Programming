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
vector<pair<int,int> >v;
ll dp[1<<15][3];
int n;
ll solve(int x,int k){
	if(~dp[x][k]){
		return dp[x][k];
	}
	dp[x][k] = 0;
	for(int i=0;i<n;i++){
		if(!(x&(1<<i))||v[i].second!=k)continue;
		for(int j=0;j<3;j++){
			if(j!=k){
				dp[x][k] += solve(x^(1<<i),j);
				dp[x][k] %= mod;
			}
		}
	}
	return dp[x][k];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin >> n >> m;
	ms1(dp);
	
	f(n){
		int add1,add2;
		cin >> add1 >> add2;
		add2--;
		dp[1<<i][add2]=1;
		v.pb({add1,add2});
	}
	ll ans = 0;
	for(int i=1;i<(1<<n);i++){
		solve(i,0);
		solve(i,1);
		solve(i,2);
	}
	for(int i=1;i<(1<<n);i++){
		int sum = 0;
		for(int j=0;j<n;j++){
			if(!(i&(1<<j)))continue;
			sum += v[j].first;
		}
		//cout << sum << endl;
		if(sum == m){
			ans += dp[i][0];
			ans %= mod;
			ans += dp[i][1];
			ans %= mod;
			ans += dp[i][2];
			ans %= mod;
		}
	}
	cout << ans << '\n';
}