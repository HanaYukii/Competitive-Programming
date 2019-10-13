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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	vector<int>d;
	int n = s.size();
	f1(n-1){
		d.pb(((s[i]-s[i-1])+10)%10);
	}
	f(10){
		fr(j,0,10){
			int x = i;
			int y = j;
			int dp[10][2] ;
			fr(k,0,2){
				fr(l,0,10){
					dp[l][k] = 1000;
				}
			}
			dp[x][0] = dp[y][0] = dp[x][1] = dp[y][1] = 0;
			int t = 20;
			while(t--){
				fr(k,0,10){
					dp[(k+x)%10][1] = min(dp[(k+x)%10][1],dp[k][0]+1);
					dp[(k+y)%10][1] = min(dp[(k+y)%10][1],dp[k][0]+1);
				}
				fr(k,0,10){
					dp[k][0] = dp[k][1];
				}
			}
			int f = 0;
			int tot = 0;
			for(auto k:d){
				if(dp[k][0]==1000){
					f = 1;
					break;
				}
				else{
					tot += dp[k][0];
				}
			}
			if(f){
				cout << -1 <<' ';
			}
			else
				cout << tot <<' ';
		}
		cout << endl;
	}
}