#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int v[300005];
vector<int>g[300005];
int pm[maxn];
int b;
int cnt;
int kk;
ll mod=998244353;

void dfs(int now,int c=0){
    v[now]=c;
    if(c==0){
        cnt++;
    }
    kk++;
    for(auto i:g[now]){
        if(v[i]==-1){
            dfs(i,c^1);
        }
        else{
            b&=v[now]!=v[i];
        }
    }
}
int main(){
    int n,m;
    ios::sync_with_stdio(0);

    cin.tie(0);
    pm[0]=1;
    for (int i = 1; i < maxn; ++i) pm[i] = pm[i - 1] * 2 % mod;
    int t;
    cin>>t;
    while(t--){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        g[i].clear();
        v[i]=-1;
    }
    for(int i=0;i<m;i++){
        int add1,add2;
        cin>>add1>>add2;
        g[add1].pb(add2);
        g[add2].pb(add1);
    }
    //memset(v,-1,sizeof(v));
    ll ans=1;
    b=1;
    f1(n){
        if(v[i]==-1){
            v[i]=1;
            kk=0;
            cnt=0;
            dfs(i,0);
            if(!b)
                break;
            ans*=(pm[cnt]+pm[kk-cnt])%mod;
            ans%=mod;
        }
    }
    if(!b){
        cout<<0<<'\n';
    }
    else{
        cout<<ans<<'\n';
    }
}
}