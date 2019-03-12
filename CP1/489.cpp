#include<bits/stdc++.h>
using namespace std;
int adj[100005];
int use[100005];
int mod=1000000007;
long long bigmod(long long b,long long p,long long m)
{
    long long ret=1;
    long long now=b%m;
    while(p)
    {
        if(p&1)
        {
            ret=ret*now;
            ret%=m;
        }
        now=now*now;
        now%=m;
        p>>=1;
    }
    return ret;
}
int main()
{
    while(1)
    {
        long long a,b,c;
        cin>>a>>b;
        cout<<(bigmod(a,b,mod)>bigmod(b,a,mod))<<endl;
    }

}
