#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  s[0] = tolower(s[0]);
  s = "Of" + s;
  cout << s << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  while (t--) {
    solve();
  }
  
}
