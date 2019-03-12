#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
long long cont[maxn];
long long dp[maxn],pre[maxn];
int main()
{
    int n;
    while(cin>>n)
    {
        memset(pre,0,sizeof(pre));
        for(int i=1; i<=n; i++)
        {
            cin>>cont[i];
            pre[i]=(cont[i]==0?pre[i-1]+1:pre[i-1]);
        }

        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1; i<=n; i++)
        {
            dp[i]=cont[i]*dp[i-1];
            if(cont[i]==0)
                dp[i]=1;
        }
        long long maxx=-1LL<<50;
        for(int i=1; i<=n; i++)
        {
            for(int j=i; j<=n; j++)
            {
                long long ans=1;
                for(int k=i;k<=j;k++)
                {
                    ans*=cont[k];
                }
                maxx=max(ans,maxx);
            }
        }
        cout<<maxx<<endl;
    }
}
