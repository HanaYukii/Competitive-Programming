#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
#define maxn 500
set<ll>fac;
vector<pair<ll,int> >v;

void dfs(int now,ll num){
	if(now==v.size()){
		fac.insert(num);
		return ;
	}
	ll mul=v[now].first;
	dfs(now+1,num);
	for(int i=0;i<v[now].second;i++){
		num*=mul;
		dfs(now+1,num);
	}
}
int main() {
	ll k;
	while(cin >> k){
		//vector<ll>fac;
		int tmp = k;
		map<ll,int>mp;
		for(ll i=2;i<=sqrt(k);i++){
			if((k%i)!=0)continue;
			while(k%i==0){
				k/=i;
				mp[i]++;
			}
		}
		if(k!=1){
			mp[k]++;
		}
		k=tmp;
		for(auto i:mp){
			v.pb({i.first,i.second*2});
		}
		dfs(0,1);
		cout<<fac.size()<<endl;
		/*for(auto i:fac){
			cout<<i<<' ';
		}
		cout<<endl;*/
		for(auto i:fac){
			cout<<i+k<<' '<<k*k/i+k<<endl;
		}
	}
}