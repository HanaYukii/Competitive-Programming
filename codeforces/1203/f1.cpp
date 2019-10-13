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
#define pii pair<int,int>
bool cmp(pii x,pii y){
	if (x.F+x.S != y.F +y.S)
		return x.F+x.S > y.F +y.S;
	else
		return x.F > y.F;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while(cin >> n >> m){
		int now = m;
		vector<pii>pl;
		vector<pii>mi;
		f(n){
			int add1,add2;
			cin >> add1 >> add2;
			if(add2<0){
				mi.pb({add1,add2});
			}
			else{
				pl.pb({add1,add2});
			}
		}
		sort(pl.begin(),pl.end());
		sort(mi.begin(),mi.end(),cmp);
		int ans = 0;
		for(auto i:pl){
			if(now<i.F){

			}
			else{
				now += i.S;
				ans++;
			}
			//cout << now << endl;
		}
		int dp[105][105]={};
		ms1(dp);
		dp[0][0] = now;
		int mx = 0;
		for(int i=1;i<=mi.size();i++){
			pii now = mi[i-1];
			dp[i][0]=dp[i-1][0];
			for(int j=1;j<=i;j++){
				dp[i][j] = dp[i-1][j];
				if(dp[i-1][j-1]+now.S>=0&&dp[i-1][j-1]>=now.F){
					dp[i][j]=max(dp[i][j],dp[i-1][j-1]+now.S);
					mx = max(mx,j);
				}
			}
		}
		cout << ans + mx << endl;
	}
}