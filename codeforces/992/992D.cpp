#include<bits/stdc++.h>
using namespace std;
#define maxn (int)2.01e5
const long long inf=(2.01e13);
int n,ans,nxt[maxn];
long long cont[maxn],pre[maxn],now,k;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>cont[i];
        pre[i]=pre[i-1]+cont[i];
        //cout<<pre[i]<<' ';
    }
    nxt[n]=n+1;
    for(int i=n-1;i>=0;i--)
    {
        if(cont[i+1]==1)
            nxt[i]=nxt[i+1];
        else
            nxt[i]=i+1;
    }
    for(int i=1;i<=n;i++)
    {
        now=1;
        for(int j=i;j<=n;j=nxt[j])
        {
            if(inf/now<=cont[j])
                break;
            now*=cont[j];
            if(now%k)
                continue;
            long long sum=now/k;
            if(pre[nxt[j]-1]-pre[i-1]>=sum&&pre[j]-pre[i-1]<=sum)
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}