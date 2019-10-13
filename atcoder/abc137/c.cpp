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
#define pii pair<int,int>

int main(){
	ll n;
	cin >> n;
	map<string,ll>mp;
	ll ans = 0;
	f(n){
		string s;
		cin >> s;
		sort(s.begin(),s.end());
		ans += mp[s];
		mp[s]++;
	}
	cout << ans << endl;
}