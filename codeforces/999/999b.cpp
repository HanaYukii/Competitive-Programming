#include<bits/stdc++.h>
using namespace std;
int n,m,cont[100005];
int inf=150;
int main()
{
    string s;
    while(cin>>n>>s)
    {
        for(int i=1;i<=n;i++)
        {
            if(!(n%i))
            {
                for(int j=1;j<=(i)/2;j++)
                {
                    char c=s[j-1];
                    s[j-1]=s[i-j];
                    s[i-j]=c;
                }
                //cout<<s<<endl;
            }

        }
        cout<<s<<endl;
    }

}
