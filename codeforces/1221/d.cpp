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
const int mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll x[n+5],y[n+5];
		f1(n){
			cin >> x[i] >> y[i];
		}
		ll dp[n+5][3] = {};
		dp[1][0]=0;
		dp[1][1]=y[1];
		dp[1][2]=y[1]*2;
		fr(i,2,n+1){
			fr(j,0,3){
				ll Min = 2e18;
				fr(k,0,3){
					if(x[i-1]-j+k!=x[i]){
						Min = min(Min,dp[i-1][k]+j*y[i]);
					}
				}
				dp[i][j] = Min;
			}
		}
		cout << min({dp[n][0],dp[n][1],dp[n][2]})<<'\n';
	}
}
