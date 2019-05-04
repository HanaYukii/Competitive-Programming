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
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n,m;
	while(cin >>n>>m){
		ll dp[n+5][4];
		f1(n){
			ll add;
			cin >> add;
			dp[i][0]=dp[i-1][0]+add;
			dp[i][1]=max(dp[i-1][0],dp[i-1][1])+add*m;
			dp[i][2]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+add;
			dp[i][3]=max({dp[i-1][3],dp[i][0],dp[i][1],dp[i][2]});
		}
		cout<<dp[n][3]<<endl;
	}

}