#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 50005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
vector<int>g[maxn];
int sz[maxn],fa[maxn],son[maxn],dep[maxn];
int idx[maxn],top[maxn],stamp;
int v[maxn],t[maxn];
int val[maxn<<2];
int n;
void init(){
    for(int i = 1 ; i <= n ; i++){
        sz[i] = fa[i] = son[i] = dep[i] = idx[i] = top[i] = v[i] = t[i] = 0;
        stamp = 0;
        g[i].clear();
    }
    for(int i = 1 ; i <= 4*n ; i++){
        val[i] = 0;
    }
}
void pushdown(int x){
    if(!val[x])return;
    val[x<<1] += val[x];
    val[x<<1|1] += val[x];
    val[x] = 0;
}
void build(int x,int l,int r){
	if(l==r){
		val[x] = t[l];
		return ;
	}
	int mid = (l+r) >> 1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
}
void update(int x,int l,int r,int ql,int qr,int v){
    if(ql <= l && qr >= r){
        val[x] += v;
        return;
    }
    pushdown(x);
    int mid = (l + r) >> 1;
    if(ql <= mid)
        update(x<<1,l,mid,ql,qr,v);
    if(qr > mid)
        update(x<<1|1,mid+1,r,ql,qr,v);
}
int query(int x,int l,int r,int pos){
	if(l == r){
		return val[x];
	}
    pushdown(x);
	int mid = (l+r) >> 1;
	if(pos <= mid){
		return query(x<<1,l,mid,pos);
	}
    else{
		return query(x<<1|1,mid+1,r,pos);
	}
}
void dfs1(int now,int pre){
    int mx = 0,idx = 0;
    sz[now] = 1;
    for(auto i:g[now]){
        if(i==pre)continue;
        fa[i] = now;
        dep[i] = dep[now] + 1;
        dfs1(i,now);
        sz[now] += sz[i];
        if(sz[i] > mx){
            mx = sz[i];
            idx = i;
        }
    }
    son[now] = idx;
}
void dfs2(int now,int tp){
    idx[now] = ++stamp;
    top[now] = tp;
    if(!son[now])return;
    dfs2(son[now],tp);
    for(auto i:g[now]){
        if(i==fa[now]||i==son[now])continue;
        dfs2(i,i);
    }
}
void change(int u,int v,int del){
    int top1 = top[u], top2 = top[v];
    while(top1 != top2){
        if(dep[top1] < dep[top2]){
            swap(top1,top2);
            swap(u,v);
        }
        update(1,1,n,idx[top1],idx[u],del);
        u = fa[top1];
        top1 = top[u];
    }
    if(dep[u] > dep[v]){
        swap(u,v);
    }
    update(1,1,n,idx[u],idx[v],del);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int m, q;
    while(cin >> n >> m >> q){
    init();
    f1(n)cin >> v[i];
    f(n-1){
        int add1, add2, add3;
        cin >> add1 >> add2;
        g[add1].pb(add2);
        g[add2].pb(add1);
    }
    dfs1(1,0);
    dfs2(1,1);
    f1(n){
        t[idx[i]] = v[i];
    }
    build(1,1,n);
    //f1(n)cout << idx[i] << endl;
    //f1(n)cout << query(1,1,n,i)<<endl;
    
    while(q--){
        string op;
	    cin >> op;
        if(op[0] == 'Q'){
            int x;
            cin >> x;
            cout << query(1,1,n,idx[x]) << endl;
        }
        else{
            int x,y,z;
            cin >> x >> y >> z;
            if(op[0] == 'D'){
                z = -z;
            }
            change(x,y,z);
        }
    }
    }
}
