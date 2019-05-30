#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int mod=998244353;

int main(){
	ll n;
	while(cin >> n){
		vector<ll>v;
		f(n){
			ll add;
			cin >> add;
			v.pb(abs(add));
		}
		sort(v.begin(),v.end());
		vector<ll>in;
		ll ans=0;
		for(int i=0;i<n;i++){
			ll need=v[i]/2+(v[i]&1);
			ll add=in.end()-lower_bound(in.begin(),in.end(),need);
			ans += add;
			in.pb(v[i]);
		}
		cout << ans << endl;
	}
}