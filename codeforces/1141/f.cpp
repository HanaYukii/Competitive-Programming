#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ls(x) arr[x].child[0]
#define rs(x) arr[x].child[1]
map<ll,set<pair<int,int> > >mp;
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	ll n;
	while(cin>>n){
		mp.clear();
		ll pre[n+5]={};
		f1(n){
			ll add;
			cin>>add;
			pre[i]=pre[i-1]+add;
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mp[pre[j]-pre[i]].insert({j,i+1});
			}
		}
		int mx=0;
		ll ans=0;
		for(auto i:mp){
			vector<pair<int,int> >era;
			int ls=0;
			for(auto j:i.second){
				if(j.second>ls){
					ls=j.first;
				}
				else{
					era.pb(j);
				}
			}
			for(auto j:era){
				mp[i.first].erase(j);
			}
			if((int)mp[i.first].size()>mx){
				mx=mp[i.first].size();
				ans=i.first;
			}
		}
		cout<<mx<<'\n';
		for(auto i:mp[ans]){
			cout<<i.second<<' '<<i.first<<'\n';
		}
	}
}