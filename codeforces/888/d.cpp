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
	while(cin >> n >> m){
		ll ans = 0;
		if(m>=4){
			ans += n *(n-1) * (n-2) * (n-3) / 24 * 9;
		}
		if(m>=3){
			ans += n *(n-1) * (n-2) / 6 * 2;
		}
		if(m>=2){
			ans += n *(n-1)/2;
		}
		ans++;
		cout << ans << endl;
	}		
}