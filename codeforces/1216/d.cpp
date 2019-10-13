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
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		ll cont[n+5] = {};
		ll mx = 0;
		f1(n){
			cin >> cont[i];
			mx = max(mx,cont[i]);
		}
		f1(n){
			cont[i] = mx - cont[i];
		}
		ll gcd = 0;
		f1(n){
			gcd = __gcd(gcd,cont[i]);
		}
		ll ans = 0;
		f1(n){
			ans += cont[i]/gcd;
		}
		cout << ans << ' '<< gcd <<endl;
	}
}