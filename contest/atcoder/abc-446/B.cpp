#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<bool>used(m+1, false);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vector<int>a(x);
    for (int j = 0; j < x; j++) {
      cin >> a[j];
    }
    int ans = 0;
    for (int j = 0; j < x; j++) {
      if (!used[a[j]]) {
        ans += a[j];
        used[a[j]] = true;
        break;
      }
    }
    cout << ans << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  while (t--) {
    solve();
  }
  
}
