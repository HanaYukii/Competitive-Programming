#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long a[25];
    while(~scanf("%llu",&a[0]))
    {
        char c;
        int cnt=1;
        while ((c = getchar()) != EOF)
        {
            if (c == ' ')
                scanf("%llu",&a[cnt++]);
            else if (c == '\n')
                break;
        }
        sort(a,a+cnt);
        unsigned long long sum=0;
        for(int i=0; i<cnt; i++)
        {
            sum+=a[i];
        }
        if((unsigned long long)sqrt(sum)*(unsigned long long)sqrt(sum)!=(sum))
        {
            puts("No");
        }
        else
        {
            sum=(unsigned long long)sqrt(sum);
            if(cnt==1)
            {
                if((unsigned long long)sqrt(a[0])*(unsigned long long)sqrt(a[0])==(a[0]))
                {
                    puts("Yes");
                    printf("%llu\n",(unsigned long long)sqrt(a[0]));
                }
                else
                {
                    puts("No");
                }
            }
            else if(cnt==4)
            {
                sort(a,a+4);
                unsigned long long f,s;
                f=(unsigned long long)sqrt(a[0]);
                s=(unsigned long long)sqrt(a[3]);
                if((a[1]==a[2])&&(a[2]==f*s)&&(f*f==a[0])&&(s*s==a[3]))
                {
                    puts("Yes");
                    printf("%llu %llu\n",f,s);
                }
                else
                {
                    puts("No");
                }
            }
            else if(cnt==9)
            {
                unsigned long long ans[3];
                ans[0]=(unsigned long long)sqrt(a[0]);
                ans[2]=(unsigned long long)sqrt(a[8]);
                ans[1]=sum-ans[0]-ans[2];
                unsigned long long cmp[9];
                for(int i=0; i<3; i++)
                {
                    for(int j=0; j<3; j++)
                    {
                        cmp[i*3+j]=ans[i]*ans[j];
                    }
                }
                sort(cmp,cmp+9);
                int f=0;
                for(int i=0; i<9; i++)
                {
                    if(cmp[i]!=a[i])
                        f=1;
                }
                if(f)
                    puts("No");
                else
                {
                    puts("Yes");
                    printf("%llu %llu %llu\n",ans[0],ans[1],ans[2]);
                }

            }
            else if(cnt==16)
            {
                unsigned long long ans[4];
                ans[0]=(unsigned long long)sqrt(a[0]);
                ans[3]=(unsigned long long)sqrt(a[15]);
                ans[1]=a[1]/ans[0];
                ans[2]=a[14]/ans[3];
                unsigned long long cmp[16];
                for(int i=0; i<4; i++)
                {
                    for(int j=0; j<4; j++)
                    {
                        cmp[i*4+j]=ans[i]*ans[j];
                    }
                }
                sort(cmp,cmp+16);
                int f=0;
                for(int i=0; i<16; i++)
                {
                    if(cmp[i]!=a[i])
                        f=1;
                }
                if(f)
                    puts("No");
                else
                {
                    puts("Yes");
                    printf("%llu %llu %llu %llu\n",ans[0],ans[1],ans[2],ans[3]);
                }

            }
            else if(cnt==25)
            {
                unsigned long long ans[5];
                ans[0]=(unsigned long long)sqrt(a[0]);
                ans[4]=(unsigned long long)sqrt(a[24]);
                ans[1]=a[1]/ans[0];
                ans[3]=a[23]/ans[4];
                ans[2]=sum-ans[0]-ans[1]-ans[3]-ans[4];
                unsigned long long cmp[25];
                for(int i=0; i<5; i++)
                {
                    for(int j=0; j<5; j++)
                    {
                        cmp[i*5+j]=ans[i]*ans[j];
                    }
                }
                sort(cmp,cmp+25);
                int f=0;
                for(int i=0; i<25; i++)
                {
                    if(cmp[i]!=a[i])
                        f=1;
                }
                if(f)
                    puts("No");
                else
                {
                    puts("Yes");
                    printf("%llu %llu %llu %llu %llu\n",ans[0],ans[1],ans[2],ans[3],ans[4]);
                }

            }
            else
            {
                puts("No");
            }
            memset(a,0,sizeof(a));
        }
    }
}
