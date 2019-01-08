#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long p(long long n,long long k)
{
    long long ret = 1;
    while (k)
    {
        if(k&1)
        {
            ret*=n;
            ret%=mod;
        }
        n *= n;
        n %= mod;
        k>>=1;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long x,k;
    cin>>x>>k;
    if(x==0)
    {
        cout<<0<<endl;
        return 0;
    }
    long long f=p(2,k+1);
    f*=(x%mod);
    f%=mod;
    long long s=p(2,k);
    s--;
    f-=s;
    if(f<0)
        f+=mod;
    f%=mod;
    cout<<f<<endl;
}
