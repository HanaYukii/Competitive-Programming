#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL a, b, c; cin >> a >> b >> c;
    if (c % 2) {
        cout << "Take another envelope\n";
    } else {
        if (a <= c && c <= b) {
            cout << "Take another envelope\n";
        } else {
            cout << "Stay with this envelope\n";
        }
    }
}