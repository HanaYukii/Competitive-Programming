#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<long long> deg(n, 0);
    for (int i = 1 ; i < n ; i++) {
        string s; cin >> s;
        for (int j = 0 ; j < i ; j++) {
            if (s[j] == '0')
                deg[i]++;
            else
                deg[j]++;
        }
    }
    sort(deg.begin(), deg.end());
    long long ans = 0, sum = 0;
    for (int i = 0 ; i < n ; i++) {
        sum += deg[i];
        ans = max(ans, sum - i * (i + 1) / 2);
    }
    cout << ans << '\n';
}