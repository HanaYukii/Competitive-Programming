struct mat {
    ll a[100][100];
    int x;
    mat() {
        memset(a, 0, sizeof(a));
        x = 2;
    }
    mat operator * ( const mat &b ) const {
        mat ret;
        for( int i = 0; i < x; ++i )
            for( int j = 0; j < x; ++j )
                for( int k = 0; k < x; ++k )
                    ret.a[i][j] = (( ret.a[i][j] + a[i][k] * b.a[k][j] ) % mod + mod) % mod;
        return ret;
    }
    mat operator + ( const mat &b ) const {
        //cout << x <<' '<<b.x<<endl;
        mat ret;
        for( int i = 0; i < x; ++i )
            for( int j = 0; j < 1; ++j )
                for( int k = 0; k < x; ++k )
                    ret.a[i][j] = (( ret.a[i][j] + a[i][k] * b.a[k][j] ) % mod + mod) % mod;
        return ret;
    }
};
