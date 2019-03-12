#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a[100005];
    while(~scanf("%lld",&a[0]))
    {
        char c;
        int cnt=1;
        while ((c = getchar()) != EOF)
        {
            if (c == ' ')
                scanf("%lld",&a[cnt++]);
            else if (c == '\n')
                break;
        }
        long long top=1000000000;
        long long btn=1;
        while(top>btn)
        {
            long long mid=((top+btn)>>1);
            int f=0;
            long long now=mid;
            for(int i=0;i<cnt;i++)
            {
                if(now>a[i])
                    now+=((a[i]+1)>>1);
                else if(now<a[i])
                {
                    now>>=1;
                }

                if(now<1)
                    f=1;
            }
            if(!f)
            {
                top=mid;
            }
            else
            {
                btn=mid+1;
            }
        }
        cout<<btn<<endl;

    }
}
