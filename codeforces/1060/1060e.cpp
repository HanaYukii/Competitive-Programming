#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
vector<int>g[maxn];
int dep[maxn],sz[maxn];
void dfs(int now,int pre){
    sz[now]=1;
    for(auto i:g[now]){
        if(i!=pre){
            dep[i]=dep[now]+1;
            dfs(i,now);
            sz[now]+=sz[i];
        }
    }
}
int main()
{
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    while(cin>>n){
        ms(dep);ms(sz);
        f(n)
            g[i].clear();
        f(n-1){
            int add1,add2;
            cin>>add1>>add2;
            add1--,add2--;
            g[add1].pb(add2);
            g[add2].pb(add1);
        }
        dfs(0,-1);
        ll ans=0;
        ll odd=0;
        for(int i=1;i<n;i++){
            ans+=sz[i]*(ll)(n-sz[i]);
            if(dep[i]&1){
                odd++;
            }
        }
        ans+=odd*(n-odd);
        cout<<ans/2<<endl;
    }
}