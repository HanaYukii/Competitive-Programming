#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long qry(const vector<pair<int,long long>>& cp, int p) {
  int lo = 0, hi = (int)cp.size() - 1, res = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (cp[mid].first <= p) { res = mid; lo = mid + 1; }
    else hi = mid - 1;
  }
  return res >= 0 ? cp[res].second : 0;
}
vector<int> pos[500005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    pos[a[i]].push_back(i);
  }

  struct Block { int p, v, j; };
  vector<Block> blocks;
  for (int v = 1; v <= n; v++)
    if ((int)pos[v].size() >= v)
      for (int j = 0; j + v <= (int)pos[v].size(); j++)
        blocks.push_back({pos[v][j + v - 1], v, j});

  sort(blocks.begin(), blocks.end(), [](const Block& a, const Block& b) {
    return a.p < b.p;
  });

  vector<pair<int,long long>> T_cp = {{-1, 1}};
  vector<vector<pair<int,long long>>> tv_cp(n + 1);
  vector<long long> tv_run(n + 1, 0);
  for (int v = 1; v <= n; v++)
    if ((int)pos[v].size() >= v)
      tv_cp[v] = {{-1, 0}};
  long long T_run = 1, ans = 0;

  for (auto& [bp, v, j] : blocks) {
    int lo_p = (j > 0 ? pos[v][j - 1] : -1);
    int hi_p = pos[v][j] - 1;

    long long s1 = (qry(T_cp, hi_p) - qry(tv_cp[v], hi_p) + MOD) % MOD;
    long long s2 = (qry(T_cp, lo_p - 1) - qry(tv_cp[v], lo_p - 1) + MOD) % MOD;
    long long dp = (s1 - s2 + MOD) % MOD;

    if (dp) {
      ans = (ans + dp) % MOD;
      T_run = (T_run + dp) % MOD;
      tv_run[v] = (tv_run[v] + dp) % MOD;
      T_cp.push_back({bp, T_run});
      tv_cp[v].push_back({bp, tv_run[v]});
    }
  }

  cout << ans << '\n';
}
