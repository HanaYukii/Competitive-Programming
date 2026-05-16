// Matrix exponentiation (square matrix, modular)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;  // change to 998244353 if needed

struct mat {
    int n;
    vector<vector<ll>> a;
    mat(int n) : n(n), a(n, vector<ll>(n, 0)) {}

    static mat I(int n) {
        mat r(n);
        for (int i = 0; i < n; i++) r.a[i][i] = 1;
        return r;
    }

    mat operator*(const mat& b) const {
        mat r(n);
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (!a[i][k]) continue;
                ll aik = a[i][k];
                for (int j = 0; j < n; j++) {
                    r.a[i][j] = (r.a[i][j] + aik * b.a[k][j]) % mod;
                }
            }
        }
        return r;
    }

    mat operator+(const mat& b) const {
        mat r(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) r.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
        return r;
    }

    mat pow(ll p) const {
        mat r = I(n), base = *this;
        while (p) {
            if (p & 1) r = r * base;
            base = base * base;
            p >>= 1;
        }
        return r;
    }
};

int main() {
    // Fibonacci: F(1) = F(2) = 1
    // M = [[1, 1],
    //      [1, 0]]
    // M^(n-1)[0][0] = F(n) for n >= 1
    ll n;
    while (cin >> n) {
        mat M(2);
        M.a[0][0] = M.a[0][1] = M.a[1][0] = 1;
        cout << M.pow(n - 1).a[0][0] << '\n';
    }
}
