#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	while(cin >> n >> m){
		ll cnt[m+5] = {};
		ll cc[m+5] = {};
		ll ans = 0;
		f1(m){
			cnt[i] = n/m;
			if(n%m>=i)cnt[i]++;
		}
		map<ll,ll>mp;
		f1(m){
			cc[i*i%m] += cnt[i];
		}
		f1(m-1){
			ans += cc[i] * cc[m-i];
		}
		ans += cc[0] * cc[0];
		cout << ans << endl;
	}
}