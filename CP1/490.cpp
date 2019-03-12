#include<bits/stdc++.h>
using namespace std;
string s[10005];
int main()
{
    srand(time(NULL));
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];
    string ans;
        for(int i=0;i<m;i++)
        {
            int cnt[26];
            memset(cnt,0,sizeof(cnt));
            for(int j=0;j<n;j++)
            {
                cnt[s[j][i]-'a']++;
            }
            int c=0;
            for(int j=0;j<26;j++)
            {
                if (cnt[j]>0)
                c++;
            }
            int t;
            t=rand()%26;
            while(cnt[t]>(n/c)||cnt[t]==0)
            {
                t=rand()%26;
            }
            ans+=(char)('a'+t);
        }
    int f=0;
    for(int i=0;i<n;i++)
    {
        if(ans==s[i])
            f=1;
    }
    if(!f)
        cout<<ans<<endl;
    else
        cout<<"-1"<<endl;



}
