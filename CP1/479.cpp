#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

void multi(long long* output, long long* f, long long* g, int count)
{

    if(count<32)
    {
        for(int t=0; t<=count; t++)
        {
            for(int t1=0; t1<=count; t1++)
            {
                output[t+t1]+=f[t]*g[t1];
            }
        }
    }
    else
    {
        long long a[count/2+1];
        long long c[count/2+1];
        long long b[count/2+1];
        long long d[count/2+1];

        long long ac[count+1];
        long long bd[count+1];

        long long mid[count+1];

        memset(ac,0,sizeof(ac));
        memset(bd,0,sizeof(bd));
        memset(mid,0,sizeof(mid));


        for(int t=0; t<=count/2; t++)
        {
            b[t]=f[t];
            d[t]=g[t];
        }
        for(int t=0; t<=count-count/2-1; t++)
        {
            a[t]=f[t+count/2+1];
            c[t]=g[t+count/2+1];
        }

        multi(bd,b,d,count/2);
        multi(ac,a,c,count-count/2-1);

        for(int t=0; t<=count-count/2-1; t++)
        {
            b[t]+=a[t];
            d[t]+=c[t];
        }

        multi(mid,b,d,count/2);

        for(int t=0; t<=count/2*2+1; t++)
            mid[t]-=bd[t];
        for(int t=0; t<=(count-count/2-1)*2+1; t++)
            mid[t]-=ac[t];

        for(int t=0; t<=count/2*2+1; t++)
        {
            output[t]+=bd[t];
            output[t+count/2+1]+=mid[t];
        }
        for(int t=0; t<=2*(count-count/2-1)+1; t++)
            output[t+2*(count/2+1)]+=ac[t];

    }
    return ;
}

int main()
{
    long long in_a[65536]={0};
    int T;
    int n;

    scanf("%d %d",&n,&T);

    for(int t=0; t<n; t++)
    {
        int add;
        scanf("%d",&add);
        in_a[add]++;
    }

    long long output[131073]={0};

    multi(output,in_a,in_a,65536);
    for(int t=0; t<131073; t++)
    {
        if(!t&1)
        {
            output[t]-=in_a[t>>1]*in_a[t>>1];
            output[t]>>=1;
            output[t]+=in_a[t>>1]*(in_a[t>>1]-1)>>1;
        }
        else
        {
            output[t]>>=1;
        }
    }
    cout<<endl;
    while(T--)
    {
        int add;
        cin>>add;
        cout<<output[add]<<endl;
    }
    return 0;
}
