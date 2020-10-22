#include<bits/stdc++.h>
using namespace std;
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    char ss[125000];
    char s[225000];
    while(~scanf("%s",ss)){
        int n = strlen(ss);
        // 填充字串
        s[0] = '#';
        for(int i = 0 ; i < n ; i++){
            s[i*2+1] = '#';
            s[i*2+2] = ss[i];
        }
        s[n * 2 + 1] = '#';
        int mxr = 0, mxp = 0; // 目前最右點，最右點的中點
        int ans = 0;
        n = n * 2 + 2;
        int dp[n + 5] = {};
        for(int i = 1 ; i < n ; i++){ //左至右枚舉所有中點
            if(i <= mxr){ // 此位置目前在先前找到的對稱子字串中，有對應的PART
                dp[i] = min(mxr - i,dp[2 * mxp - i]);
            }
            else{
                dp[i] = 0;
            }
            if (i + dp[i] >= mxr){
               while(s[i-dp[i]] == s[i+dp[i]])dp[i]++; // 暴力比對
               dp[i]--;
            }
            if( i + dp[i] > mxr){ // 此位置為中心 找到更右的對稱子字串
                mxr = i + dp[i];
                mxp = i;
            }
            ans = max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
}
