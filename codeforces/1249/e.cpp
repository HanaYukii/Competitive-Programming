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
    int n,k;
    cin >> n >> k;
    int dp[n][2]={};
    dp[0][1]=1e5;
    vector<int>v1,v2;
    v1.pb(0);
    v2.pb(0);
    for(int i=0;i<n-1;i++){
        int add;
        cin >> add;
        v1.pb(add);
    }
    for(int i=0;i<n-1;i++){
        int add;
        cin >> add;
        v2.pb(add);
    }
    f1(n-1){
        dp[i][0] = min(dp[i-1][0],dp[i-1][1])+v1[i];
        dp[i][1] = min(dp[i-1][0]+k,dp[i-1][1])+v2[i];
    }
    f(n){
        cout<<min(dp[i][0],dp[i][1])<<' ';
    }
    cout << endl;
}
