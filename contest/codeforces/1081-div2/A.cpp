#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      string r = s.substr(i) + s.substr(0, i);
      int cnt = 1;
      for (int j = 1; j < n; j++)
        if (r[j] != r[j - 1]) cnt++;
      ans = max(ans, cnt);
    }
    cout << ans << '\n';
  }
}
