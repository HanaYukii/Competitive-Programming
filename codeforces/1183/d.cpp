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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		unordered_map<int,int>mp;
		f(n){
			int add;
			cin >> add;
			mp[add]++;
		}
		vector<int>v;
		for(auto i:mp){
			v.pb(i.second);
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		int ans = v[0];
		int last = v[0];
		for(int i=1;i<(int)v.size();i++){
			ans += min(last-1,v[i]);
			last = min(last-1,v[i]);
			if(last == 0)break;
		}
		cout << ans << '\n';
	}
}