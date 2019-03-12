#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;
vector<pair<int,int> >g[maxn];
ll w[maxn];
ll dp[maxn];
ll ans;
void dfs(int now,int pre){
    vector<ll>bt;
    for(auto i:g[now]){
        if(i.first==pre)continue;
        dfs(i.first,now);
        bt.pb(dp[i.first]-i.second);
    }
    ll fir=0,sec=0;
    sort(bt.begin(),bt.end());
    if(bt.size()){
        fir=max(fir,bt[bt.size()-1]);
    }
    if(bt.size()>=2){
        sec=max(sec,bt[bt.size()-2]);
    }
    dp[now]=w[now]+fir;
    ans=max(ans,w[now]+fir+sec);
}
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    while(cin>>n){
        f1(n)cin>>w[i];
        f1(n-1){
            int add1,add2,w;
            cin>>add1>>add2>>w;
            g[add1].pb({add2,w});
            g[add2].pb({add1,w});
        }
        ans=0;
        dfs(1,0);
        cout<<ans<<endl;
    }
    

}