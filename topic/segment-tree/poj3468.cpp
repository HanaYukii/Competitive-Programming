#include<iostream>
using namespace std;

const int MAXN = 300005;
long long lz[MAXN<<2];
long long sum[MAXN<<2];
void pushdown(int x,int m){
    if(!lz[x])return ;
    lz[x<<1] += lz[x];
    lz[x<<1|1] += lz[x];
    sum[x<<1] += lz[x] * (m-(m>>1));
    sum[x<<1|1] += lz[x] * (m>>1);
    lz[x] = 0;
}
void pushup(int x){
    sum[x] = sum[x<<1] + sum[x<<1|1];
}
void build(int x,int l,int r){
    if(l==r){
        cin >> sum[x];
        return;
    }
    int mid = (l+r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
void update(int x,int l,int r,int ql,int qr,long long v){
    if(l==ql&&r==qr){
        sum[x] += (r-l+1) * v;
        lz[x] += v;
        return ;
    }
    pushdown(x,r-l+1);
    int mid = (l+r) >> 1;
    if(qr<=mid){
        update(x<<1,l,mid,ql,qr,v);
    }
    else if(ql>mid){
        update(x<<1|1,mid+1,r,ql,qr,v);
    }
    else{
        update(x<<1,l,mid,ql,mid,v);
        update(x<<1|1,mid+1,r,mid+1,qr,v);
    }
    pushup(x);
}
long long query(int x,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
        return sum[x];
    }
    pushdown(x,r-l+1);
    int mid = (l+r) >> 1;
    long long ret = 0;
    if(qr<=mid){
        ret += query(x<<1,l,mid,ql,qr);
    }
    else if(ql>mid){
        ret += query(x<<1|1,mid+1,r,ql,qr);
    }
    else{
        ret += query(x<<1,l,mid,ql,mid);
        ret += query(x<<1|1,mid+1,r,mid+1,qr);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    build(1,1,n);
    while(k--){
        string op;
        cin >> op;
        int l,r;
        cin >> l >> r;
        if(op=="Q"){
            cout<<query(1,1,n,l,r)<<'\n';
        }
        else{
            long long v;
            cin >> v;
            update(1,1,n,l,r,v);
        }
    }
}