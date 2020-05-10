#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 100005;
const int mod = 998244353;
vector<int>g[maxn];
int n;
int u[maxn];
int sz[maxn];
int p[maxn];
int pa[maxn][18];
int dep[maxn];
int d[maxn];
void mark(int now, int pre) {
    sz[now] = 1;
    for (auto i:g[now]) {
        if (i == pre) continue;
        if (!u[i]) {
            mark(i, now);
            sz[now] += sz[i];
        }
    }
}
int find_root(int now, int tar) {
    while (1) {
        int nx = 0;
        for (auto i:g[now]) {
            if (u[i] || sz[i] > sz[now]) {
                continue;
            }
            if (2 * sz[i] > tar) {
                nx = i;
                break;
            }
        }  
        if (nx) {
            now = nx;
        }
        else {
            return now;
        }
    }
}
void clear(int now) {
    for (auto i:g[now]) {
        if (!u[i]&&sz[i]) {
            sz[i] = 0;
            clear(i);
        }
    }
}
void build_ctt(int now, int pa) {
    //cout << now <<' '<<pa << endl;
    mark(now, 0);
    now = find_root(now, sz[now]);
    u[now] = 1;
    p[now] = pa;
    clear(now);
    for (auto i:g[now]) {
        if (!u[i]) {
            build_ctt(i, now);
        }
    }
}
void dfs(int now, int pre) {
    //cout << now <<' '<<pre << "here"<<endl;
    for (auto i:g[now]) {
        if (i == pre) {
            continue;
        }
        dep[i] = dep[now] + 1;
        pa[i][0] = now;
        dfs(i, now);
    }
}
int lca(int x,int y){
    if(dep[x] < dep[y]){
        swap(x,y);
    }
    int left = dep[x] - dep[y];
    for(int i=17;i>=0;i--){
        if(left >= (1<<i)){
            x = pa[x][i];
            left -= (1<<i);
        }
    }
    if(x==y)return x;
    for(int i=17;i>=0;i--){
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
void update(int now) {
    int x;
    x = now;
    while(now != 0) {
        d[now] = min(d[now], dis(now, x));
        now = p[now];
    }
}
int query(int now) {
    int ret = 1e9;
    int x;
    x = now;
    while (now != 0) {
        ret = min(ret, dis(x, now) + d[now]);
        now = p[now];
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> n >> k;
    f (n - 1) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }    
    dfs(1, 0);
    for (int i = 1 ; i < 18 ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            pa[j][i] = pa[pa[j][i-1]][i-1];
        }
    }
    memset(d, 0x3f,sizeof(d));
    //cout << "GG" << endl;
    build_ctt(1,0);
    //cout << "GG" << endl;
    update(1);
    //cout << k <<' '<<"GG" << endl;
    while (k--) {
        int op;
        int tar;
        cin >> op >> tar;
        //cout << op <<' '<<tar << endl;
        if (op == 2) {
            cout << query(tar) << '\n';
        }
        else {
            update(tar);
        }
    }
}
