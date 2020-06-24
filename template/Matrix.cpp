struct mat {
    ll a[2][2];
    mat() {
        memset(a, 0, sizeof(a));
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
