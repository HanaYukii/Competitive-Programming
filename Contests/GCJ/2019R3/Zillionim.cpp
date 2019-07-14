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
const ll bb=1e12;
const ll sb=1e10;
int main(){
	int t,w;
	cin >> t >> w;
	while(t--){
		vector<pair<ll,ll> >v;
		v.pb(1,bb);
		while(1){
			vector<pair<ll,ll> >nv;
			ll add;
			cin >> add;
			int idx=0;
			for(int i=0;i<v.size();i++){
				if(v[i].first<=add&&v[i].second>=add){
					idx = i;
					break;
				}
			}
			if(add-v[idx].first>=sb){
				v.pb({v[idx].first,add-1});
			}
			if(v[idx].second-add>=2*sb-1){
				v.pb({add+sb+1,v[idx].second});
			}
			for(int i=0;i<v.size();i++){
				if(i!=idx){
					nv.pb(v[i]);
				}
			}
			sort(nv.begin(),nv.end());
			
		}
	}
}