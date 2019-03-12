#include<bits/stdc++.h>
using namespace std;
int cont[100000][2];
long long gcd(long long x,long long y)
{
    while((x%=y)&&(y%=x));
    return x+y;
}
int main()
{
    ios_base::sync_with_stdio(0);

    long long l,r,x,y;

    int cnt=0;
    long long ans=0;
    cin>>l>>r>>x>>y;
    long long m=x*y;
    for(long long i=1;i<=sqrt(m);i++)
    {
        if(!(m%i))
        {
            cont[cnt][0]=i;
            cont[cnt++][1]=m/i;
        }
    }
    for(int i=0;i<cnt;i++)
    {
        if(cont[i][0]<=r&&cont[i][0]>=l&&cont[i][1]<=r&&cont[i][1]>=l)
        {
            if(gcd(cont[i][0],cont[i][1])==x)
            {
                //cout<<cont[i][0]<<' '<<cont[i][1]<<endl;
                if(cont[i][0]==cont[i][1])
                {
                    ans++;
                }
                else
                {
                    ans+=2;
                }
            }
        }
    }
    cout<<ans<<endl;
}
