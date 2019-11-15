#include<bits/stdc++.h>
using namespace std;
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    char ss[125000];
    char s[225000];
    while(~scanf("%s",ss)){
        int n = strlen(ss);
        s[0] = '*';
        for(int i = 0 ; i < n ; i++){
            s[i*2+1] = '#';
            s[i*2+2] = ss[i];
        }
        s[n * 2 + 1] = '#';
        int mxr = 0,mxp = 0;
        int ans = 0;
        n = n * 2 + 2;
        int dp[n + 5] = {};
        for(int i = 1 ; i < n ; i++){
            if(i < mxr){
                dp[i] = min(mxr - i,dp[2 * mxp - i]);
            }
            else{
                dp[i] = 1;
            }
            while(s[i-dp[i]] == s[i+dp[i]])dp[i]++;
            if( i + dp[i] > mxr){
                mxr = i + dp[i];
                mxp = i;
            }
            ans = max(ans,dp[i] - 1);
        }
        printf("%d\n",ans);
    }
}
