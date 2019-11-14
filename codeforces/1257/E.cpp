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
const int mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    set<int>st[3];
    int a,b,c;
    cin >> a >> b >> c;
    f(a){
        int add;
        cin >> add;
        st[0].insert(add);
    }
    f(b){
        int add;
        cin >> add;
        st[1].insert(add);
    }
    f(c){
        int add;
        cin >> add;
        st[2].insert(add);
    }
    n = a + b + c;
    int dp[n+5][3] = {};
    f1(n){
        if(st[0].count(i)){
            dp[i][0] = dp[i-1][0];
        }
        else{
            dp[i][0] = dp[i-1][0] + 1;
        }
        if(st[1].count(i)){
            dp[i][1] = min(dp[i-1][0],dp[i-1][1]);
        }
        else{
            dp[i][1] = min(dp[i-1][0],dp[i-1][1]) + 1;
        }
        if(st[2].count(i)){
            dp[i][2] = min({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
        }
        else{
            dp[i][2] = min({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+1;
        }
       // cout << dp[i][0] << ' ' << dp[i][1] <<' '<<dp[i][2] << endl;
    }
    cout << min({dp[n][0],dp[n][1],dp[n][2]}) << endl;
}
