#include<bits/stdc++.h>
using namespace std;
int ans[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ans[1]=1;
    ans[2]=2;
    for(int i=3;i<=1000000;i++)
    {
        ans[i]=ans[i-1]+ans[i-2]+1;
        ans[i]%=1000000007;
    }
    int n;
    cin>>n;
    while(n--)
    {
        int ask;
        cin>>ask;
        cout<<ans[ask]<<endl;
    }
}
