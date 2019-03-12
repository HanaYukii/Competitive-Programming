#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int player[3][22];
        int mov[3][105];
        int now[3]={0};
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<22;j++)
            {
                player[i][j]=0;
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<105;j++)
            {
                mov[i][j]=0;
            }
        }
        for (int i=0; i<3; i++)
        {
            int n;
            scanf("%d",&n);
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&player[i][j]);
                if(player[i][j]<=0||player[i][j]>13)
                    player[i][j]=14;
                //cout<<player[i][j]<<' ';
                getchar();
            }
            //cout<<endl;
            for(int j=1; j<n; j++)
            {
                if(player[i][j]!=0)
                    for(int k=j+1; k<=n; k++)
                    {
                        if(player[i][j]==player[i][k])
                        {
                            player[i][j]=0;
                            player[i][k]=0;
                            break;
                        }
                    }
            }
            int cnt=0;
            for(int j=1; j<=n; j++)
            {
                if(player[i][j]!=0)
                {
                    player[i][++cnt]=player[i][j];
                }
            }
            player[i][0]=cnt;
            //cout<<cnt<<' ';
            /*for(int j=1; j<=cnt; j++)
            {
                cout<<player[i][j]<<' ';
            }
            cout<<endl;*/
        }
        for (int i=0; i<3; i++)
        {
            int n;
            scanf("%d",&n);
            mov[i][0]=n;
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&mov[i][j]);
            }
        }
        int n=0;
        int times=100000;
        int flag=0;
        /*for (int i=0; i<3; i++)
            {
                for(int j=0; j<=player[i][0]; j++)
                {
                    cout<<player[i][j]<<' ';
                }
                cout<<endl;
            }*/
        if(player[0][0]==0||player[1][0]==0||player[2][0]==0)
        {
                flag=1;
        }
        else
        while(times--)
        {

            int ac=n%3;
            int ac2=(ac+1)%3;
            //cout<<ac<<' '<<ac2<<endl;
            int m=mov[ac][now[ac]%mov[ac][0]+1]%player[ac2][0];
            if(!m)
                m=player[ac2][0];
            //cout<<m<<' '<<player[ac2][m]<<endl;
            now[ac]++;
            player[ac][player[ac][0]+1]=player[ac2][m];
            player[ac2][m]=0;
            for(int i=m; i<player[ac2][0]; i++)
                player[ac2][i]=player[ac2][i+1];
            int f=0;
            for(int i=1; i<=player[ac][0]; i++)
            {
                if(player[ac][i]==player[ac][player[ac][0]+1])
                {
                    for(int j=i; j<player[ac][0]; j++)
                    {
                        player[ac][j]=player[ac][j+1];
                    }
                    f=1;
                    break;
                }
            }
            if(f)
                player[ac][0]--;
            else
                player[ac][0]++;
            player[ac2][0]--;
            /*for (int i=0; i<3; i++)
            {
                for(int j=0; j<=player[i][0]; j++)
                {
                    cout<<player[i][j]<<' ';
                }
                cout<<endl;
            }*/
            if(player[ac][0]==0||player[ac2][0]==0)
            {
                flag=1;
                break;

            }

            n++;
        }
        //cout<<times<<endl;
        int ans=100;
        for (int i=0; i<3; i++)
        {
            for(int j=1; j<=player[i][0]; j++)
            {
                //cout<<player[i][j]<<' ';
                if(player[i][j]==14)
                    ans=i;
            }
            //cout<<endl;
        }
        if(!flag)
            puts("Good Game");
        else if(ans==100)
            puts("cnm");
        else if(ans==0)
            puts("Alice");
        else if(ans==1)
            puts("Bob");
        else
            puts("Carol");
    }

}
