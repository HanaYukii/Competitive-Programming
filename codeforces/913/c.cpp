#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define bg begin()
#define ed end()
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,k;
	while(cin >> n >> k){
		ll cont[35]={};
		ll dp[35]={};
		f(n){
			cin >> cont[i];
		}
		dp[0] = cont[0];
		f1(n-1){
			dp[i] = min(cont[i],dp[i-1]<<1);
		}
		ll ans = 1e18;
		ll now = 0;
		for(int i=n-1;i>=0;i--){
			ans = min(ans,now+((k-1)/(1LL<<i)+1)*dp[i]);
			now += (k)/(1LL<<i)*dp[i];
			k %= (1LL<<i);
			//cout << ans << now << k << endl;
		}
		cout << ans << endl;
	}
}