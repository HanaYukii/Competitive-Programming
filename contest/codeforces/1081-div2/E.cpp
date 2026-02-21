#include <bits/stdc++.h>
using namespace std;

int a[1000005], b[1000005];
bool used[1000005];
int dir[1000005];
vector<int>u;
vector<pair<int,int>> g[1000005];

void dfs(int x) {
  while (!g[x].empty()) {
    auto [y, idx] = g[x].back();
    g[x].pop_back();
    if (used[idx]) continue;
    used[idx] = true;
    if (x == u[idx-1]) {
      dir[idx] = 1;
    }
    dfs(y);
  }
}

void solve() {
  int n;
  cin >> n;
  u.clear();
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    used[i] = 0;
    dir[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  vector<int> cnt(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i]) {
      continue;
    }
    cnt[a[i]]++;
    cnt[b[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] % 2) {
      cout << -1 << '\n';
      return;
    }
  }
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i]) {
      continue;
    }
    u.push_back(a[i]);
    g[a[i]].push_back({b[i], ++tot});
    g[b[i]].push_back({a[i], tot});
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].size()) {
      dfs(i);
    }
  }
  vector<int> ans;
  tot = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i]) {
      continue;
    }
    if (dir[++tot] == 1) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << '\n';
  for (auto &i: ans) {
    cout << i << " ";
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
