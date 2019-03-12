#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
int cont[maxn];
int dp[maxn],last[maxn];
int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
        cin>>cont[i];
    memset(dp,10000,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>=1;j--)
        {
            if(cont[i]>m)
                continue;
            else if(last[j-1]>=cont[i])
            {
                if(dp[j-1]<dp[j])
                {
                    dp[j]=dp[j-1];
                    last[j]=last[j-1]-cont[i];
                }
                else if(dp[j-1]==dp[j])
                {
                    last[j]=max(last[j],last[j-1]-cont[i]);
                }
            }
            else
            {
                if(dp[j-1]+1<dp[j])
                {
                    dp[j]=dp[j-1]+1;
                    last[j]=m-cont[i];
                }
                else if(dp[j-1]+1==dp[j])
                {
                    last[j]=max(last[j],m-cont[i]);
                }
            }

        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dp[i]>k)
        {
            cout<<i-1<<endl;
            break;
        }

    }
}
