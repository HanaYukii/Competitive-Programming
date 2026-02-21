// KMP string matching
#include <bits/stdc++.h>
using namespace std;
vector<int>fail;
void build(string s) {
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
}
int match(string s, string t) {
    int p1 = 0, p2 = 0;
    int ans = 0;
    while (p1 < (int)s.size()) {
        if (p2 == -1 || s[p1] == t[p2]) {
            p1++, p2++;
            if (p2 == (int)t.size()) {
                ans++;
                p2 = fail[p2];
            }
        }
        else {
            p2 = fail[p2];
        }
    }
    return ans;
}
void solve() {
    string s, t;
    cin >> s >> t;
    build(t); // build failure
    cout << match(s, t) << '\n'; // t appear time in s
}
