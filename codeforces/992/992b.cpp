#include<bits/stdc++.h>
using namespace std;
int s[1000];
long long ans;
int cnt;
long long l,r;
void dfs(long long x,long long y,int now)
{
    //cout<<x<<' '<<y<<endl;
    if(now==cnt)
    {
        if(x<=r&&x>=l&&y>=l&&y<=r)
        {
            ans++;
        }
        return ;
    }
    if(x>r||y>r)
        return;
    dfs(x*s[now],y,now+1);
    dfs(x,y*s[now],now+1);
}
int main()
{
    ios_base::sync_with_stdio(0);

    long long x,y;

    cnt=0;
    cin>>l>>r>>x>>y;
    if(y%x)
    {
        cout<<0<<endl;
        return 0;
    }
    long long k=y/x;
    for(int i=2;i<=sqrt(k);i++)
    {
        if(!(k%i))
        {
            long long now=1;
            while(!(k%i))
            {
                k/=i;
                now*=i;
            }
            s[cnt++]=now;
        }
    }
    if(k>1)
        s[cnt++]=k;
    dfs(x,x,0);
    cout<<ans<<endl;
}
