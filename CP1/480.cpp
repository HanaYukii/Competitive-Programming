#include "iostream"
#include "string"
#include "vector"
#include "cstring"
#include "fstream"
#include "cstdio"
using namespace std;
#define M 500005
#define lson l,mid,root<<1
#define rson mid+1,r,root<<1|1
#define LL long long
LL ans[M<<2];
LL mod;
LL gcdExtended(LL a, LL b, LL *x, LL *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    LL x1, y1; // To store results of recursive call
    LL gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}
LL modInverse(LL a, LL m)
{
    LL x, y;
    LL c=a;
    LL b=m;
    LL g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    else
    {
        // m is added to handle negative x
        LL res = (x%m + m) % m;
        return res;
    }
}

void PushUp(int root)
{
    LL a=ans[root<<1]%mod,b=ans[root<<1|1]%mod;
    ans[root]=(a*b)%mod;
}
void build(int l,int r,int root)
{
    if(l==r)
    {
        scanf("%I64d",&ans[root]);
        ans[root]%=mod;
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    PushUp(root);
}
void update(int p,int value,int l,int r,int root)
{
    if(l==r)
    {
        ans[root]=value;
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid) update(p,value,lson);
    else update(p,value,rson);
    PushUp(root);
}
LL Query(int L,int R,int l,int r,int root)
{
    if(L<=l&&r<=R) return ans[root]%mod;
    int mid=(l+r)>>1;
    LL ret=-1;
    if(L<=mid) ret=Query(L,R,lson);
    if(R>mid)
    {
        LL rr=Query(L,R,rson);
        if(ret!=-1)
        {
            LL a=ret%mod,b=rr%mod;
            ret=(a*b)%mod;
        }
        else ret=rr;
    }
    return ret;
}
int main()
{
    int n,q,ll,rr,p,k,v,cmd;
    int T;
    T=1;
    while(T--)
    {
        scanf("%d",&n);
        scanf("%d %lld",&q,&mod);
        build(1,n,1);
        while(q--)
        {
            scanf("%d",&cmd);
            if(cmd==2)
            {
                scanf("%d%d",&k,&v);
                update(k,v,1,n,1);
            }
            if(cmd==1)
            {
                scanf("%d%d",&ll,&rr);
                LL ans=Query(ll,rr,1,n,1);
                cout<<modInverse(ans,mod)<<endl;;
            }
        }
    }
    return 0;
}
