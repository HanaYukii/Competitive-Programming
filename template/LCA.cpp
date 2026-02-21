// Lowest Common Ancestor (binary lifting)
#include<bits/stdc++.h>
using namespace std;


const int MAXN = 2e5 + 5;
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
    for (int i = 0 ; i < n - 1 ; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,1);
    for(int i = 1 ; i <= 19 ; i++){
        for (int j = 1 ; j <= n ; j++){
            pa[j][i] = pa[pa[j][i-1]][i-1];
        }
    }
    int x, y;
    cin >> x >> y;
    int L = lca(x, y) // lca
    int D = dis(x, y) // dis
    int pa = getpa(x, y) // x's y time parent
}  
