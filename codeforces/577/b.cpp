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
	int n,m;
	while(cin >> n >> m){
		if(n>=m){
			cout<<"YES"<<endl;
			exit(0);
		}
		int dp[m+5][2] = {};
		dp[0][0] = 1;
		f(n){
			int add;
			cin >> add;
			add %= m;
			for(int j=m-1;j>=0;j--){
				int p = j-add;
				if(p<0){
					p += m;
				}
				dp[j][1] |= dp[p][0];
			}
			fr(j,0,m){
				dp[j][0] |= dp[j][1];
			}
		}
		if(dp[0][1]){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}		
}