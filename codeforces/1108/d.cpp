#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;


int main(void){
	ios_base::sync_with_stdio(false);
	int n;
	while(cin >> n){
		int dp[n+5][3] = {};
		int pre[n+5][3] = {};
		f1(n){
			fr(j,0,3){
				dp[i][j] = 1e9;
			}
		}
		string c ="RGB";
		string s;
		cin >> s;
		s = " "+s;
		f1(n){
			fr(j,0,3){
				if(s[i]==c[j]){
					fr(k,0,3){
						if(k==j)continue;
						if(dp[i-1][k]<dp[i][j]){
							dp[i][j] = dp[i-1][k];
							pre[i][j] = k;
						}
					}
				}
				else{
					fr(k,0,3){
						if(k==j)continue;
						if(dp[i-1][k]+1<dp[i][j]){
							dp[i][j] = dp[i-1][k] + 1;
							pre[i][j] = k;
						}
					}
				}
			}
		}
		string ans;
		int num =1e9;
		int idx = 0;
		f(3){
			if(dp[n][i]<num){
				num = dp[n][i];
				idx = i;
			}
		}
		for(int i=n;i>=1;i--){
			ans += c[idx];
			idx = pre[i][idx];
		}
		reverse(ans.begin(),ans.end());
		cout << num << endl;
		cout << ans << endl;
	}
}