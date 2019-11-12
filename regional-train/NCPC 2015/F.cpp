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
bool solve(){
    int n,k;
    cin >> n >> k;
    int dp[k+5][n+5]= {};
    f(n+1){
        dp[0][i] = 1;
    }
    f(k){
        int add1, add2;
        cin >> add1 >> add2;
        int d = add2 - add1;
        for(int j = 0 ; j < n + 1 ; j++){
            if(!dp[i][j])continue;
            int nxt1 = j + d;
            int nxt2 = j - d;
            if(nxt1 < n + 1){
                dp[i+1][nxt1] = 1;
            }
            if(nxt2 >= 0){
                dp[i+1][nxt2] = 1;
            }
        }
    }
    f(n+1){
        if(dp[k][i])return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ret = 1;
    int t;
    cin >> t;
    while(t--){
        ret &= solve();
    }
    if(ret){
        cout<<"possible"<<endl;
    }
    else{
        cout<<"impossible"<<endl;
    }
}
