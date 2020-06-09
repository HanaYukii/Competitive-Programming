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
int a[maxn], b[maxn], to[maxn],u[maxn];
vector<int>ans;
vector<int>g[maxn];
int n;
void dfs(int now) {
    while (g[now].size()) {
        int x = g[now].back();
        g[now].pop_back();
        if (u[x]) {
            continue;
        }
        u[x] = u[((x-1)^1)+1] = 1; 
        dfs(to[x]);
        ans.push_back(x);
        ans.push_back(((x-1)^1)+1);
    }
}
bool check(int x) {
    for (int i = 0 ; i < (1 << x) ; i++) {
        g[i].clear();
    }
    ans.clear();
    f1 (n) {
        int xx = a[i] & ((1<<x) - 1);
        int yy = b[i] & ((1<<x) - 1);
        g[xx].pb(i*2);
        g[yy].pb(i*2-1);
        u[i*2] = 0;
        u[i*2-1] = 0;
        to[i*2] = yy;
        to[i*2-1] = xx;
    }
    for (int i = 0 ; i < (1<<x) ; i++) {
        if (g[i].size() % 2) {
            return 0;
        }
    }
    dfs(to[1]);
    return (int)ans.size() == n * 2;
}
void solve() {
    cin >> n;
    f1 (n) {
        cin >> a[i] >> b[i];
    }
    for (int i = 20 ; i >= 0 ; i--) {
        if (check(i)) {
            cout << i << endl;
            break;
        }
    }
    for (int i = 0 ; i < n * 2 ; i++) {
        cout << ans[i] <<' ';
    }
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}
