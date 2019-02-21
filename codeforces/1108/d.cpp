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
	while(cin>>n){
		string s;
		cin>>s;
		pair<int,int>dp[205][3];
		if(s[0]=='R'){
			dp[0][0].first=0;
			dp[0][1].first=1;
			dp[0][2].first=1;
		}
		else if(s[0]=='G'){
			dp[0][0].first=1;
			dp[0][1].first=0;
			dp[0][2].first=1;
		}
		else{
			dp[0][0].first=1;
			dp[0][1].first=1;
			dp[0][2].first=0;
		}
		for(int i=1;i<n;i++){
			if(s[i]=='R'){
				if(dp[i-1][1].first<dp[i-1][2].first){
					dp[i][0].first=dp[i-1][1].first;
					dp[i][0].second=1;
				}
				else{
					dp[i][0].first=dp[i-1][2].first;
					dp[i][0].second=2;
				}
				if(dp[i-1][0].first<dp[i-1][2].first){
					dp[i][1].first=dp[i-1][0].first+1;
					dp[i][1].second=0;
				}
				else{
					dp[i][1].first=dp[i-1][2].first+1;
					dp[i][1].second=2;
				}
				if(dp[i-1][0].first<dp[i-1][1].first){
					dp[i][2].first=dp[i-1][0].first+1;
					dp[i][2].second=0;
				}
				else{
					dp[i][2].first=dp[i-1][1].first+1;
					dp[i][2].second=1;
				}
			}
			else if(s[i]=='G'){
				if(dp[i-1][1].first<dp[i-1][2].first){
					dp[i][0].first=dp[i-1][1].first+1;
					dp[i][0].second=1;
				}
				else{
					dp[i][0].first=dp[i-1][2].first+1;
					dp[i][0].second=2;
				}
				if(dp[i-1][0].first<dp[i-1][2].first){
					dp[i][1].first=dp[i-1][0].first;
					dp[i][1].second=0;
				}
				else{
					dp[i][1].first=dp[i-1][2].first;
					dp[i][1].second=2;
				}
				if(dp[i-1][0].first<dp[i-1][1].first){
					dp[i][2].first=dp[i-1][0].first+1;
					dp[i][2].second=0;
				}
				else{
					dp[i][2].first=dp[i-1][1].first+1;
					dp[i][2].second=1;
				}
			}
			else{
				if(dp[i-1][1].first<dp[i-1][2].first){
					dp[i][0].first=dp[i-1][1].first+1;
					dp[i][0].second=1;
				}
				else{
					dp[i][0].first=dp[i-1][2].first+1;
					dp[i][0].second=2;
				}
				if(dp[i-1][0].first<dp[i-1][2].first){
					dp[i][1].first=dp[i-1][0].first+1;
					dp[i][1].second=0;
				}
				else{
					dp[i][1].first=dp[i-1][2].first+1;
					dp[i][1].second=2;
				}
				if(dp[i-1][0].first<dp[i-1][1].first){
					dp[i][2].first=dp[i-1][0].first;
					dp[i][2].second=0;
				}
				else{
					dp[i][2].first=dp[i-1][1].first;
					dp[i][2].second=1;
				}
			}
		}
		cout<<min({dp[n-1][2].first,dp[n-1][1].first,dp[n-1][0].first})<<endl;
		string ans;
		int last;
		if(min({dp[n-1][2].first,dp[n-1][1].first,dp[n-1][0].first})==dp[n-1][0].first){
			ans+="R";
			last=0;
		}
		else if(min({dp[n-1][2].first,dp[n-1][1].first,dp[n-1][0].first})==dp[n-1][1].first){
			ans+="G";
			last=1;
		}
		else{
			ans+="B";
			last=2;
		}
		for(int i=n-1;i>0;i--){
			if(dp[i][last].second==0){
				ans+="R";
			}
			else if(dp[i][last].second==1){
				ans+="G";
			}
			else{
				ans+="B";
			}
			last=dp[i][last].second;
		}
		reverse(ans.begin(),ans.end());
		cout<<ans<<endl;
	}
}