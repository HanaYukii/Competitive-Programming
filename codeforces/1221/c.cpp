#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9+7;
ll pm(ll x,ll p){
	ll now = x;
	ll ret = 1;
	while(p){
		if(p&1){
			ret *= now;
			ret %= mod;
		}
		now *= now;
		now %= mod;
		p >>= 1;
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,k;
	cin >> n >> k;
	ll ans = 1;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i)continue;
		ll cnt = 0;
		ll now = i;
		while(n%i==0){
			n/=i;
		}
		while(k>=now){
			cnt += k / now;
			cnt %= (mod-1);
			if(k/now<i)break;
			now *= i;
		}
		ans *= pm(i,cnt);
		//cout<<i<<' '<<cnt<<endl;
		ans %= mod;
	}
	if(n>1){
		ll cnt = 0;
		ll now = n;
		while(k>=now){
			cnt += k / now;
			cnt %= (mod-1);
			if(k/now<n)break;
			now *= n;
			
		}
		ans *= pm(n,cnt);
		//cout<<n<<' '<<cnt<<endl;
		ans %= mod;
	}
	cout << ans << endl;
}