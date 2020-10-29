#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const ll mod = 1e9 + 7;
const int maxn = 5e5+5;
int sum[maxn<<2];
void pushup(int x) {
    sum[x] = sum[x<<1] + sum[x<<1|1];
}
void build(int x,int l,int r) {
    if (l == r) {
        cin >> sum[x];
        return;
    }
    int mid = (l + r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
void update(int x,int l,int r,int p,int v) {
    if (l == r) {
        sum[x] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) {
        update(x<<1,l,mid,p,v);
    }
    else {
        update(x<<1|1,mid+1,r,p,v);
    }
    pushup(x);
}
int query(int x,int l,int r,int ql,int qr) {
    if (ql <= l && qr >= r) {
        return sum[x];
    }
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        return query(x<<1,l,mid,ql,qr);
    }
    if (ql > mid) {
        return query(x<<1|1,mid+1,r,ql,qr);
    }
    return query(x<<1,l,mid,ql,qr) + query(x<<1|1,mid+1,r,ql,qr);
}
int main() {
	// Segment Tree single modify, Range sum
    int n, m;
    cin >> n >> m;
    build(1,1,n);    
    while(m--) {
        int op;
        cin >> op;
        if (op == 0) {
            int p, k;
            cin >> p >> k;
            update(1,1,n,p,k);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << query(1,1,n,l,r) << '\n';
        }
    }
}