#include<bits/stdc++.h>
using namespace std;
int cont[20][20];
int ans[20],use[20];
int m,n,f;
void dfs(int now)
{
    if((now==n)&&!f)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d ",ans[i]);
        }
        cout<<endl;
        f=1;
        return;
    }
    for(int i=1;i<=m;i++)
    {
        if(f)
            return;
        if(!use[cont[now][i]])
        {

            use[cont[now][i]]=1;
            ans[now]=i;
            dfs(now+1);
            use[cont[now][i]]=0;
        }
    }
    return;
}
int main()
{

    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&cont[i][j]);
        }
    }
    f=0;
    dfs(0);
}
