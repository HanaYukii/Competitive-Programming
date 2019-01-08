#include<bits/stdc++.h>
using namespace std;
int n,m,cont[100005];
int inf=150;
int main()
{
    while(cin>>n>>m)
    {
    for(int i=0;i<n;i++)
        cin>>cont[i];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(cont[i]<=m)
        {
            ans++;
            cont[i]=inf;
        }
        else
        {
            break;
        }
    }
    for(int i=n-1;i>0;i--)
    {
        if(cont[i]<=m)
        {
            ans++;
            cont[i]=inf;
        }
        else
        {
            break;
        }
    }
    cout<<ans<<endl;
    }
}
