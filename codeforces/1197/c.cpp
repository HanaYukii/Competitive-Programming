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
const ll mod = 1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,k;
	while(cin >> n >> k){
		ll cont[n+5] = {};
		vector<ll>dif;
		ll ans = 0;
		f1(n){
			cin >> cont[i];
		}
		fr(i,2,n+1){
			dif.pb(cont[i]-cont[i-1]);
		}
		sort(dif.begin(),dif.end());
		f(n-k){
			ans += dif[i];
		}
		cout << ans << endl;
	}
}