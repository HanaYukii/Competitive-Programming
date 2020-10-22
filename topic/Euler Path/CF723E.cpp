#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define pll pair<ll,ll>
#define pii pair<int,int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int maxn = 1e6 + 50000;
const int mod = 1e9 + 7;
vector<int>g[205];
set<pair<int,int>>st;
int v[205];
int n;
void dfs(int now) {
    v[now] = 1;
    while (g[now].size()) {
        int x = g[now].back();
        g[now].pop_back();
        if (!st.count({x,now})) {
            st.insert({now,x});
            st.insert({x,now});
            dfs(x);
            if (max(now,x) != n + 1) {
                cout << now <<' '<<x<<'\n';
            }
        }
    }
}

void solve() {
    st.clear();
    int  m;
    cin >> n >> m;
    f1 (n + 1) {
        g[i].clear();
        v[i] = 0;
    }
    f (m) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    int ans = 0;
    f1(n) {
        if (g[i].size() % 2) {
            g[n+1].pb(i);
            g[i].pb(n+1);
        }
        else {
            ans++;
        }
    }
    cout << ans << '\n';
    f1(n) {
        if (!v[i]) {
            dfs(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
