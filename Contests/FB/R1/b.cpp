#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const ll mod = 1e9+7;
ll pm(ll x){
	ll ret = 1;
	ll now = 2;
	while(x){
		if(x&1){
			ret *= now;
			ret %= mod;
		}
		now *= now;
		now %= mod;
		x >>= 1;
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int c=1;c<=t;c++){
		int n,k;
		cin >> n >> k;
		ll ans = 0;
		stack<ll>q;
		string s;
		cin >> s;
		s=" "+s;
		for(ll i=n;i>=1;i--){
			if(s[i]=='A'){
				if(!q.empty()){
					q.pop();
				}
			}
			else{
				q.push(i);
				if((int)q.size()>k){
					ll now = q.top();
					q.pop();
					ans += pm(now);
					ans %= mod;
					if(q.size()){
						q.pop();
					}
				}
			}
		}
		cout << "Case #"<<c<<": "<<ans << '\n';
	}
}