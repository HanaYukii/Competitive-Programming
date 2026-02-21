#include<bits/stdc++.h>
using namespace std;

using pll = pair<long long,long long>;
using pii = pair<int,int>;
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;

struct mat {
    long long a[2][2];
    mat() {
        memset( a, 0, sizeof( a ) );
    }
    mat operator * ( const mat &b ) const {
        mat ret;
        for( int i = 0; i < 2; ++i )
            for( int j = 0; j < 2; ++j )
                for( int k = 0; k < 2; ++k )
                    ret.a[i][j] = ( ret.a[i][j] + a[i][k] * b.a[k][j] ) % mod;
        return ret;
    }
    mat operator + ( const mat &b ) const {
        mat ret;
        for( int i = 0; i < 2; ++i )
            for( int j = 0; j < 2; ++j )
                ret.a[i][j] = (a[i][j] + b.a[i][j] ) % mod;
        return ret;
    }
}sum[MAXN<<2], lz[MAXN<<2];

mat get(int k) {
    mat ret;
    mat sum;
    sum.a[0][0] = 0, sum.a[0][1] = 1;
    sum.a[1][0] = 1, sum.a[1][1] = 1;
    ret.a[0][0] = ret.a[1][1] = 1;
    while (k) {
        if (k & 1) {
            ret = ret * sum;
        }
        sum = sum * sum;
        k >>= 1;
    }
    return ret;
}
void init(int x) {
    lz[x].a[0][0] = 1, lz[x].a[0][1] = 0;
    lz[x].a[1][0] = 0, lz[x].a[1][1] = 1;
}

void pull(int x) {
    sum[x] = sum[x<<1|1] + sum[x<<1];
}
void push(int x) {
    sum[x<<1] = sum[x<<1] * lz[x];
    sum[x<<1|1] = sum[x<<1|1] * lz[x];
    lz[x<<1] = lz[x<<1] * lz[x];
    lz[x<<1|1] = lz[x<<1|1] * lz[x];
    init(x);
}
void build( int x, int l, int r ) {
    init(x);
    if(l == r) {
        sum[x].a[0][0] = 0;
        sum[x].a[0][1] = 1;
        int idx;
        cin >> idx;
        sum[x] = sum[x] * get(idx);
        return;
    }
    int mid = (l + r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pull(x);
}
long long query( int x, int l, int r, int ql,int qr ) {
    if(ql <= l && qr >= r) {
        return sum[x].a[0][0];
    }
    int mid = (l + r) >> 1;
    push(x);
    if(qr <= mid) {
        return query(x<<1,l,mid,ql,qr);
    } 
    else if(ql > mid) {
        return query(x<<1|1,mid+1,r,ql,qr);
    }
    else {
        return (query(x<<1|1,mid+1,r,ql,qr) + query(x<<1,l,mid,ql,qr)) % mod;
    }
}
void update(int x,int l,int r,int ql,int qr, mat m) {
    if(ql <= l && qr >= r) {
        sum[x] = sum[x] * m;
        lz[x] = lz[x] * m;
        return;
    }
    push(x);
    int mid = (l + r) >> 1;
    if(ql <= mid) {
        update(x<<1,l,mid,ql,qr,m);
    }
    if(qr > mid) {
        update(x<<1|1,mid+1,r,ql,qr,m);
    }
    pull(x);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
        cin >> n >> m;
        build(1,1,n);
        while(m --) {
            int tp, l, r;
            cin >> tp >> l >> r;
            if(tp == 1) {
                int k;
                cin >> k;
                mat add = get(k);
                update(1,1,n,l,r,add);
            }
            else {
                cout << query(1,1,n,l,r) << '\n';
            }
        }
    
}
