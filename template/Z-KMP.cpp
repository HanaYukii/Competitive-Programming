// Z-function (Z-algorithm)
// cses 2107
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 200005;

vector<int> build(string s) {
    vector<int>fail;
    fail.push_back(-1);
    int p1 = 0, p2 = -1;
    while (p1 < (int)s.size()) {
        if (p2 == -1 || s[p1] == s[p2]) {
            p1++, p2++;
            fail.push_back(p2);
        }
        else {
            p2 = fail[p2];
        }
    }
    return fail;
}
vector<int> Z(string &s) { 
    int L = 0, R = 0;
  vector<int> z(s.size()); z[0] = s.size();
  for (int i = 1 ; i < (int)s.size() ; i++) {
    if (i <= R && z[i - L] <= R - i) z[i] = z[i - L];
    else { L = i; if (i > R) R = i;
      while (R < z[0] && s[R - L] == s[R]) R++;
      z[i] = (R--) - L;
    }
  }
  return z;
}
void go() {
   string s;
   cin >> s;
   auto fail = build(s);
   auto z = Z(s);
   z[0] = 0;
   for (auto &i : z) {
        cout << i <<' ';
   }
   cout << endl;
   for (int i = 1 ; i < fail.size() ; i++) {
        cout << fail[i] << ' ';
   }
   cout << endl;
   
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
}
