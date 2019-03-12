#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    char b[m][n*4];
    int h[m],mxh=-1;
    for(int i=0; i<m; i++)
    {
        h[i]=-1;
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<4*n; j++)
        {
            b[i][j]='.';
        }
    }
    while(n--)
    {
        string c;
        cin>>c;
        string s;
        cin>>s;

        int rr=m-1;
        int hh;
        if(c=="O"||c=="L"||c=="J")
        {
            for(int i=0; i<s.length(); i++)
            {
                if(s[i]=='<')
                    rr--;
                else
                    rr++;
                rr=min(m-1,rr);
                rr=max(1,rr);
            }
        }
        else if(c=="Z"||c=="S"||c=="T")
        {
            for(int i=0; i<s.length(); i++)
            {
                if(s[i]=='<')
                    rr--;
                else
                    rr++;
                rr=min(m-1,rr);
                rr=max(2,rr);
            }
        }
        else
        {
            for(int i=0; i<s.length(); i++)
            {
                if(s[i]=='<')
                    rr--;
                else
                    rr++;
                rr=min(m-1,rr);
                rr=max(0,rr);
            }
        }

        if(c=="O")
        {
            hh=max(h[rr],h[rr-1]);
            b[rr][hh+1]='O';
            b[rr][hh+2]='O';
            b[rr-1][hh+1]='O';
            b[rr-1][hh+2]='O';
            h[rr]=hh+2;
            h[rr-1]=hh+2;
            mxh=max(mxh,hh+2);
        }
        else if(c== "L")
        {
            hh=max(h[rr],h[rr-1]);
            b[rr][hh+1]='O';
            b[rr-1][hh+3]='O';
            b[rr-1][hh+1]='O';
            b[rr-1][hh+2]='O';
            h[rr]=hh+1;
            h[rr-1]=hh+3;
            mxh=max(mxh,hh+3);
        }
        else if(c== "J")
        {
            hh=max(h[rr],h[rr-1]);
            b[rr-1][hh+1]='O';
            b[rr][hh+3]='O';
            b[rr][hh+1]='O';
            b[rr][hh+2]='O';
            h[rr]=hh+3;
            h[rr-1]=hh+1;
            mxh=max(mxh,hh+3);
        }
        else if(c== "I")
        {
            hh=h[rr];
            b[rr][hh+4]='O';
            b[rr][hh+3]='O';
            b[rr][hh+1]='O';
            b[rr][hh+2]='O';
            h[rr]=hh+4;
            mxh=max(mxh,hh+4);
        }
        else if(c== "Z")
        {
            hh=max({h[rr],h[rr-1],h[rr-2]-1});
            b[rr-1][hh+2]='O';
            b[rr-1][hh+1]='O';
            b[rr-2][hh+2]='O';
            b[rr][hh+1]='O';
            h[rr]=hh+1;
            h[rr-1]=hh+2;
            h[rr-2]=hh+2;
            mxh=max(mxh,hh+2);
        }
        else if(c== "S")
        {
            hh=max({h[rr]-1,h[rr-1],h[rr-2]});
            b[rr-1][hh+2]='O';
            b[rr-1][hh+1]='O';
            b[rr][hh+2]='O';
            b[rr-2][hh+1]='O';
            h[rr-2]=hh+1;
            h[rr-1]=hh+2;
            h[rr]=hh+2;
            mxh=max(mxh,hh+2);
        }
        else if(c== "T")
        {
            hh=max({h[rr]-1,h[rr-1],h[rr-2]-1});
            b[rr-2][hh+2]='O';
            b[rr-1][hh+1]='O';
            b[rr-1][hh+2]='O';
            b[rr][hh+2]='O';
            h[rr-2]=hh+2;
            h[rr-1]=hh+2;
            h[rr]=hh+2;
            mxh=max(mxh,hh+2);
        }
        //cout<<mxh<<endl;
        if(c=="L"||c=="J"||c=="S"||c=="Z")
        {
            int f=0;
            for(int i=0; i<m; i++)
            {
                if(b[i][hh+1]=='.')
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                for(int i=hh+1; i<=mxh; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        b[j][i]=b[j][i+1];
                    }
                }
                for(int i=0; i<m; i++)
                {
                    h[i]=-1;
                    for(int j=mxh; j>=0; j--)
                    {
                        if(b[i][j]=='O')
                        {
                            h[i]=j;
                            break;
                        }
                    }
                }
                mxh--;
            }

        }
        else if(c=="T"||c=="O")
        {
            int f=0;
            hh++;
            for(int i=0; i<m; i++)
            {
                if(b[i][hh+1]=='.')
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                for(int i=hh+1; i<=mxh; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        b[j][i]=b[j][i+1];
                    }
                }
                mxh--;
            }
            hh--;
            f=0;
            for(int i=0; i<m; i++)
            {
                if(b[i][hh+1]=='.')
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                for(int i=hh+1; i<=mxh; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        b[j][i]=b[j][i+1];
                    }
                }
                mxh--;
            }
            for(int i=0; i<m; i++)
            {
                h[i]=-1;
                for(int j=mxh; j>=0; j--)
                {
                    if(b[i][j]=='O')
                    {
                        h[i]=j;
                        break;
                    }
                }
            }
        }
        else
        {
            int f=0;
            hh+=3;
            for(int i=0; i<m; i++)
            {
                if(b[i][hh+1]=='.')
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                for(int i=hh+1; i<=mxh; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        b[j][i]=b[j][i+1];
                    }
                }
                mxh--;
            }
            hh--;
            f=0;
            for(int i=0; i<m; i++)
            {
                if(b[i][hh+1]=='.')
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                for(int i=hh+1; i<=mxh; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        b[j][i]=b[j][i+1];
                    }
                }
                mxh--;
            }
            for(int i=0; i<m; i++)
            {
                h[i]=-1;
                for(int j=mxh; j>=0; j--)
                {
                    if(b[i][j]=='O')
                    {
                        h[i]=j;
                        break;
                    }
                }
            }
            hh--;
            f=0;
            for(int i=0; i<m; i++)
            {
                if(b[i][hh+1]=='.')
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                for(int i=hh+1; i<=mxh; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        b[j][i]=b[j][i+1];
                    }
                }
                mxh--;
            }
            for(int i=0; i<m; i++)
            {
                h[i]=-1;
                for(int j=mxh; j>=0; j--)
                {
                    if(b[i][j]=='O')
                    {
                        h[i]=j;
                        break;
                    }
                }
            }
            hh--;
            f=0;
            for(int i=0; i<m; i++)
            {
                if(b[i][hh+1]=='.')
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                for(int i=hh+1; i<=mxh; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        b[j][i]=b[j][i+1];
                    }
                }
                mxh--;
            }
            for(int i=0; i<m; i++)
            {
                h[i]=-1;
                for(int j=mxh; j>=0; j--)
                {
                    if(b[i][j]=='O')
                    {
                        h[i]=j;
                        break;
                    }
                }
            }
        }
        /*for(int j=2*m-1; j>=0; j--)
        {
            for(int i=0; i<m; i++)
            {
                cout<<b[i][j];
            }
            cout<<endl;
        }*/
    }
    cout<<mxh+1<<endl;
}
