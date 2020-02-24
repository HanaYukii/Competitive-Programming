
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<cstdlib>
#include<stack>
using namespace std;
 
#define inf 0x3f3f3f3f
#define eps 1e-7
#define LL long long
#define ULL unsigned long long
#define MP make_pair
#define pb push_back
#define ls ( i << 1 )
#define rs ( ls | 1 )
#define md ( ( ll[i] + rr[i] ) >> 1 )
#define mxn 400010
#define mod 1000000007
#define PI acos( -1.0 )
string s;
int lz[400005];
struct mat {
    LL a[2][2];
    mat() {
        memset( a, 0, sizeof( a ) );
    }
    mat( LL x ) {
        a[0][0] = a[1][0] = 1;
        a[1][1] = 0;
        a[0][1] = x;
    }
    mat operator * ( const mat &b ) const {
        mat ret;
        for( int i = 0; i < 2; ++i )
            for( int j = 0; j < 2; ++j )
                for( int k = 0; k < 2; ++k )
                    ret.a[i][j] = ( ret.a[i][j] + a[i][k] * b.a[k][j] ) % mod;
        return ret;
    }
};
mat sum[mxn];
void pull(int x) {
    sum[x] = sum[x<<1|1] * sum[x<<1];
}
void Swap(int x) {
    swap(sum[x].a[0][0],sum[x].a[1][1]);
    swap(sum[x].a[1][0],sum[x].a[0][1]);
    lz[x]^=1;
}
void push(int x) {
    if(!lz[x])return;
    Swap(x<<1);
    Swap(x<<1|1);
    lz[x] = 0;
}
void build( int x, int l, int r ) {
    if(l == r) {
        if(s[l-1] == 'A') {
            sum[x].a[0][0] = 1, sum[x].a[0][1] = 1;
            sum[x].a[1][0] = 0, sum[x].a[1][1] = 1;
        }
        else {
            sum[x].a[0][0] = 1, sum[x].a[0][1] = 0;
            sum[x].a[1][0] = 1, sum[x].a[1][1] = 1;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pull(x);
}
mat query( int x, int l, int r, int ql,int qr ) {
    if(ql <= l && qr >= r) {
        return sum[x];
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
        return query(x<<1|1,mid+1,r,ql,qr) * query(x<<1,l,mid,ql,qr);
    }
}
void update(int x,int l,int r,int ql,int qr) {
    if(ql <= l && qr >= r) {
        Swap(x);
        return;
    }
    push(x);
    int mid = (l + r) >> 1;
    if(ql <= mid) {
        update(x<<1,l,mid,ql,qr);
    }
    if(qr > mid) {
        update(x<<1|1,mid+1,r,ql,qr);
    }
    pull(x);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
        cin >> n >> m;
        cin >> s;
        build(1,1,n);
        while( m -- ) {
            int tp;
            cin >> tp;
            if(tp == 1) {
                int L, R;
                cin >> L >> R;
                update(1,1,n,L,R);
                continue;
            }
            LL a, b, l, rr;
            cin >> l >> rr >> a >> b;
            mat r = query(1,1,n,l, rr);
            cout << (a * r.a[0][0] + b * r.a[0][1]) % mod <<' '<<(a * r.a[1][0] + b * r.a[1][1]) % mod<<'\n';
        }
    
}
