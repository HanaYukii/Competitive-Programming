#include<bits/stdc++.h>
using namespace std;

long long dp[100005][2];
int w[100005];
vector<int>g[100005];
void dfs(int now)
{
    for(int i:g[now])
    {
        dfs(i);
        dp[now][0]+=max(dp[i][1],dp[i][0]);
        dp[now][1]+=dp[i][0];
    }
    dp[now][1]+=w[now];
}
void f(int now,int n)
{
    if(n==2)
    {
        f(now,dp[now][1]>=dp[now][0]);
    }
    else if(n==1)
    {
        cout<<now<<' ';
        for(int i:g[now])
        {
            f(i,0);
        }
    }
    else
    {
        for(int i:g[now])
        {
            f(i,2);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>w[i];

    for(int i=0;i<n-1;i++)
    {
        int add1,add2;
        cin>>add2>>add1;
        g[add1].push_back(add2);
        dp[add2][0]=1;
    }
    int s;
    for(int i=1;i<=n;i++)
    {
        if(!dp[i][0])
        {
            s=i;
        }
        else
            dp[i][0]=0;
    }
    dfs(s);
    cout<<max(dp[s][0],dp[s][1])<<endl;
    f(s,2);
}
