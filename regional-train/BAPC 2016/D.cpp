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
    int n;
    cin >> n;
    int val[n+5];
    int dp[n+5] ={};
    f1(n){
        cin >> val[i];
    }
    f1(n){
        dp[i] = 1e9;
    }
    f1(n){
        fr(j,1,i+1){
            int d = max(20 * (i - j + 1), val[i] - val[j] - 1800 + 20) + 120;
            dp[i] = min(dp[i],dp[j-1] + d);
        }
    }
    cout << dp[n] << endl;
}
