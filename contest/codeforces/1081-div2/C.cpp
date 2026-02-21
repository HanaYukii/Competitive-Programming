#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n, h, k;
    cin >> n >> h >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
    }
    vector<long long> pre_sum(n + 1, 0), pre_min(n + 1, 2e9), suf_max(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pre_sum[i + 1] = pre_sum[i] + a[i];
      pre_min[i + 1] = min(pre_min[i], a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
      suf_max[i] = max(suf_max[i + 1], a[i]);
    }

    long long r = max(0LL, (h - 1) / sum);
    long long rem = h - r * sum;

    long long ans = 2e18;
    for (int i = 1; i <= n; i++) {
      long long best = pre_sum[i];
      if (i < n) {
        best += max(0LL, suf_max[i] - pre_min[i]);
      }
      if (best >= rem) {
        ans = i;
        break;
      }
    }
    cout << r * (n + k) + ans << '\n';
  }
}
