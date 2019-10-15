#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
vector<int>g[maxn];
int deg[maxn];
int dp[maxn][2];
void dfs(int now,int pre){
    vector<int>d1;
    dp[now][1] = deg[now] - 1;
    for(auto i:g[now]){
        if(i==pre)continue;
        dfs(i,now);
        dp[now][0] = max(dp[now][0],dp[i][0]);
        if(g[i].size()>1){
            d1.pb(dp[i][1]);
            dp[now][1] = max(dp[now][1],deg[now]-1+dp[i][1]);
        }
    }
    sort(d1.rbegin(),d1.rend());
    int x = deg[now] + 1;
    f(2){
        if(i<(int)d1.size()){
            x += d1[i];
        }
    }
    dp[now][0] = max(dp[now][0],x);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        f1(n)g[i].clear();
        f1(n){
            dp[i][0] = dp[i][1] = 0;
        }
        f(n-1){
            int add1,add2;
            cin >> add1 >> add2;
            g[add1].pb(add2);
            g[add2].pb(add1);
        }
        if(n<=2){
            cout<<2<<'\n';
            continue;
        }
        int rt = 0;
        f1(n){
            deg[i] = g[i].size();
            if(deg[i]>1)rt = i;
        }
        dfs(rt,rt);
        cout<<dp[rt][0]<<'\n';
    }
}