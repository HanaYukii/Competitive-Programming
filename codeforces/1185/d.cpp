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
const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	while(cin >> n){
		vector<ll>v;
		map<ll,int>mp;
		f(n){
			ll add;
			cin >> add;
			v.pb(add);
			mp[add] = i+1;
		}
		sort(v.begin(),v.end());
		ll dif = v[1] - v[0];
		int f = 0;
		int u = 0;
		ll pre = v[1];
		int pos = n-1;
		for(int i = 2 ; i<n;i++){
			if(v[i]-pre==dif){
				pre = v[i];
				continue;
			}
			else if(v[i]-pre!=dif&&!u){
				u=1;
				pos = i;
				continue;
			}
			else if(v[i]-pre!=dif&&u){
				f=1;
			}
		}
		if(!f){
			cout<<mp[v[pos]]<<endl;
			continue;
		}
		f = 0;
		u = 0;
		pre = v[n-2];
		pos = 0;
		dif = v[n-1] - v[n-2];
		for(int i = n-3; i>=0;i--){
			if(pre-v[i]==dif){
				pre = v[i];
				continue;
			}
			else if(pre-v[i]!=dif&&!u){
				u=1;
				pos = i;
				continue;
			}
			else if(pre-v[i]!=dif&&u){
				f=1;
			}
		}
		if(!f){
			cout<<mp[v[pos]]<<endl;
			continue;
		}
		cout<<-1<<endl;
	}

}