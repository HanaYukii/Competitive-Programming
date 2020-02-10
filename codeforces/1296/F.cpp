#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define F first
#define S second
const int mod = 1e9 + 7;
vector<pair<int,pair<int,int> > >g[5005];
struct s
{
    int u,v,k;
};
int mi;
int walk(int cur,int v,int k,int pre){
    if(cur == v){
        return 1;
    }
    int f = 0;
    for(auto &i:g[cur]){
        if(i.F == pre)continue;
        if(walk(i.F,v,k,cur)){
            mi = min(mi,i.S.S);
            i.S.S = max(i.S.S,k);
            f = 1;
        }
    }
    return f;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<s>vv;
    f(n-1){
        int x,y;
        cin >> x >> y;
        g[x].pb({y,{i,1}});
        g[y].pb({x,{i,1}});
    }
    int k;
    cin >> k;
    f(k){
        int u,v,c;
        cin >> u >> v >> c;
        vv.pb({u,v,c});
    }
    for(auto i:vv){
        walk(i.u,i.v,i.k,0);
        walk(i.v,i.u,i.k,0);
    }
    for(auto i:vv){
        mi = 1e7;
        walk(i.u,i.v,i.k,0);
        if(mi != i.k){
            cout << -1 << '\n';
            exit(0);
        }
    }
    int ans[n - 1];
    f1(n){
        for(auto j:g[i]){
            ans[j.S.F] = j.S.S;
        }
    }
    f(n-1){
        cout << ans[i] <<' ';
    }
    cout << '\n';
}
