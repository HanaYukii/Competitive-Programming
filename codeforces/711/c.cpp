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
	int n,m,k;
	while(cin >> n >> m >> k){
		ll dp[n+5][m+5][k+5];
		ll c[n+5][m+5] = {};
		int cont[n+5] = {};
		ms1(dp);
		f1(n){
			cin >> cont[i];
		}
		f1(n){
			fr(j,1,m+1){
				cin >> c[i][j];
			}
		}
		if(cont[1]==0){
			f1(m){
				dp[1][i][1] = c[1][i];
			}
		}
		else{
			dp[1][cont[1]][1] = 0;
		}
		fr(i,2,n+1){
			int cur;
			cur = cont[i];
			if(cur > 0){
				fr(j,1,k+1){
					ll mi = 1e18;
					if(~dp[i-1][cur][j]){
						mi = dp[i-1][cur][j];
					}
					fr(x,1,m+1){
						if(x==cur)continue;
						if(~dp[i-1][x][j-1]){
							mi = min(mi,dp[i-1][x][j-1]);
						}
					}
					if(mi<1e18){
						dp[i][cur][j] = mi;
					}
				}
			}
			else{
				fr(zz,1,m+1){
					cur = zz;
					fr(j,1,k+1){
						ll mi = 1e18;
						if(~dp[i-1][cur][j]){
							mi = dp[i-1][cur][j];
						}
						fr(x,1,m+1){
							if(x==cur)continue;
							if(~dp[i-1][x][j-1]){
								mi = min(mi,dp[i-1][x][j-1]);
							}
						}
						if(mi<1e18){
							dp[i][cur][j] = mi + c[i][zz];
						}
					}
				}
			}
		}
		ll mi = 1e18;
		f1(m){
			if(~dp[n][i][k]){
				mi = min(mi,dp[n][i][k]);
			}
		}
		if(mi<1e18){
			cout<<mi<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
}