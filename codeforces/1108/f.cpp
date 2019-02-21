#include<bits/stdc++.h>
#define Mercer register int
using namespace std;
const int P = 30;
const int maxn = 400005;
bool vis[maxn];
long long ans,ggg;
int tot, num, n, m, delta;
int h[maxn], dep[maxn], fa[maxn], anc[maxn][P + 1], mx1[maxn][P + 1];
inline const int read(){
    Mercer x = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x;
}
struct test{int x, y, z;}c[maxn];
struct edge{int v, nxt, w;}e[maxn];
int find(int x) { return (fa[x] == x) ? x : fa[x] = find(fa[x]);}
inline bool cmp(test a, test b) { return a.z < b.z;}
inline void add(int u, int v, int w){
    e[++num].v = v, e[num].w = w, e[num].nxt = h[u], h[u] = num;
    e[++num].v = u, e[num].w = w, e[num].nxt = h[v], h[v] = num;
}
inline void Kruskal(){
    sort(c + 1, c + m + 1, cmp);
    for(Mercer i = 1; i <= m; ++i){
        int p = find(c[i].x), q = find(c[i].y);
        if(p != q){
            ans += c[i].z, ++tot, vis[i] = true;
            fa[p] = q, add(c[i].x, c[i].y, c[i].z);
            if(tot == n - 1) break;
        }
    }
    if(tot!=n-1)
        ans=-1;
}
inline int query(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    int t = dep[x] - dep[y];
    for(int i = 0; i <= P; ++i)
        if((1 << i) & t) x = anc[x][i];
    for(int i = P; i >= 0; --i)
        if(anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
    return (x == y) ? x : anc[x][0];
}
inline void update(int x, int lca, int w){
    int m1 = 0, t = dep[x] - dep[lca];
    for(int i = 0; i <= P; ++i)
        if((1 << i) & t){
            m1 = max(m1, mx1[x][i]);
            x = anc[x][i];
        }
    if(w-m1==0){
    	ggg++;
    }
    delta = min(delta, w - m1);
}
inline void update(int i, int w){
    int x = c[i].x, y = c[i].y, lca = query(x, y);
    update(x, lca, w), update(y, lca, w);
}
void dfs(int u, int fa){
    for(int i = 1; i <= P; ++i)
    {
        if(dep[u] < (1 << i)) break;
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
        mx1[u][i] = max(mx1[u][i - 1], mx1[anc[u][i - 1]][i - 1]);
    }
    for(int i = h[u]; i; i = e[i].nxt){
        int v = e[i].v;
        if(v == fa) continue;
        dep[v] = dep[u] + 1;
        mx1[v][0] = e[i].w;
        anc[v][0] = u;
        dfs(v, u);
    }
}
int main(){
    n = read(), m = read(), delta = 0x7fffffff;
    for(Mercer i = 1; i <= n; ++i) fa[i] = i;
    for(Mercer i = 1; i <= m; ++i) c[i].x = read(), c[i].y = read(), c[i].z = read();
    Kruskal();
    dfs(1, 0);
       for(Mercer i = 1; i <= m; ++i)
            if(!vis[i]) update(i, c[i].z);
        cout<<ggg<<endl;
}