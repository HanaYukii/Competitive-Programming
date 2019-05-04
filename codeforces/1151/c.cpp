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
#define pii pair<ll,ll>
const ll mod = 1e9+7;
void clr(ll x,ll &odd,ll &even){
	odd=0,even=0;
	int now=0;
	for(ll i=1;i-1<x;i<<=1){
		if(now==1){
			even+=min(x-(i-1),i);
		}
		else{
			odd+=min(x-(i-1),i);
		}
		//cout<<min(x-(i-1),i)<<endl;
		//cout<<even<<' '<<odd<<endl;
		now^=1;
	}
	odd%=mod;
	even%=mod;
}
ll inv(){
	ll ret=1;
	ll p=1e9+5;
	ll x=2;
	while(p){
		if(p&1){
			ret*=x;
			ret%=mod;
		}
		x=x*x%mod;
		p>>=1;
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll l,r;
	while(cin >>l>>r){
		ll ol=0,el=0,oor,er;
		clr(l-1,ol,el);
		clr(r,oor,er);
		//cout<<ol<<' '<<el<<' '<<oor<<' '<<er<<endl;
		//cout<<ol+el<<' '<<oor+er<<endl;
		ll ff=(((1+(ol*2-1))%mod*ol)%mod)*inv()%mod;
		ll ss=(((2+(el*2))%mod*el)%mod)*inv()%mod;
		ll fff=(((1+(oor*2-1))%mod*oor)%mod)*inv()%mod;
		ll sss=(((2+(er*2))%mod*er)%mod)*inv()%mod;
		cout<<(((fff+sss)%mod-(ff+ss)%mod)+mod)%mod<<endl;
	}
	
}