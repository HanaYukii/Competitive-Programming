#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    ll dp[20005] = {};
    f1(20000){
        dp[i] = 1e18;
    }
    dp[0] = 0;
    f(k){
        int add1, add2;
        cin >> add1 >> add2;
        for(int i = 0 ; i < n ; i++){
            dp[i+add1] = min(dp[i+add1],dp[i] + add2);
        }
    }
    ll mi = 1e18;
    for(int i = n ; i <= 20000 ;i++ ){
        mi = min(mi,dp[i]);
    }
    cout << mi << '\n';
}
