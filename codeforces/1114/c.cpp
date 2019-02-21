#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
struct s{
	ll num,idx;
}cont[maxn];
bool cmp(s x,s y){
	return x.num>y.num;
}
int main(){
	ll n,b;
	while(cin>>n>>b){
		map<ll,ll>mp;
		for(ll i=2;i<=(ll)sqrt(b);i++){
			while(b%i==0){
				b/=i;
				mp[i]++;
			}
		}
		if(b>1){
			mp[b]++;
		}
		ll Min=2e18;
		for(auto i:mp){
			ll tmp=n;
			ll sum=0;
			tmp/=i.first;
			while(tmp){
				sum+=tmp;
				tmp/=i.first;
			}
			Min=min(Min,sum/i.second);
		}
		cout<<Min<<endl;
	}
}