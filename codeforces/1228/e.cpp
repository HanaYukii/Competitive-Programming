#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
const int mod = 1e9+7;
ll pre[300];
int n;
int d;
int now = 19260817;
ll pm(ll x,ll k){
	ll ret = 1;
	ll now = x;
	while(k){
		if(k&1){
			ret *= now;
			ret %= mod;
		}
		now *= now;
		now %= mod;
		k >>= 1;
	}
	return ret;
}
ll C(int n,int m){
	return pre[n]*pm(pre[m],mod-2)%mod*pm(pre[n-m],mod-2)%mod;
}
void init(){
	pre[0] = 1;
	f1(n){
		pre[i] = pre[i-1] * i % mod;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> d;
	init();
	ll ans = 0;
	f(n+1){
		fr(j,0,n+1){
			now = pm(d,i*j)*C(n,i)%mod*C(n,j)%mod * pm(d-1,n*n-i*j)%mod;
			if((i^j)&1)ans = (ans - now + mod)%mod;
			else ans = (ans + now) % mod;
		}
	}
	cout << ans << endl;
}