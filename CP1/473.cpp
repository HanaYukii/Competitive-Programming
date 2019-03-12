#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    re:
    getline(cin,s);
    getline(cin,s);
    getline(cin,s);
    int cnt=1;
    string t[3000];
    int ff=0;
    for(int i=1; i<s.length(); i++)
    {
        if(s[i]!='|'&&s[i]!='0')
            ff=1;
        if(s[i]!='|'&&ff)
            t[cnt]+=s[i];
        else if(s[i]=='|')
        {
            ff=0;
            cnt++;
        }

    }
    getline(cin,s);
    int l=cnt-1;
    for(int z=1; z<l; z++)
    {
        getline(cin,s);
        for(int i=1; i<s.length(); i++)
        {
            if(s[i]!='|'&&s[i]!='0')
                ff=1;
            if(s[i]!='|'&&ff)
                t[cnt]+=s[i];
            else if(s[i]=='|')
            {
                cnt++;
                ff=0;
            }
        }
        getline(cin,s);
    }
    //cout<<l<<endl;
    int flag[3000]= {0};
    while(getline(cin,s))
    {
        if(s[0]=='+')
            goto re;
        int f1=0;
        for(int i=1; i<=cnt; i++)
        {
            if(t[i]==s)
            {
                //cout<<i<<endl;
                f1=1;
                flag[i]=1;
            }
        }
        if(f1)
        {
            int r=0,c=0;
            for(int i=0; i<l; i++)
            {
                int f=0;
                for(int j=1; j<=l; j++)
                {
                    if(flag[i*l+j]==0)
                    {
                        f=1;
                        break;
                    }
                }
                if(!f)
                    r++;
            }
            for(int i=1; i<=l; i++)
            {
                int f=0;
                for(int j=0; j<l; j++)
                {
                    if(flag[i+j*l]==0)
                    {
                        f=1;
                        break;
                    }
                }
                if(!f)
                    c++;
            }
            /*for(int i=0; i<l; i++)
            {
                for(int j=0; j<l; j++)
                {
                    cout<<flag[i*l+j+1]<<' ';
                }
                cout<<'\n';
            }*/
            cout<<r<<' '<<c<<endl;
        }
    }
}
