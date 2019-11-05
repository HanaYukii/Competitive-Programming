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
#define F first
#define S second

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,d;
    cin >> n >> d;
    int dp[n+5][d+5]={};
    int pre[n+5];
    f1(n){
        int add;
        cin >> add;
        pre[i] = pre[i-1] + add;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=d+1;j++){
            int mi = 1e9;
            for(int k=0;k<i;k++){
                if(dp[k][j-1]==-1)continue;;
                int cur = pre[i]-pre[k];
                int rem = cur % 10;
                cur /= 10;
                cur *= 10;
                if(rem>=5){
                    cur += 10;
                }
                mi = min(mi,dp[k][j-1] + cur);
            }
            if(mi == 1e9)continue;
            dp[i][j] = mi ;
        }
    }
    int mi = 1e9;
    for(int i=1;i<=d+1;i++){
        if(~dp[n][i])mi = min(mi,dp[n][i]);
    }
    cout << mi << endl;
}
