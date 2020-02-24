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
