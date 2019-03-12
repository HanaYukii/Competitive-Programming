#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int mod=1e9+7;

int main(){
    int n,m;
    while(cin>>n>>m){
    	vector<ll>cont;
    	cont.pb(-1e18);
        f(n){
            ll add;
            cin>>add;
            cont.pb(add);
        }
        sort(cont.begin(),cont.end());
        int dp[5005][5005]={};
        f(n+1){
        	fr(j,0,m+1){
        		dp[i][j]=0;
        	}
        }
        cont.pb(1e18);
        f1(n){
        	int now=i-(lower_bound(cont.begin(),cont.end(),cont[i]-5)-cont.begin())+1;
        	for(int j=0;j<=m;j++){
        		dp[i][j]=dp[i-1][j];
          	}
        	for(int j=1;j<=m;j++){
        		dp[i][j]=max(dp[i][j],dp[i-now][j-1]+now);
        	}
        }
       	int mx=0;
       	f1(n){
       		fr(j,1,m+1){
       			mx=max(mx,dp[i][j]);
       		}
       	}
       	cout<<mx<<endl;
    }
}