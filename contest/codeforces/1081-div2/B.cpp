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
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        cnt1++;
      }
      else {
        cnt0++;
      }
    }
    bool c1 = false;
    if (cnt1 % 2 == 0) {
      c1 = true;
    }
    else if (cnt0 % 2 == 1) {
      c1 = false;
    }
    else { 
      cout << -1 << '\n'; 
      continue; 
    }
    vector<int> ans;
    char pick;
    if (c1) {
      pick = '1';
    }
    else {
      pick = '0';
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == pick)  {
        ans.push_back(i + 1);
      }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}
