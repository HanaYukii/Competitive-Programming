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
int v[maxn];
int dp[205][205];
int n,k;
vector<int>g[maxn];
int tmp[205];
void dfs(int now,int pre){
    int i,j;
    dp[now][0]=v[now];
    for(auto to:g[now]){
        if(to==pre)continue;
        dfs(to,now);
        ms(tmp);
        for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
                if(i+j+1>k){
                    tmp[min(i,j+1)]=max(tmp[min(i,j+1)],dp[now][i]+dp[to][j]);
                }
            }
        }
        for(int i=0;i<=k;i++){
            dp[now][i]=tmp[i];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    f1(n){
        cin >> v[i];
    }
    f(n-1){
        int add1,add2;
        cin >> add1 >> add2;
        g[add1].pb(add2);
        g[add2].pb(add1);
    }
    dfs(1,0);
    int ans = 0;
    f(k+1){
        ans = max(ans,dp[1][i]);
    }
    cout << ans << endl;
}
