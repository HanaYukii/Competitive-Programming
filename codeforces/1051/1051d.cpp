#include<bits/stdc++.h>
using namespace std;
long long dp[1005][2005][2];
#define mod 998244353

int main()
{
    ios_base::sync_with_stdio(0);
    int n,k;
    while(cin>>n>>k){
        dp[1][1][0]=2;
        dp[1][2][1]=2;
        for(int i=2;i<=n;i++){
            for(int j=k;j>=1;j--){
                if(j>=2){
                dp[i][j][1]+=dp[i-1][j-2][1];
                dp[i][j][1]%=mod;
                }
                dp[i][j][1]+=dp[i-1][j-1][0]*2;
                dp[i][j][1]%=mod;
                dp[i][j][1]+=dp[i-1][j][1];
                dp[i][j][1]%=mod;
                dp[i][j][0]+=dp[i-1][j][0]+dp[i-1][j][1]*2;
                dp[i][j][0]%=mod;
                dp[i][j][0]+=dp[i-1][j-1][0];
                dp[i][j][0]%=mod;
            }
        }
        cout<<(dp[n][k][0]+dp[n][k][1])%mod<<endl;
    }
}
