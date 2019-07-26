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
const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,m,k;
	while(cin >> n >> m >> k){
		ll pre[n+5][11] = {};
		ll mi[11] = {};
		ll cont[n+5] = {};
		ll ans = 0;
		f1(n){
			cin >> cont[i];
			fr(j,0,m){
				if(i%m!=j){
					pre[i][j] = pre[i-1][j] + cont[i];
					mi[j] = min(mi[j],pre[i][j]);
				}
				else{
					pre[i][j] = pre[i-1][j] + cont[i] - k;
					ans = max(ans,pre[i][j] - mi[j]);
					mi[j] = min(mi[j],pre[i][j]);
				}
			}
		}
		cout << ans << endl;
	}
}