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
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int pa[200005][20];
vector<int>g[200005];
int dep[200005];
void dfs(int now, int pre){
    pa[now][0] = pre;
    for(auto i:g[now]){
        if (i == pre) {
            continue;
        }
        dep[i] = dep[now] + 1;
        dfs(i, now);
    }
}
int lca(int x,int y){
    if(dep[x] < dep[y]){
        swap(x,y);
    }
    int left = dep[x] - dep[y];
    for(int i=19;i>=0;i--){
        if(left >= (1<<i)){
            x = pa[x][i];
            left -= (1<<i);
        }
    }
    if(x==y)return x;
    for(int i=19;i>=0;i--){
        if(pa[x][i]!=pa[y][i]){
            x = pa[x][i];
            y = pa[y][i];
        }
    }
    return pa[x][0];
}
int dis(int x,int y) {
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
int getpa(int x, int k) {
    int cur = x;
    int i = 0;
    while (k) {
        if (k & 1) {
            cur = pa[cur][i];
        }
        k >>= 1;
        i++;
    }
    return cur;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    f(n - 1) {
        int add1, add2;
        cin >> add1 >> add2;
        g[add1].pb(add2);
        g[add2].pb(add1);
    }
    dfs(1,1);
    f1(19){
        fr(j,1,n+1){
            pa[j][i] = pa[pa[j][i-1]][i-1];
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        //cout << dis(a, b) << '\n';
        if (dis(a, b) <= k && (k - dis(a, b)) % 2 == 0) {
            cout << "YES\n";
        }
        else if (dis(a, x) + dis(y, b) + 1 <= k && (k - dis(a, x) - dis(y, b)) % 2 == 1) {
            cout << "YES\n";
        }
        else if (dis(a, y) + dis(x, b) + 1 <= k && (k - dis(a, y) - dis(x, b)) % 2 == 1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}  
