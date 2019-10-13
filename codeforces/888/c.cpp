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
const int mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	string s;
	while(cin >> s){
		n = s.size();
		s = " "+s;
		vector<int>v[26];
		f(26){
			v[i].pb(0);
		}
		f1(n){
			v[s[i]-'a'].pb(i);
		}
		f(26){
			v[i].pb(n+1);
		}
		int ans = n;
		f(26){
			int mx = 0;
			for(int j = 1 ; j < v[i].size(); j++){
				mx = max(mx,v[i][j]-v[i][j-1]);
			}
			ans = min(ans,mx);
		}
		cout << ans << endl;
	}		
}