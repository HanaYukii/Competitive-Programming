#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const ll mod = 1e9+7;
struct E
{
	ll x,y,w;
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int c=1;c<=t;c++){
		int n,m;
		cin >> n >> m;
		vector<E>e;
		ll dp[n+5][n+5];
		f1(n){
			fr(j,1,n+1){
				if(i==j)dp[i][j]=0;
				else dp[i][j]=1e10;
			}
		}
		f(m){
			ll add1,add2,add3;
			cin >> add1 >> add2 >> add3;
			e.pb({add1,add2,add3});
			dp[add1][add2]=add3;
			dp[add2][add1]=add3;
		}
		for (int k=1; k<=n; k++){
        	for (int i=1; i<=n; i++){
            	for (int j=1; j<=n; j++){
                	if (dp[i][k] + dp[k][j] < dp[i][j]){
                   	 	dp[i][j] = dp[i][k] + dp[k][j];
                	}
            	}
        	}
		}
		int f=0;
		for(auto i:e){
			if(dp[i.x][i.y]<i.w){
				f=1;
			}
		}
		if(f){
			cout<<"Case #"<<c<<": Impossible"<<'\n';
		}
		else{
			cout<<"Case #"<<c<<": "<<m<<'\n';
			for(auto i:e){
				cout<<i.x<<' '<<i.y<<' '<<i.w<<'\n';
			}
		}
	}
}