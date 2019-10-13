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
		int mid = n/2;
		ll cont[n+5] = {};
		f(n)cin >> cont[i];
		sort(cont,cont+n);
		ll ans = 0;
		for(ll i = 1LL<<32;i;i>>=1){
			ll cur = ans + i;
			ll u = 0;
			fr(j,mid,n){
				if(cont[j]<cur){
					u += cur - cont[j];
				}
			}
			if(u<=m){
				ans += i;
			}
		}
		cout << ans << endl;
	}
}