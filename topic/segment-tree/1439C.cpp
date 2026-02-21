#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int MAXN = 200005;

long long lz[MAXN<<2];
long long sum[MAXN<<2];
long long mi[MAXN<<2];
void pushup(int x) {
    sum[x] = sum[x<<1] + sum[x<<1|1];
    mi[x] = min(mi[x<<1],mi[x<<1|1]);
}
void pushdown(int x,int l,int r,int mid) {
    if (lz[x]) {
        mi[x<<1] = mi[x<<1|1] = mi[x];
        sum[x<<1] = 1LL * mi[x] * (mid - l + 1);
        sum[x<<1|1] = 1LL * mi[x] * (r - mid);
        lz[x<<1] = lz[x<<1|1] = lz[x];
        lz[x] = 0;
    }
}
void build(int x, int l, int r) {
    if (l == r) {
        cin >> sum[x];
        mi[x] = sum[x];
        return;
    }
    int mid = (l + r) >> 1;
    build(x<<1, l, mid);
    build(x<<1|1, mid + 1, r);
    pushup(x);
}
void update(int x, int l, int r,int ql, int qr, int val) {
    if (ql > qr)return;
    if (ql <= l && qr >= r) {
        lz[x] = val;
        sum[x] = 1LL * (r - l + 1) * val;
        mi[x] = val;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(x,l,r,mid);
    if (ql <= mid) {
        update(x<<1, l, mid, ql, qr, val);
    }
    if (qr > mid) {
        update(x<<1|1, mid + 1, r, ql, qr, val);
    }
    pushup(x);
}
long long query(int x, int l, int r, int ql, int qr,int &val) {
    if (mi[x] > val) {
        return 0;
    }
    if (ql <= l && qr >= r && sum[x] <= val) {
        val -= sum[x];
        return r - l + 1;
    }
    int mid = (l + r) >> 1;
    pushdown(x,l,r,mid);
    if (qr <= mid) {
        return query(x<<1,l,mid,ql,qr,val);
    }
    else if (ql > mid) {
        return query(x<<1|1,mid+1,r,ql,qr,val);
    }
    else {
        return query(x<<1,l, mid,ql,qr,val) + query(x<<1|1,mid+1,r,ql,qr,val);
    }
}
int query2(int x, int l, int r, int qr,int val) {
    if (mi[x] >= val) {
        return -1;
    }
    if (l == r) {
        return l;
    }
    int mid = (l + r) >> 1;
    int ret = query2(x<<1,l,mid,qr,val);
    if (~ret) {
        return ret;
    }
    if (qr > mid) {
        return query2(x<<1|1,mid+1,r,qr,val);
    }
    return ret;
}
void go() {
    int n, q;
    cin >> n >> q;
    build(1,1,n);
    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            int x = query2(1,1,n,a,b);
            if (~x)
                update(1,1,n,x,a,b);
        }
        else {
            cout << query(1,1,n,a,n,b) << '\n';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
    
}
