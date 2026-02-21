#include <bits/stdc++.h>
using namespace std;


void solve() {
  int n;
  cin >> n;
  map<int, int> dp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (dp.find(x - 1) == dp.end()) {
      dp[x] = max(dp[x], 1);
    } else {
      dp[x] = max(dp[x], dp[x - 1] + 1);
    }
  }
  int ans = 0;
  for (auto [x, y] : dp) {
    ans = max(ans, y);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}