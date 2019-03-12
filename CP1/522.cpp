#include<bits/stdc++.h>
using namespace std;
int dp[231073],cont[230173];
int n,m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int mx=0,ml=0;
    for(int i=0;i<n;i++)
    {
        cin>>cont[i];
        dp[cont[i]]=dp[cont[i]-1]+1;
        if(dp[cont[i]]>ml)
        {
            mx=cont[i];
            ml=dp[cont[i]];
        }
    }
    int now=mx-ml+1;
    cout<<ml<<endl;
    for(int i=0;i<n;i++)
    {
        if(now==mx+1)
            break;
        if(cont[i]==now)
        {
            now++;
            cout<<i+1<<' ';
        }
    }
    cout<<endl;
}
