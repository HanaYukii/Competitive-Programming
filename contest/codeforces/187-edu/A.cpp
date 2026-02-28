#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long x;
    cin >> x;
    long long sum = 0;
    vector<int>d;
    int flag = 0;
    while(x) {
        int md = x % 10;
        d.push_back(md);
        sum += md;
        x /= 10;
    }
    d.back()--;
    sort(d.begin(), d.end());

    int ans = 0;
    while (sum > 9) {
        ans++;
        sum -= d.back();
        d.pop_back();
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
