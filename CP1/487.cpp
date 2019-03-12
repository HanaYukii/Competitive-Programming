#include<bits/stdc++.h>
using namespace std;
long long cnt[21][21];
int l[21];
long long a[1<<21];
long long now[21];
int m,n,f;
const long long mod=1e9+7;

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int add;
        scanf("%d",&add);
        now[add-1]++;
    }
    for(int i=0; i<n; i++)
    {
        a[1<<i]=now[i];
    }
    for(int i=1; i<n; i++)
    {
        memset(now,0,sizeof(now));
        for(int j=0; j<m; j++)
        {
            int add;
            scanf("%d",&add);
            now[add-1]++;
        }
        for(int i=;i<)
    }

}

