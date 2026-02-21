#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 0; i < n; i++) {
    pq.push({i, a[i]});
    int need = b[i];
    while (need > 0) {
      auto [idx, val] = pq.top();
      pq.pop();
      int take = min(need, val);
      need -= take;
      val -= take;
      if (val > 0) {
        pq.push({idx, val});
      }
    }
    while (!pq.empty() && pq.top().first <= i - d) {
      pq.pop();
    }
  }
  long long ans = 0;
  while (!pq.empty()) {
    ans += pq.top().second;
    pq.pop();
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  
}
