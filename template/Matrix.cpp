// Matrix exponentiation
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using ll = long long;
struct mat {
    vector<vector<long long>>a;
    int x;
    mat() {
        a.resize(2,vector<ll>(2,0));
        x = 2;
    }
    mat(int n) {
        a.resize(n,vector<ll>(n,0));
        x = n;
    }
    mat operator * ( const mat &b ) const {
        mat ret(x);
        ret.x = x;
        for( int i = 0; i < x; ++i )
            for( int j = 0; j < x; ++j )
                for( int k = 0; k < x; ++k )
                    ret.a[i][j] = (( ret.a[i][j] + a[i][k] * b.a[k][j] ) % mod + mod) % mod;
        return ret;
    }
    mat operator + ( const mat &b ) const {
        mat ret(x);
        ret.x = x;
        for( int i = 0; i < x; ++i )
            for( int j = 0; j < 1; ++j )
                for( int k = 0; k < x; ++k )
                    ret.a[i][j] = (( ret.a[i][j] + a[i][k] * b.a[k][j] ) % mod + mod) % mod;
        return ret;
    }
};

int main() {
    // Matrix power fib
    //{1,1,2,3,5,8};
    ll n;
    while (cin >> n) {
        mat ans(2);
        mat mul(2);
        ans.a[0][0] = 1; // fib 1
        ans.a[1][0] = 1; // fib 2
        ll left = n - 1;
        mul.a[0][1] = 1;
        mul.a[1][0] = mul.a[1][1] = 1;
        while (left) {
            if (left & 1) {
                ans = mul + ans;
            }
            mul = mul * mul;
            left >>= 1;
        }
        cout << ans.a[0][0] << '\n'; // fib n
    }
}
