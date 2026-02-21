#include <bits/stdc++.h>
using namespace std;

int m, a, b;
int dp[1005][1005];

int vis[1005][1005];

bool ok(int x, int y) {
  if (x == 0 || y == 0) return false;
  if (dp[x][y] != -1) return dp[x][y];
  if (vis[x][y]) return dp[x][y] = 1;
  vis[x][y] = 1;
  dp[x][y] = ok(y, (1LL * a * y + 1LL * b * x) % m);
  return dp[x][y];
}
void solve() {
  cin >> m >> a >> b;
  int ans = 0;
  memset(dp, -1, sizeof(dp));
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (ok(i, j)) {
        ans++;
      }
    }
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