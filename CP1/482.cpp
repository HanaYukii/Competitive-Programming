#include<bits/stdc++.h>
using namespace std;
long long bit[100005];
const int ma=100005;
long long LIS[100005];
long long LDS[100005];
int cont[100005];
map<int,int>mp;
int dis[100005];
const long long mod= 1000000007;
void addi(int p,long long k)
{
    while(p<=ma)
    {
        bit[p]+=k;
        bit[p]%=mod;
        p+=(p&-p);
    }
}
long long sum(int p)
{
    long long ans=0;
    while(p>0)
    {
        ans+=bit[p];
        ans%=mod;
        p-=(p&-p);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(bit,0,sizeof(bit));
        for(int i=0;i<n;i++)
        {
            cin>>dis[i];
            cont[i]=dis[i];
        }
        sort(dis,dis+n);
        int now=2;
        mp[dis[0]]=1;
        for(int i=1;i<n;i++)
        {
            if(dis[i]!=dis[i-1])
            {
                mp[dis[i]]=now++;
            }
        }
        for(int i=0;i<n;i++)
        {
            cont[i]=mp[cont[i]];
        }
        for(int i=0; i<n; i++)
        {
            int add=cont[i];
            LIS[i]=sum(add-1);
            LIS[i]++;
            addi(add,LIS[i]);
        }
        memset(bit,0,sizeof(bit));
        for(int i=n-1; i>=0; i--)
        {
            int add=cont[i];
            LDS[i]=sum(add-1);
            LDS[i]++;
            addi(add,LDS[i]);
        }
        long long sum=0;
        for(int i=1; i<n-1; i++)
        {
            sum+=(LIS[i]-1)*(LDS[i]-1);
            sum%=mod;
        }
        cout<<sum<<endl;
    }
}
