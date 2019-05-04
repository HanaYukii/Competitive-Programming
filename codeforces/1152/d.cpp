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
pair<int,bool> dp[2005][2005];
const int mod=1e9+7;
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n,m;
	//int now=0;
	while(cin >>n){
		n <<= 1;
		dp[0][0] = {0,1};
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				int sum = 0;
				int f=0;
				if(j){
					sum +=dp[i-1][j-1].first;
					sum %= mod;
					f |=dp[i-1][j-1].second;
				}

				if(j+1 <= i-1){
					sum += dp[i-1][j+1].first;
					sum %= mod;
					f |= dp[i-1][j+1].second;
				}
				if(f){
					dp[i][j] = {(sum+1)%mod,0};
				}
				else{
					dp[i][j] = {sum,1};
				}
			}
		}
		cout<<dp[n][0].first<<endl;
	}

}