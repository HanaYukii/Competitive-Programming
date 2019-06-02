#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long c, n; cin >> c >> n;
    long long cnt = 0;
    for (long long i = 0 ; i < n ; i++) {
        long long a, b, x; cin >> a >> b >> x;
        cnt -= a;
        if (cnt < 0) {
            cout << "impossible\n";
            exit(0);
        }
        cnt += b;
        if (cnt > c) {
            cout << "impossible\n";
            exit(0);
        }
        if (cnt < c && x > 0) {
            cout << "impossible\n";
            exit(0);
        }
        if (i == n - 1 && x > 0) {
            cout << "impossible\n";
            exit(0);
        }
    }
    if (cnt == 0)
        cout << "possible\n";
    else
        cout << "impossible\n";
}