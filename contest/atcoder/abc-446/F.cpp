#include <bits/stdc++.h>
using namespace std;
vector<int> in[300005], out[300005];
int r[300005];
int low[300005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    low[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    out[x].push_back(y);
    in[y].push_back(x);
    low[y] = min(low[y], x);
  }

  vector<int> diff(n + 2, 0);
  for (int i = 1; i <= n; i++) {
    if (low[i] < i) {
      diff[low[i]]++;
      diff[i]--;
    }
  }
  vector<int> pre(n + 1);
  for (int i = 1; i <= n; i++)
    pre[i] = pre[i - 1] + diff[i];
  r[1] = 1;
  int cnt = 1;
  queue<int> q;
  q.push(1);
  for (int k = 1; k <= n; k++) {
    if (!r[k]) {
      for (int i : in[k]) {
        if (r[i]) {
          r[k] = true;
          cnt++;
          q.push(k);
          break;
        }
      }
    }
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int i : out[x]) {
        if (i <= k && !r[i]) {
          r[i] = true;
          cnt++;
          q.push(i);
        }
      }
    }
    cout << (cnt == k ? pre[k] : -1) << '\n';
  }
}
