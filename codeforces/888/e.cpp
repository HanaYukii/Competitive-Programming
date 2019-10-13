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
		int div = n/2;
		int rem = n-div;
		ll cont[n+5] = {};
		ll cont2[n+5] = {};
		f1(div){
			cin >> cont[i];
			cont[i] %= m;
		}
		f1(rem){
			cin >> cont2[i];
			cont2[i] %= m;
		}
		vector<ll>v;
		f(1<<div){
			int cur = 1;
			ll num = 0;
			fr(j,1,div+1){
				if(i&cur){
					num += cont[j];
				}
				cur <<= 1;
			}
			num %= m;
			v.pb(num);
		}
		sort(v.begin(),v.end());
		ll ans = 0;
		f(1<<rem){
			int cur = 1;
			ll num = 0;
			fr(j,1,rem+1){
				if(i&cur){
					num += cont2[j];
				}
				cur <<= 1;
			}
			num %= m;
			ll nd = m-1-num;
			if(nd<0)nd += m;
			int idx = upper_bound(v.begin(),v.end(),nd)-v.begin();
			if(idx == 0){
				num += v.back();
			}
			else{
				num += v[idx-1];
			}
			num %= m;
			ans = max(ans,num);
		}
		cout << ans << endl;
	}		
}