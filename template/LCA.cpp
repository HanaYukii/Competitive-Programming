nclude<bits/stdc++.h>
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
#define double long double
const int mod = 1e9+7;

int pa[200005][20];
vector<int>g[200005];
int sz[200005];
int dep[200005];
void dfs(int x){
    sz[x] = 1;
    for(auto i:g[x]){
        dep[i] = dep[x] + 1;
        dfs(i);
        sz[x] += sz[i];
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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    f1(n){
        cin >> pa[i][0];
        g[pa[i][0]].pb(i);
    }
    f1(19){
        fr(j,1,n+1){
            pa[j][i] = pa[pa[j][i-1]][i-1];
        }
    }
    dfs(0);
}  
