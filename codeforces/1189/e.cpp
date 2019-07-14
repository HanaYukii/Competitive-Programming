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
	ll n,p,k;
	while(cin >> n >> p >> k){
		map<ll,int>mp;
		ll ans = 0;
		f(n){
			ll add;
			cin >> add;
			ll num = add;
			f(3){
				num *= add;
				num %= p;
			}
			ll mi = add * k % p;
			num -= mi;
			num += p;
			num %= p;
			ans += mp[num];
			mp[num]++;
		}
		cout << ans << endl;
	}
}