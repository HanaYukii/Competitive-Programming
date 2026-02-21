#include<bits/stdc++.h>
using namespace std;
 
using pll = pair<long long,long long>;
using pii = pair<int,int>;
const int MAXN = 1e6 + 50000;
const int mod = 1e9 + 7;
int a[MAXN], b[MAXN], to[MAXN],u[MAXN];
vector<int>ans;
vector<int>g[MAXN];
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
    for (int i = 1; i <= n; i++) {
        int xx = a[i] & ((1<<x) - 1);
        int yy = b[i] & ((1<<x) - 1);
        g[xx].push_back(i*2);
        g[yy].push_back(i*2-1);
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
    for (int i = 1; i <= n; i++) {
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
