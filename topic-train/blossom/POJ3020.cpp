#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 405
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second 
int h,w,idx;
int mp[maxn][maxn];
int e[maxn][maxn];
int match[maxn];
vector<int>g[maxn];
int Q[maxn],rear;
int nxt[maxn],mark[maxn],vis[maxn],fa[maxn];
void init(){
    memset(e,0,sizeof(e));
    for(int i=0;i<maxn;i++){
        g[i].clear();
    }
}
int getFa(int x){
    return fa[x]==x? x: fa[x]=getFa(fa[x]);
}
void merge(int a,int b){
    a = getFa(a);
    b = getFa(b);
    fa[a] = b;
}
void add_edge(int x,int y){
    if(e[x][y])return;
    e[x][y]=e[y][x]=1;
    g[x].push_back(y);
    g[y].push_back(x);
}
int LCA (int x,int y){
    static int t = 0;t++;
    while(1){
        if(x!=-1){
            x = getFa(x);
            if(vis[x]==t)return x;
            vis[x] = t;
            if(match[x] != -1)x = nxt[match[x]];
            else x = -1;
        }
        swap(x,y);
    }
}
void group(int a,int p){
    while(a != p){
        int b = match[a], c = nxt[b];
        if(getFa(c) != p)nxt[c] = b;
        if(mark[b] == 2) mark[Q[rear++] = b] = 1;
        if(mark[c] == 2) mark[Q[rear++] = c] = 1;
        merge(a,b);
        merge(b,c);
        a = c;
    }
}
void aug(int s){
    for(int i=0;i<idx;i++){
        nxt[i] = -1, fa[i] = i;
        mark[i] = 0,  vis[i] = -1;
    }
    mark[s] = 1;
    Q[0] = s;rear = 1;
    for(int front = 0;match[s] == -1 && front < rear ; front++){
        int x = Q[front];
        for(int i = 0 ; i < g[x].size() ; i++){
            int y = g[x][i];
            if(match[x]==y)continue;
            if(getFa(x) == getFa(y))continue;
            if(mark[y] == 2)continue;
            if(mark[y] == 1){
                int r = LCA(x,y);
                if(getFa(x) != r)nxt[x] = y;
                if(getFa(y) != r)nxt[y] = x;
                group(x, r);
                group(y, r);
            }
            else if(match[y] == -1){
                nxt[y] = x;
                for(int u = y; u != -1; ){
                    int v = nxt[u];
                    int mv = match[v];
                    match[v] = u;
                    match[u] = v;
                    u = mv;
                }
                break;
            }
            else{
                nxt[y] = x;
                mark[Q[rear++] = match[y]] = 1;
                mark[y] = 2;
            }
        }
    }
}
int blossom(){
    int ret = 0;
    memset(match,-1,sizeof(match));
    for(int i=0;i<idx;i++){
        if(match[i]==-1)aug(i);
    }
    for(int i=0;i<idx;i++){
        if(match[i]!=-1)ret++;
    }
    return ret;
}
int main(){
    int t;
    cin >> t;
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    while(t--){
        init();
        cin >> h >> w;
        string s[h+5];
        for(int i=0;i<h;i++){
            cin >> s[i];
        }
        idx = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(s[i][j]=='*'){
                    mp[i][j]=idx++;
                }
                else{
                    mp[i][j]=-1;
                }
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(mp[i][j]==-1)continue;
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx<0||nx>=h||ny<0||ny>=w)continue;
                    if(mp[nx][ny]==-1)continue;
                    add_edge(mp[i][j],mp[nx][ny]);
                }
            }
        }
        int match = blossom();
        cout << idx - match / 2 << endl;
    }
}
