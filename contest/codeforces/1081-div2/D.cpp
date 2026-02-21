#include <bits/stdc++.h>
using namespace std;

vector<int> g[200005];
long long sum[200005];
long long w[200005];
long long h[200005];
long long tot[200005];
long long add[200005];
long long ans[200005];

void dfs(int x, int p) {
  sum[x] = w[x];
  h[x] = 0;
  tot[x] = 0;
  add[x] = 0;
  long long mx = -1, smx = -1;
  for (int y : g[x]) {
    if (y == p) {
        continue;
    }
    dfs(y, x);
    sum[x] += sum[y];
    tot[x] += tot[y] + sum[y];
    add[x] = max(add[x], add[y]);
    h[x] = max(h[x], h[y] + 1);
    if (h[y] + 1 >= mx) { 
      smx = mx; 
      mx = h[y] + 1;
    }
    else if (h[y] + 1 > smx) {
      smx = h[y] + 1;
    }
  }
  for (int y : g[x]) {
    if (y == p) {
      continue;
    }
    long long level = 0;
    if (h[y] + 1 == mx) {
      level = smx;
    }
    else {
      level = mx;
    }
    add[x] = max(add[x], level * sum[y]);
  }
  ans[x] = tot[x] + add[x];
}

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++){
    cout << ans[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
