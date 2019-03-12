#include<bits/stdc++.h>
using namespace std;
long long pre[55];
int dp[55][55];
int n,m;

int main()
{
    int n;
    cin>>n;
    int now[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>now[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        while(now[i]!=i)
        {
            cnt++;
            int tmp=now[i];
            now[i]=now[tmp];
            now[tmp]=tmp;
            if(cnt>3*n)
                goto endd;
        }

    }
    endd:
    if(cnt<=3*n&&!((3*n-cnt)&1))
    {
        puts("Petr");
    }
    else
    {
        puts("Um_nik");
    }
}
