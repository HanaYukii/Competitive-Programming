#include<bits/stdc++.h>
using namespace std;
int n,m,cont[400005],u[400005];
queue<int>k[26];
int main()
{
    string s;
    cin>>n>>m;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        k[s[i]-'a'].push(i);
    }
    int now=0;
    while(k[now].empty())
    {
        now++;
        if(now==26)
        {
            cout<<endl;
            return 0;
        }
    }
    while(m--)
    {
        while(k[now].empty())
        {
            now++;
            if(now==26)
            {
                cout<<endl;
                return 0;
            }
        }
        if(!k[now].empty())
        {
            int t=k[now].front();
            k[now].pop();
            u[t]=1;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(!u[i])
            cout<<s[i];
    }
    cout<<endl;
}
