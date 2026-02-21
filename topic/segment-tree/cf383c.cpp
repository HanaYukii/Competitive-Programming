#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
int L[MAXN],R[MAXN];
vector<int>g[MAXN];
int cur;
int f[MAXN<<2];
int v[MAXN<<2];
int fa[MAXN];
int n;
void dfs(int now,int pre){
    L[now] = R[now]=++cur;
    for(auto i:g[now]){
        if(i==pre)continue;
        fa[i] = now;
        dfs(i,now);
        R[now] = max(R[now],R[i]);
    }
}
void pushup(int x){
    v[x] = v[x<<1] && v[x<<1|1];
}
void pushdown(int x){
    if(f[x]){
        f[x<<1] = 1;
        v[x<<1] = 1;
        f[x<<1|1] = 1;
        v[x<<1|1] = 1;
        f[x] = 0;
    }
}
void update(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r){
        v[x] = f[x] = 1;
        return ;
    }
    pushdown(x);
    int mid = (l+r) >> 1;
    if(ql<=mid)
        update(x<<1,l,mid,ql,qr);
    if(qr>mid)
        update(x<<1|1,mid+1,r,ql,qr);
    pushup(x);
}
void update2(int x,int l,int r,int pos){
    if(l==r){
        v[x] = 0;
        return;
    }
    pushdown(x);
    int mid = (l+r) >> 1;
    if(pos <= mid){
        update2(x<<1,l,mid,pos);
    }
    else{
        update2(x<<1|1,mid+1,r,pos);
    }
    pushup(x);
}
int query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r){
        return v[x];
    }
    int mid = (l+r) >> 1;
    int ret = 1;
    pushdown(x);
    if(ql<=mid){
        ret =  ret && query(x<<1,l,mid,ql,qr);
    }
    if(qr>mid){
        ret = ret && query(x<<1|1,mid+1,r,ql,qr);
    }
    pushup(x);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    while(cin >> n){
        for (int i = 0; i < n-1; i++){
            int add1,add2;
            cin >> add1 >> add2;
            g[add1].push_back(add2);
            g[add2].push_back(add1);
        }
        cur = 0;
        dfs(1,0);
        cin >> m;
        while(m--){
            int op,k;
            cin >> op >> k;
            if(op == 1){
                if(!query(1,1,n,L[k],R[k])&&fa[k])update2(1,1,n,L[fa[k]]);
                update(1,1,n,L[k],R[k]);
            }
            else if(op==2){
                update2(1,1,n,L[k]);
            }
            else{
                cout<<query(1,1,n,L[k],R[k])<<'\n';
            }
        }
    }
}