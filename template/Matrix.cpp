struct mat {
    ll a[6][6];
    mat() {
        memset(a, 0, sizeof(a));
    }
    mat operator * ( const mat &b ) const {
        mat ret;
        for( int i = 0; i < 6; ++i )
            for( int j = 0; j < 6; ++j )
                for( int k = 0; k < 6; ++k )
                    ret.a[i][j] = ( ret.a[i][j] + a[i][k] * b.a[k][j] ) % mod;
        return ret;
    }
};
void solve() {
    ll n;
    mat ans, now;
    cin >> n;
    f(5) {
        now.a[i][i + 1] = 1;
    }
    f(6) {
        now.a[5][i] = 1;
    }
    ans.a[5][0] = 1;
    while (n) {
        if (n & 1) {
            ans = now * ans;
        }
        now = now * now;
        n >>= 1;
    }
    cout << ans.a[5][0] << '\n';
}
