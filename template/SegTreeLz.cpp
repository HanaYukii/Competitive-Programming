// Segment Tree with Lazy Propagation
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
const int mod = 1e9+7;
long long lz[MAXN<<2];
long long mx[MAXN<<2];
void pushdown(int x){
    if(!lz[x])return ;
    lz[x<<1] += lz[x];
    lz[x<<1|1] += lz[x];
    mx[x<<1] += lz[x];
    mx[x<<1|1] += lz[x];
    lz[x] = 0;
}
void pushup(int x){
    mx[x] = max(mx[x<<1], mx[x<<1|1]);
}
void build(int x,int l,int r){
    if(l==r){
        //
        return;
    }
    int mid = (l+r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
void update(int x,int l,int r,int ql,int qr,long long v){
    if (ql <= l && qr >= r){
        mx[x] += v;
        lz[x] += v;
        return ;
    }
    pushdown(x);
    int mid = (l+r) >> 1;
    if(ql <= mid){
        update(x<<1, l, mid, ql, qr, v);
    }
    if(qr > mid){
        update(x<<1|1, mid + 1, r, ql, qr, v);
    }
    pushup(x);
}
long long query(int x,int l,int r,int ql,int qr){
    if (ql <= l && qr >= r){
        return mx[x];
    }
    pushdown(x);
    int mid = (l+r) >> 1;
    long long mx = -1e18;
    if(ql <= mid){
        mx = max(mx, query(x<<1,l,mid,ql,qr));
    }
    if(qr > mid){
        mx = max(mx, query(x<<1|1,mid+1,r,ql,qr));
    }
    return mx;
}
int main() {
    // Segment Tree Range add, Range max
}
