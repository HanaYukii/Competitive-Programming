#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9 + 7;
int n, m;
ll mi, mx;
ll ans;
vector<pair<int,int> >g[maxn];
int sz[maxn];
void dfs(int now,int pre,int val){
    sz[now] = 1;
    for(auto i:g[now]){
        if(i.F != pre){
            dfs(i.F,now,i.S);
            sz[now] += sz[i.F];
        }
    }
    if(sz[now]&1){
        mi += val;
    }
    mx += (ll)min(n-sz[now],sz[now]) * val;
}
void init(){
    cin >> n;
    n *= 2;
    f1(n){
        g[i].clear();
    }
    f(n-1){
        int add1, add2, add3;
        cin >> add1 >> add2 >> add3;
        g[add1].pb({add2,add3});
        g[add2].pb({add1,add3});
    }
    mi = 0, mx = 0;
}
void solve(){
    dfs(1,0,0);
    cout << mi <<' '<<mx << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        init();
        solve();
    }
}
