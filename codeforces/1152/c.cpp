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
bool test(int x){
	int ret=0;
	while(x){
		if(!(x&1)){
			ret = 1;
			break;
		}
		x >>= 1;
	}
	return ret^1;
}
int tb(int x){
	int ret=0;
	while(x){
		ret++;
		x >>= 1;
		//cout<<ret<<'z'<<endl;
	}
	return ret;
}
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n,m;
	//int now=0;
	while(cin >>n >> m){
		if(n==m){
			cout<<0<<endl;
			continue;
		}
		vector<ll>d;
		if(n>m){
			swap(n,m);
		}
		ll dif=abs(n-m);
		for(int i=1;i<=(ll)sqrt(dif);i++){
			if(dif%i==0){
				d.pb(i);
				d.pb(dif/i);
			}
		}
		ll mi=2e18;
		ll ans=0;
		for(auto i:d){
			ll mul=(n-1)/i;
			ll g=i*(mul+1)-n;
			ll a=n+g,b=m+g;
			if(a*b/(__gcd(a,b))<mi){
				mi=a*b/(__gcd(a,b));
				ans=g;
			}
		}
		cout<<ans<<endl;
	}

}