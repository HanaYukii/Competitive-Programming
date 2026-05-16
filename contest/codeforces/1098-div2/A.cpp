#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x % 3]++;
    }
    cout << mp[0] + min(mp[1], mp[2]) + (max(mp[1], mp[2]) - min(mp[1], mp[2])) / 3 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
